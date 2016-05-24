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
    QString afficher(){
    return atome;
    }
    bool isNull(){return atome.isEmpty();}

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
public:
    QStack<Litterale*> PileLit;

    Pile():message(""),nb(0),nbAffiche(4){
        PileLit.clear();

    }
    ~Pile();
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

signals:
    void modificationEtat();
public slots:
    void afficheDivZero(){setMessage("Impossible il y a une division par zéro");}

};

class Controleur : public QObject{
    Q_OBJECT

    LitteraleManager& LitMng;
    Pile& LitAff;

    QMap<QString,operande*> faire;

    Controleur(LitteraleManager& m, Pile& v):LitMng(m), LitAff(v){
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

    Litterale* addLitterale(QString& e){return LitMng.addLitterale(e);}
    void removeLitterale(Litterale* e){LitMng.removeLitterale(e);}





    void commande(const QString& c);

    void commandeEx(const QString &c);
    void commandeP(const QString &c);



};
bool estUnOperateurNum(const QString s);
bool estUnOperateur1(const QString s);
bool estUnOperateur2(const QString s);
bool estUnOperateurLog(const QString s);
bool estUnOperateur(const QString s);
bool estUnLitteraleNum(const QString s);
bool estUnEntier(const QString s);
bool estUnRationnel(const QString s);
bool estUnReel(const QString s);
bool estUnComplexe(const QString s);
bool estUnAtome(const QString s);
bool estUneExpression(const QString s);
bool estUnProgramme(const QString s);
#endif

