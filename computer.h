#ifndef _COMPUTER_H
#define _COMPUTER_H

#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QObject>
#include <QDebug>
#include <QStack>
#include <QVector>
#include <QException>
#include <qstring.h>
#include <QMap>
#include "operande.h"

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
    virtual double getRNumerateur() const {return 0;}
    virtual double getRDenominateur() const {return 1;}
    virtual double getINumerateur() const {return 0;}
    virtual double getIDenominateur() const {return 1;}
    virtual bool isNull()const =0;
    Litterale(){}
    virtual ~Litterale(){}


};

class LitteraleNum : public Litterale{

    LitteraleNum(const Litterale& e);
    LitteraleNum& operator=(const LitteraleNum& e);
    friend class LitteraleManager;
public:
    LitteraleNum(){}
    virtual QString afficher()=0;

    virtual bool isNull() const =0;
    virtual ~LitteraleNum(){}

};

class Entier : public LitteraleNum{
    int  nombre;

public :
    Entier(int a ): nombre(a){}
    QString afficher(){

        return QString::number(nombre);
    }
    bool isNull()const {return nombre==0;}
    ~Entier(){qDebug("On détruit un entier");}

    double getRNumerateur() const {return nombre;}
    double getRDenominateur() const {return 1;}
};

class Rationnel : public LitteraleNum{
    int numerateur;
    int denominateur;
public:
    void simplification(){

                if (numerateur==0) { denominateur=1; return; }
                if (denominateur==0) return;
                int a=numerateur, b=denominateur;
                if (a<0) a=-a; if (b<0) b=-b;
                while(a!=b){ if (a>b) a=a-b; else b=b-a; }
                numerateur/=a; denominateur/=a;
                if (denominateur<0) { denominateur=-denominateur; numerateur=-numerateur; }

    }
    void setRationnel(int n, int d){

        numerateur=n;
        denominateur=d;

        simplification();

    }
    Rationnel(int n, int d){

        setRationnel(n,d);
    }


     QString afficher(){
    return QString::number(numerateur)+"/"+QString::number(denominateur);
    }

    bool isNull() const {return numerateur==0;}
    bool isNotRationnel(){return denominateur==1;}

    double getRNumerateur() const {return numerateur;}
    double getRDenominateur() const {return denominateur;}


};

class Reel : public LitteraleNum {
    double nombre;
public :
    QString afficher(){
    return QString::number(nombre);
    }
    Reel(double d):nombre(d){}
    bool isNull() const {return nombre==0;}
    double getRNumerateur() const {return nombre;}
    double getRDenominateur() const {return 1;}




};

class Complexe : public Litterale{
    LitteraleNum& reel;
    LitteraleNum& imaginaire;
public:
    QString afficher(){

    return reel.afficher()+"$"+imaginaire.afficher();
    }
    Complexe(LitteraleNum& a,LitteraleNum& b): reel(a),imaginaire(b){}
    bool isNull() const {return (reel.isNull())&&(imaginaire.isNull());}

    double getRNumerateur() const {return reel.getRNumerateur();}
    double getRDenominateur() const {return reel.getRDenominateur();}
    double getINumerateur() const {return imaginaire.getRNumerateur();}
    double getIDenominateur() const {return imaginaire.getRDenominateur();}
};

class Atome : public Litterale{
    QString atome;
public:
    Atome(QString a): atome(a){}
    bool isNull() const{return atome.isEmpty();}
    QString afficher(){return atome;}
    ~Atome(){}
};

class Expression : public Litterale{
    QString expression;
public:
    Expression(const QString& s): expression(s){}
    QString afficher(){
    return expression;
    }
    bool isNull() const {return expression.isEmpty();}
    ~Expression(){}


};






class Programme : public Litterale{
    QString programme;
public:
    Programme(QString s): programme(s){}
    QString afficher(){
    return programme;
    }
    bool isNull() const {return programme.isEmpty();}
};

class LitteraleManager : public QObject {
    Q_OBJECT


    unsigned int nb;
public:
    LitteraleManager():nb(0){}
    ~LitteraleManager();

    Litterale* addLitterale(const QString& v);
    void removeLitterale(Litterale* e);
    unsigned int getNbLiterrale(){return nb;}
    static LitteraleManager& getInstance();
    static void libererInstance();
signals :
    void erreurDivZero();




};

class Pile : public QObject {
    Q_OBJECT



    QString message;
    unsigned int nb;
    unsigned int nbAffiche;
    friend class LitteraleManager;
    QStack<Litterale*> PileLit;
public:


    Pile():message(""),nb(0),nbAffiche(4){
        PileLit.clear();

    }
    Pile(const Pile& a):message(a.message),nb(a.nb),nbAffiche(a.nbAffiche),PileLit(a.PileLit){}

    ~Pile();
    Pile& operator=(Pile& a){
        message=a.message;
        nb=a.nb;
        nbAffiche=a.nbAffiche;
        for (unsigned int i=0; i<a.getNbLitterale();i++)
            PileLit[i]=a.PileLit[i];
        return *this;
    }
    void push(Litterale* e);
    void pop();
    bool estVide() const { return PileLit.isEmpty(); }

