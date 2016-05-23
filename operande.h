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
    virtual bool verifierL(){}
    virtual bool verifierPile(){}


};

class addition : public operande{

public:
    int typeoperande()const {return 1;}
    void operator() ();


};

class complexise : public operande{
public:
    int typeoperande() const {return 4;}
    void operator() ();

};



#endif // OPERANDE_H
