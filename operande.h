#ifndef OPERANDE_H
#define OPERANDE_H

#include "computer.h"


class operande{

public:
    virtual int typeoperande()const =0;
    virtual void operator()() =0;
    virtual bool verifierNum(){ return false;}
    virtual bool verifierL(){return false;}
    virtual bool verifierPile(){return false;}



};

class addition : public operande{

public:
    int typeoperande()const {return 1;}
    void operator() (){qDebug("Test");}
};



#endif // OPERANDE_H
