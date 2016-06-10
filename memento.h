#ifndef MEMENTO_H
#define MEMENTO_H


#include "include.h"
class Pile;
///\brief Cette classe va nous servir à sauvegarder les différents états de la pile à chaque commande
class Memento{
    friend class Pile;
    QVector<Pile*> etatsPasse;
    QVector<Pile*> etatsS;
public:
    Memento(Pile* P){
        etatsPasse.push_front(P);
    }
    Memento():etatsPasse(0), etatsS(0){}
    /// donne l'état actuellement sauvegardé de la pile
    Pile& getMemento() const{return *etatsPasse.front();}
    /// donnne le nombre d'états passé sauvegardé
    int getNbMemento()const {return etatsPasse.count();}
    /// donne le nombre d'états futurs sauvegardé
    int getNbFutur()const{return etatsS.count();}
    /// permet de supprimer l'ensemble des états futur
    void clearFutur(){etatsS.clear();}
    ///méthode servant pour récupérer l'état de la pile juste une itération dans le passé (pratique pour LASTARGS)
    /// Elle ne modifie rien
    Pile* montremoilepasse(){
        Pile * a;
        Pile* temp;
        temp=etatsPasse.front();
        etatsPasse.pop_front();
        a=etatsPasse.front();
        etatsPasse.push_front(temp);
        return a;
    }
    /// Cette méthode récupère aussi l'état de la pile passé mais en vue d'un UNDO
    /// Elle modifie le memento
    Pile* getMementoAvant(){
        Pile* a;
        pushFutur(etatsPasse.front());

        etatsPasse.pop_front();
        a=etatsPasse.front();

        etatsPasse.pop_front();

        return a;
    }
    /// permet de pusher un état passé de la pile
    void pushMemento(Pile* p){etatsPasse.push_front(p);}
    /// permet de pusher un état futur de la pile
    void pushFutur(Pile* p){etatsS.push_front(p);}
    /// Cette méthode récupère aussi l'état de la pile futur mais en vue d'un REDO
    /// Elle modifie le memento
    Pile* getMementoApres(){
        Pile* a;
        a=etatsS.front();

        etatsS.pop_front();
        return a;
    }

};


#endif // MEMENTO_H
