#ifndef MEMENTO_H
#define MEMENTO_H


#include "include.h"
class Pile;

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
    Pile* montremoilepasse(){
        Pile * a;
        Pile* temp;
        temp=etatsPasse.front();
        etatsPasse.pop_front();
        a=etatsPasse.front();
        etatsPasse.push_front(temp);
        return a;
    }

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


#endif // MEMENTO_H
