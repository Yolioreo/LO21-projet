#ifndef LITTERALE_H
#define LITTERALE_H


#include "include.h"

class Litterale {
    Litterale(const Litterale& e);
    Litterale& operator=(const Litterale& e);
    friend class LitteraleManager;

public:
    virtual QString afficher()=0;//à mettre const
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
    Atome(const QString& a): atome(a){}
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
    Programme(const QString& s): programme(s){}
    QString afficher(){
    return programme;
    }
    bool isNull() const {return programme.isEmpty();}
};



#endif // LITTERALE_H
