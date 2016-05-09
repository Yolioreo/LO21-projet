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


    Litterale(const Litterale& e);
    Litterale& operator=(const Litterale& e);
    friend class LitteraleManager;

public:
    virtual QString afficher()=0;
    virtual bool isNull()const =0;
    Litterale(){}

};

class Entier : public Litterale{
    int  nombre;

public :
    Entier(int a ): nombre(a){}
    QString afficher(){
        // faire la fonction
        QString temp="";
        temp=temp+nombre ;
        return temp;
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
     QString afficher(){
    return numerateur+"/"+denominateur;
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
    bool isNotRationnel(){return denominateur==1;}
};


class Reel : public Litterale {
    double nombre;
public :
    QString afficher(){
    return QString::number(nombre);
    }
    Reel(double d):nombre(d){}
    bool isNull() const {return nombre==0;}



};

template<class T, class P>
class Complexe : public Litterale{
    T reel;
    P imaginaire;
public:
    QString afficher(){
    return reel.afficher()+"$"+imaginaire.afficher();
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
    QString afficher(){
    return atome;
    }
};
class Expression : public Litterale{
    QString expression;
public:
    Expression(QString s): expression(s){}
    QString afficher(){
    return expression;
    }
};

class Programme : public Litterale{

};



class LitteraleManager {
    QVector<Litterale*> lit;



    LitteraleManager(){ lit.clear();}
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
    Litterale* addLitterale(const QString& v);
    void removeLitterale(Litterale* e);
    unsigned int getNbLiterrale(){return lit.count();}
    static LitteraleManager& getInstance();
    static void libererInstance();

};




class Pile : public QObject {
    Q_OBJECT



    QString message;

    unsigned int nbAffiche;
public:
    QStack<Litterale*> PileLit;

    Pile():message(""),nbAffiche(4){PileLit.clear(); }
    ~Pile();
    void push(Litterale& e);
    void pop();
    bool estVide() const { return PileLit.isEmpty(); }

    void affiche(QTextStream& f) const;
    Litterale& top() const;
    void setNbLitteraleToAffiche(unsigned int n) { nbAffiche=n; }
    unsigned int getNbLitteraleToAffiche() const { return nbAffiche; }
    void setMessage(const QString& m) { message=m; modificationEtat(); }
    QString getMessage() const { return message; }
    unsigned int getNbLitterale(){return PileLit.count();}

signals:
    void modificationEtat();
};

class Controleur {
    LitteraleManager& LitMng;
    Pile& LitAff;
public:
    Controleur(LitteraleManager& m, Pile& v):LitMng(m), LitAff(v){}
    void commande(const QString& c);

    void commandeEx(const QString &c);
    void commandeP(const QString &c);
};

bool estUnOperateur(const QString s);
bool estUnLitterale(const QString s);
bool estUnEntier(const QString s);
bool estUnRationnel(const QString s);
bool estUnReel(const QString s);
bool estUnComplexe(const QString s);
bool estUnAtome(const QString s);
bool estUnExpression(const QString s);
bool estUnProgramme(const QString s);
#endif
