#ifndef OPERANDE_H
#define OPERANDE_H




#include "include.h"
#include "litterale.h"

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
    void additionExpression(Litterale* L1,Litterale* L2);


};

class soustraction : public operande{

public:
    int typeoperande()const {return 2;}
    void operator() ();
    void soustractionExpression(Litterale* L1,Litterale* L2);

};



class multiplication : public operande{
public:
    int typeoperande() const {return 4;}
    void operator() ();
    void multiplicationExpression(Litterale* L1,Litterale* L2);

};

class division : public operande{
public:
    int typeoperande() const {return 4;}
    void operator() ();
    void divisionExpression(Litterale* L1,Litterale* L2);

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

class RE : public operande{
public :
    int typeoperande() const {return 7;}
    void operator() ();
};

class IM : public operande{
public :
    int typeoperande() const {return 7;}
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

class undo : public operande{
public :
    int typeoperande() const {return 24;}
    void operator() ();
};

class redo : public operande{
public :
    int typeoperande() const {return 25;}
    void operator() ();
};

class eval : public operande{
public :
    int typeoperande() const {return 27;}
    void operator() ();
    void EvalsurExp();
    void EvalsurPrg();
};

class sto : public operande{
public :
    int typeoperande() const {return 28;}
    void operator() ();
};

class ift : public operande{
public :
    int typeoperande() const {return 26;}
    void operator() ();
};


#endif // OPERANDE_H
