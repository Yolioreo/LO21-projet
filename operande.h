#ifndef OPERANDE_H
#define OPERANDE_H




#include "include.h"
#include "litterale.h"

class operande{
/// \brief Cette classe abstraite  est la mère de toutes les opérations
public:
    /// permet de connaitre le numéro de l'opérande, pratique pour le débugage
    virtual int typeoperande()const =0;
    /// operateur () surchagé pour faire office de foncteur
    virtual void operator() () =0;
    /// permet de vérifier les éléments dans la pile
    virtual bool verifierNumArite2();
     /// permet de vérifier les éléments dans la pile
    virtual bool verifierNumArite1();
     /// permet de vérifier les éléments dans la pile
    virtual bool verifierL(){return false ;}
    /// permet de vérifier les éléments dans la pile
    virtual bool verifierPile(){return false ;}
    /// crée un string prêt à être utiliser par le litteral manager
    const QString creationStringLitterale(int tempRN, int tempRD, int tempIN, int tempID);
    /// permet de vérifier que l'opérateur passé en argument est un opérateur unaire
    bool operateurunaire(QString c);


};

class addition : public operande{
///\brief permet de faire l'addition
public:
    int typeoperande()const {return 1;}
    void operator() ();
    void additionExpression(Litterale* L1,Litterale* L2);


};

class soustraction : public operande{

    ///\brief permet de faire la soustraction
public:
    int typeoperande()const {return 2;}
    void operator() ();
    void soustractionExpression(Litterale* L1,Litterale* L2);

};



class multiplication : public operande{

    ///\brief permet de faire la multiplication
public:
    int typeoperande() const {return 4;}
    void operator() ();
    void multiplicationExpression(Litterale* L1,Litterale* L2);

};

class division : public operande{

    ///\brief permet de faire la division
public:
    int typeoperande() const {return 4;}
    void operator() ();
    void divisionExpression(Litterale* L1,Litterale* L2);

};


class complexise : public operande{

    ///\brief permet de créer un complexe
public:
    int typeoperande() const {return 5;}
    void operator() ();

};

class NEG : public operande{

    ///\brief permet de donner l'opposé d'un littéral
public :
    int typeoperande() const {return 6;}
    void operator() ();
};

class DEN : public operande{

    ///\brief permet de récuperer le dénominateur d'un littéral
public :
    int typeoperande() const {return 7;}
    void operator() ();
};

class NUM : public operande{

    ///\brief permet de récuperer le numérateur d'un littéral
public :
    int typeoperande() const {return 8;}
    void operator() ();
};

class RE : public operande{

    ///\brief permet de récuperer la partie réel d'un littéral
public :
    int typeoperande() const {return 7;}
    void operator() ();
};

class IM : public operande{

    ///\brief permet de récuperer la partie imaginaire d'un littéral
public :
    int typeoperande() const {return 7;}
    void operator() ();
};

class DIV : public operande{

    ///\brief permet de donner le résultat d'une division entière
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

    ///\brief permet de comparer deux littéraux
public :
    int typeoperande() const {return 12;}
    void operator() ();
};

class inferieur : public operande{

    ///\brief permet de comparer deux littéraux
public :
    int typeoperande() const {return 13;}
    void operator() ();
};

class superieur : public operande{

    ///\brief permet de comparer deux littéraux
public :
    int typeoperande() const {return 14;}
    void operator() ();
};

class inferieurOuEgale : public operande{

    ///\brief permet de comparer deux littéraux
   public :
    int typeoperande() const {return 15;}
    void operator() ();
};

class superieurOuEgale : public operande{

    ///\brief permet de comparer deux littéraux
public :
    int typeoperande() const {return 16;}
    void operator() ();
};

class AND : public operande{

    ///\brief permet de faire une opération logique
public :
    int typeoperande() const {return 17;}
    void operator() ();
};

class OR : public operande{

    ///\brief permet de faire une opération logique
public :
    int typeoperande() const {return 18;}
    void operator() ();
};

class NOT : public operande{

    ///\brief permet de faire une opération logique
public :
    int typeoperande() const {return 19;}
    void operator() ();
};

class dup : public operande{

    ///\brief permet de dupliquer le top de la pile
public :
    int typeoperande() const {return 20;}
    void operator() ();
};
class drop : public operande{

    ///\brief permet de drop le top de la pile
public :
    int typeoperande() const {return 21;}
    void operator() ();
};
class Swap : public operande{
    ///\brief permet de swap les deux top de la pile
public :
    int typeoperande() const {return 22;}
    void operator() ();
};

class clear : public operande{
    ///\brief permet de clear la pile
public :
    int typeoperande() const {return 23;}
    void operator() ();
};

class lastop : public operande{

    ///\brief permet de refaire le dernier operateur
public:
    int typeoperande() const {return 24;}
    void operator() ();
};

class lastargs : public operande{
    ///\brief permet de repush les derniers arguments utilisés
public:
    int typeoperande() const {return 30;}
    void operator() ();
};

class undo : public operande{

    ///\brief permet de d'annuler une action
public :
    int typeoperande() const {return 25;}
    void operator() ();
};

class redo : public operande{

    ///\brief permet d'annuler l'annulation d'une action
public :
    int typeoperande() const {return 26;}
    void operator() ();
};

class eval : public operande{

    ///\brief permet d'évaluer une expression ou un programme
public :
    int typeoperande() const {return 27;}
    void operator() ();
    void EvalsurExp();
    void EvalsurPrg();
};

class sto : public operande{

    ///\brief permet d'affecter un atome à un litteral numérique ou programme
public :
    int typeoperande() const {return 28;}
    void operator() ();
};

class ift : public operande{

    ///\brief permet de faire un if en programmation
public :
    int typeoperande() const {return 29;}
    void operator() ();
};

class edit : public operande{

    ///\brief permet d'éditer un programme
public :
    int typeoperande() const {return 30;}
    void operator() ();
signals :
    void send();
};

//class forget: public operande{
//public:
//    int typeoperande() const {return 31;}
//    void operator() ();

//};


#endif // OPERANDE_H