    void affiche(QTextStream& f) const;
    Litterale* top() const;
    void setNbLitteraleToAffiche(unsigned int n) { nbAffiche=n; }
    unsigned int getNbLitteraleToAffiche() const { return nbAffiche; }
    void setMessage(const QString& m) { message=m; modificationEtat(); }
    QString getMessage() const { return message; }
    unsigned int getNbLitterale(){return nb;}

    class iterator{
    QStack<Litterale*> current;
    unsigned int index;
    friend class Pile;
    public:
    iterator(QStack<Litterale*> p, unsigned int a):current(p),index(a){}
    Litterale* operator*(){return current[index];}
    bool operator!=(Pile::iterator a){return index!=a.index;}
    iterator operator++(){index++; return *this;}
    };

    Pile::iterator begin(){return iterator(PileLit,0);}
    Pile::iterator end(){return iterator(PileLit,nb);}

signals:
    void modificationEtat();
public slots:
    void afficheDivZero(){setMessage("Impossible il y a une division par zéro");}

};

class Memento{
    friend class Pile;
    QVector<Pile*> etatsPasse;
    QVector<Pile*> etatsS;
public:
    Memento(Pile* P){
        etatsPasse.push_front(P);
    }
    Memento():etatsPasse(0), etatsS(0){}
    Pile& getMemento(){return *etatsPasse.front();}
    int getNbMemento(){return etatsPasse.count();}
    int getNbFutur(){return etatsS.count();}
    void clearFutur(){etatsS.clear();}
    Pile* getMementoAvant(){
        Pile* a;
        pushFutur(etatsPasse.front());
        etatsPasse.pop_front();
        a=etatsPasse.front();
        etatsPasse.pop_front();
        return a;
    }
    void pushMemento(Pile* p){etatsPasse.push_front(p);}
    void pushFutur(Pile* p){etatsS.push_front(p);}

    Pile* getMementoApres(){
        Pile* a;
        a=etatsS.front();

        etatsS.pop_front();
        return a;
    }

};

class Controleur : public QObject{
    Q_OBJECT

    LitteraleManager& LitMng;
    Pile& LitAff;
    Memento memento;
    QMap<QString,operande*> faire;
    QMap<Atome*,Litterale*> variable;
    QString lastoperande;

    Controleur(LitteraleManager& m, Pile& v):LitMng(m), LitAff(v){
        pushMemento();
        connect(&LitMng,SIGNAL(erreurDivZero()),&LitAff,SLOT(afficheDivZero()));
        initialisationMap();


    }

    struct Handler1{
        Controleur* instance;
        Handler1():instance(nullptr){}
        // destructeur appelé à la fin du programme
        ~Handler1(){ delete instance; }
    };
    static Handler1 handler;
    ~Controleur(){}


    Controleur(const Controleur& m);
    Controleur& operator=(const Controleur& m);
public:
    void initialisationMap();
    static Controleur& getInstance(LitteraleManager& Mng,Pile& stack);
    static Controleur& getInstance();
    static void libererInstance();

    unsigned int getNbLitterale(){
        return LitAff.getNbLitterale();
    }
    bool faitpartiedeMap(const QString s){return faire.contains(s);}
    void push(Litterale* e){ LitAff.push(e);}
    Litterale* top(){ return LitAff.top();}
    void pop(){LitAff.pop();}
    void setMessage(const QString& s) const {LitAff.setMessage(s);}
    QString getLastOperande(){return lastoperande;}
    Litterale* addLitterale(QString e){return LitMng.addLitterale(e);}
    void removeLitterale(Litterale* e){LitMng.removeLitterale(e);}
    void commande(const QString& c);
    void setPile(Pile& P){LitAff=P; modificationEtat();}

    // partie memento

    Pile* getMementoAvant(){return memento.getMementoAvant();}
    Pile* getMementoApres(){return memento.getMementoApres();}
    void pushMemento(){memento.pushMemento(new Pile(LitAff)); qDebug("On a sauvegardé la pile");}
    int getNbMemento(){return memento.getNbMemento();}
    int getNbFutur(){return memento.getNbFutur();}
    void clearFutur(){memento.clearFutur();}


    void commandeEx(const QString &c);
    void commandeP(const QString &c);

    // partie création de variables

    void creationVariable(Atome* a,Litterale* l){
        variable[a]=l;
        setMessage(l->afficher()+" stocké dans "+a->afficher());
    }
    unsigned int getNbVariable(){return variable.size();}
    QMap<Atome*,Litterale*> getVar()const{return variable;}

signals:
    void modificationEtat();
public slots :
    //void slotOperator(); // à définir


};

bool estUnLitteraleNum(const QString s);
bool estUnEntier(const QString s);
bool estUnRationnel(const QString s);
bool estUnReel(const QString s);
bool estUnComplexe(const QString s);
bool estUnAtome(const QString s);
bool estUneExpression(const QString s);
bool estUnProgramme(const QString s);
bool isOperator(const QString s);
QString parseExpression(const QString& s);
bool isHigher(QString a, QString b);
int order(QString op);
bool isChar(QChar a);
bool isPartOperand(QChar a, QString s, int i);
#endif

