#ifndef _COMPUTER_H
#define _COMPUTER_H

#include <QString>
#include <QTextStream>
#include <QObject>
#include <QDebug>
#include <QStack>
#include <QVector>

using namespace std;

class ComputerException {
    QString info;
public:
    ComputerException(const QString& str):info(str){}
    QString getInfo() const { return info; }
};

class Litterale {


    Litterale(const Expression& e);
    Litterale& operator=(const Expression& e);
    friend class LitteraleManager;
public:
    virtual void afficher(std::ostream& f=std::cout)=0
    virtual bool isNull()const =0
};

class Entier : public Litterale{
    int  nombre;

public :
    Entier(int a ): nombre(a){}
    void afficher(std::ostream& f=std::cout){
        // faire la fonction
    }
    bool isNull()const {return nombre==0;}


};

class Rationnel : public Litterale{
    int numerateur;
    int denominateur;
public:
    Rationnel(int n, int d){
        setRationnel(n,d);
    }

    void setRationnel(int n, int d){
        numerateur=n;
        if (d!=0) denominateur=d;
        else throw ComputerException("Division par zéro");
        simplification();

    }
    void afficher(std::ostream& f=std::cout){
    // faire la fonction
    }
    void simplification(){

                if (numerateur==0) { denominateur=1; return; }
                if (denominateur==0) return;
                int a=numerateur, b=denominateur;
                if (a<0) a=-a; if (b<0) b=-b;
                while(a!=b){ if (a>b) a=a-b; else b=b-a; }
                numerateur/=a; denominateur/=a;
                if (denominateur<0) { denominateur=-denominateur; numerateur=-numerateur; }

    }
    bool isNull() const {return numerateur==0;}

};


class Reel : public Litterale {
    double nombre;
public :
    void afficher(std::ostream& f=std::cout){
    // faire la fonction penser au .
    }
    Reel(double d):nombre(d){}
    bool isNull() const {return nombre==0;}



};

template<class T, class P>
class Complexe : public Litterale{
    T reel;
    P imaginaire;
public:
    void afficher(std::ostream& f=std::cout){
    // faire la fonction penser au $
    }
    Complexe( T a, P b):reel(a),imaginaire(b){}
    bool isNull() const {return (reel==0)&&(imaginaire==0);}

};

class Atome : public Litterale
{
    QString atome;
public:
    Atome(QString a) {
        if ((a[0]>='A')&&(a[0]<='Z'))
        {
            atome=a;
        }
        else throw ComputerException("Nom d'atome impossible, commencez par une majuscule pls");
    }
};
class Expression : public Litterale{
    QString expression;
public:
    Expression(Qstring s): expression(s){}

};

class Programme : public Litterale{

};



class LitteraleManager {
    QVector<Litterale*> lit;
    unsigned int nb;


    LitteraleManager():exps(nullptr),nb(0),nbMax(0){}
    ~LitteraleManager();
    LitteraleManager(const LitteraleManager& m);
    LitteraleManager& operator=(const LitteraleManager& m);

    struct Handler{
        LitteraleManager* instance;
        Handler():instance(nullptr){}
        // destructeur appelé à la fin du programme
        ~Handler(){ delete instance; }
    };
    static Handler handler;
public:
    Litterale& addLitterale(Litterale v);
    void removeLitterale(Litterale& e);
    static LitteraleManager& getInstance();
    static void libererInstance();

    class iterator {
        QVector<Litterale*> current;
        iterator(Litterale* u):current(u){}
        friend class LitteraleManager;
    public:
        iterator():current(0){}
        Litterale& operator*() const { return **current; }
        bool operator!=(iterator it) const { return current!=it.current; }
        iterator& operator++(){ ++current; return *this; }
    };
    iterator begin() { return iterator(lit.begin()); }
    iterator end() { return iterator(lit.end()); }
};




class Pile : public QObject {
    Q_OBJECT

    QStack<Litterale*> PileLit;
    unsigned int nb;
    QString message;

    unsigned int nbAffiche;
public:
    Pile():PileLit(nullptr),nb(0),message(""),nbAffiche(4){}
    ~Pile();
    void push(Litterale& e);
    void pop();
    bool estVide() const { return nb==0; }
    unsigned int taille() const { return nb; }
    void affiche(QTextStream& f) const;
    Litterale& top() const;
    void setNbLitteraleToAffiche(unsigned int n) { nb=n; }
    unsigned int getNbLitteraleToAffiche() const { return nbAffiche; }
    void setMessage(const QString& m) { message=m; modificationEtat(); }
    QString getMessage() const { return message; }

    class iterator {
        std::deque<Litterale*> current;
        iterator(Litterale* u):current(u){}
        friend class LitteraleManager;
    public:
        iterator():current(0){}
        Litterale& operator*() const { return **current; }
        bool operator!=(iterator it) const { return current!=it.current; }
        iterator& operator++(){ ++current; return *this; }
    };
    iterator begin() { return iterator(PileLit.begin()); }
    iterator end() { return iterator(PileLit.end()); }

signals:
    void modificationEtat();
};

class Controleur {
    LitteraleManager& LitMng;
    Pile& LitAff;
public:
    Controleur(LitteraleManager& m, Pile& v):LitMng(m), LitAff(v){}
    void commande(const QString& c);

};

bool estUnOperateur(const QString s);
bool estUnLitterale(const QString s);
bool estUnEntier(const QString s);
bool estUnRationnel(const QString s);
bool estUnReel(const QString s);
bool estUnComplexe(const QString s);
bool estUnAtome(const QString s);
bool estUnProgramme(const QString s);
#endif
