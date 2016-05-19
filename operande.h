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
    virtual bool verifierNum(){ return false;}
    virtual bool verifierL(){return false;}
    virtual bool verifierPile(){return false;}



};

class addition : public operande{

public:
    int typeoperande()const {return 1;}
    void operator() ();

};



#endif // OPERANDE_H
