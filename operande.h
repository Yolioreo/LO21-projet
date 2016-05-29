#ifndef OPERANDE_H
#define OPERANDE_H


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

class Controleur;
class Litterale;

class operande{

public:
    virtual int typeoperande()const =0;
    virtual void operator() () =0;
    virtual bool verifierNumArite2();
    virtual bool verifierNumArite1();
    virtual bool verifierL(){return false ;}
    virtual bool verifierPile(){return false ;}
    const QString creationStringLitterale(int tempRN, int tempRD, int tempIN, int tempID);



};

class addition : public operande{

public:
    int typeoperande()const {return 1;}
    void operator() ();


};

class soustraction : public operande{

public:
    int typeoperande()const {return 2;}
    void operator() ();


};



class multiplication : public operande{
public:
    int typeoperande() const {return 4;}
    void operator() ();

};

class division : public operande{
public:
    int typeoperande() const {return 4;}
    void operator() ();

};

class complexise : public operande{
public:
    int typeoperande() const {return 5;}
    void operator() ();

};

class NEG : public operande{
public :
    int typeoperande() const {return 6;}
    void operator() ();
};

class DEN : public operande{
public :
    int typeoperande() const {return 7;}
    void operator() ();
};

class NUM : public operande{
public :
    int typeoperande() const {return 8;}
    void operator() ();
};

class DIV : public operande{
public :
    int typeoperande() const {return 9;}
    void operator() ();
};

class MOD : public operande{
public :
    int typeoperande() const {return 10;}
    void operator() ();
};

class difference : public operande{
public :
    int typeoperande() const {return 11;}
    void operator() ();
};

class egalite : public operande{
public :
    int typeoperande() const {return 12;}
    void operator() ();
};

class inferieur : public operande{
public :
    int typeoperande() const {return 13;}
    void operator() ();
};

class superieur : public operande{
public :
    int typeoperande() const {return 14;}
    void operator() ();
};

class inferieurOuEgale : public operande{
public :
    int typeoperande() const {return 15;}
    void operator() ();
};

class superieurOuEgale : public operande{
public :
    int typeoperande() const {return 16;}
    void operator() ();
};

class AND : public operande{
public :
    int typeoperande() const {return 17;}
    void operator() ();
};

class OR : public operande{
public :
    int typeoperande() const {return 18;}
    void operator() ();
};

class NOT : public operande{
public :
    int typeoperande() const {return 19;}
    void operator() ();
};

class dup : public operande{
public :
    int typeoperande() const {return 20;}
    void operator() ();
};
class drop : public operande{
public :
    int typeoperande() const {return 21;}
    void operator() ();
};
class Swap : public operande{
public :
    int typeoperande() const {return 22;}
    void operator() ();
};

class clear : public operande{
public :
    int typeoperande() const {return 23;}
    void operator() ();
};

class lastop : public operande{
public:
    int typeoperande() const {return 24;}
    void operator() ();
};

#endif // OPERANDE_H
