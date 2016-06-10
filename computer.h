
#ifndef _COMPUTER_H
#define _COMPUTER_H


#include "include.h"
#include "memento.h"
#include "litterale.h"
#include "operande.h"


using namespace std;

class ComputerException {
    QString info;
public:
    ComputerException(const QString& str):info(str){}
    QString getInfo() const { return info; }
};


class LitteraleManager : public QObject {
/// \brief Cette classe gère la création et la destruction des littéraux

    Q_OBJECT
    unsigned int nb;
public:
    LitteraleManager():nb(0){}
    ~LitteraleManager();
    /// ajoute un littéral avec un parseur
    Litterale* addLitterale(const QString& v);
    /// détruit un littéral
    void removeLitterale(Litterale* e);
    /// donne le nombre de Litteraux
    unsigned int getNbLiterrale(){return nb;}
signals :
    void erreurDivZero(); /// un signal qui verifie que les données qu'on lui envoie sont corrects
};


class Pile : public QObject {
    /// \brief C'est ici que seront stocké les littéraux dont on est en train de se servir
    Q_OBJECT
    QString message;
    unsigned int nb;
    unsigned int nbAffiche;
    friend class LitteraleManager;
    QStack<Litterale*> PileLit;
public:
    Pile():message(""),nb(0),nbAffiche(4){
        PileLit.clear();
        qDebug()<<"Initialisation pile";
        chargementcontexte();

    }
    Pile(const Pile& a):message(a.message),nb(a.nb),nbAffiche(a.nbAffiche),PileLit(a.PileLit){}

    ~Pile();
     /// l'operateur = permet de recopier une pile dans une autre, pratique pour le changement de contexte
    Pile& operator=(Pile& a){
        message=a.message;
        nb=a.nb;
        nbAffiche=a.nbAffiche;
        PileLit.resize(a.getNbLitterale());
        for (unsigned int i=0; i<a.getNbLitterale();i++)
            PileLit[i]=a.PileLit[i];
        return *this;
    }
    /// permet de push un litteral dans la pile
    void push(Litterale* e);
    /// permet de pop un litteral de la pile
    void pop();
    /// teste si  la pile est vide
    bool estVide() const { return PileLit.isEmpty(); }
    /// permet d'afficher le contenu de la pile
    void affiche(QTextStream& f) const;
    /// permet de connaitre le premier element de la pile
    Litterale* top() const;
    ///permet de changer le nombre de litteraux à afficher sur la pile
    void setNbLitteraleToAffiche(unsigned int n) { nbAffiche=n; }
    /// permet de connaitre le nombre de litteraux à afficher sur la pile
    unsigned int getNbLitteraleToAffiche() const { return nbAffiche; }
   /// permet de mettre un message en haut de la calculatrice ( message d'erreur)
    void setMessage(const QString& m) {
      message=m;
      modificationEtat();
      if(m!="")
      bipsonore();
    }
    /// permet de récuperer le message affiché au dessus de la pile
    QString getMessage() const { return message; }
    /// permet de connaitre le nombre de littéraux sur la pile
    unsigned int getNbLitterale(){return nb;}

    class iterator{
        ///\brief c'est un simple iterateur de la classe Pile
        QStack<Litterale*> current;
        unsigned int index;
        friend class Pile;
    public:
        iterator(QStack<Litterale*> p, unsigned int a):current(p),index(a){}
        Litterale* operator*(){return current[index];}
        bool operator!=(Pile::iterator a){return index!=a.index;}
        iterator operator++(){index++; return *this;}
    };
    /// donne un itérateur sur le premier élément de la pile
    Pile::iterator begin(){return iterator(PileLit,0);}

    /// donne un itérateur sur le premier dernier de la pile
    Pile::iterator end(){return iterator(PileLit,nb);}

signals:
    /// signal permet de rafraichir l'affichage
    void modificationEtat();
    /// signal envoyer au début pour récupérer les informations de la dernière session
    void chargementcontexte();
    /// signal pour envoyer un bip quand il y a une erreur
    void bipsonore();
public slots:
    void afficheDivZero(){setMessage("Impossible il y a une division par zéro");}

};



class Controleur : public QObject{
    ///\brief cette classe gère l'ensemble des litteraux,de la pile, du litteral Manager. C'est un singleton qui est utilisé quasiment partout
    Q_OBJECT

    LitteraleManager& LitMng;
    Pile& LitAff;
    Memento memento;
    QMap<QString,operande*> faire;
    QMap<Atome*,Litterale*> variable;
    QString lastoperande;
    Controleur(LitteraleManager& m, Pile& v):LitMng(m), LitAff(v){
        pushMemento();
        connect(&LitMng,SIGNAL(erreurDivZero()),&LitAff,SLOT(afficheDivZero()));
        initialisationMap();
    }
    struct Handler1{
        ///\brief ceci est la structure de création du singleton Controleur
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
    /// permet de lier les opérateurs à leurs foncteurs
    void initialisationMap();
    /// permet de récupérer une instance du controleur (création)
    static Controleur& getInstance(LitteraleManager& Mng,Pile& stack);
    /// surchage pour permettre de rapidement récupérer une instance du controleur
    static Controleur& getInstance();
    /// permet de libérer l'instance du controleur
    static void libererInstance();
    /// permet de récupéer le nombre d'éléments dans la pile
    unsigned int getNbLitterale() const{
        return LitAff.getNbLitterale();
    }
    ///permet de savoir si un opérateur fait bien parti des opérateurs mappés
    bool faitpartiedeMap(const QString& s){return faire.contains(s);}
    /// permet de push un litteral dans la pile
    void push(Litterale* e){ LitAff.push(e);}
    /// permet de récupérer l'élément sur la pile
    Litterale* top(){ return LitAff.top();}
    /// permet de pop un littéral de la pile
    void pop(){LitAff.pop();}
    /// permet de changer le message affiché au dessus de la pile
    void setMessage(const QString& s) const {LitAff.setMessage(s);}
    /// permet de récupérer le dernier opérande de la pile
    QString getLastOperande(){return lastoperande;}
    /// permet de créer un litteral dans le litteral manager
    Litterale* addLitterale(QString e){return LitMng.addLitterale(e);}//vérifier si modifie e
    /// permet de supprimer un litterale du litteral manager
    void removeLitterale(Litterale* e){LitMng.removeLitterale(e);}
    /// Fonction principale du Controleur ! Elle permet de gérer tous ce qu'on lui envoie
    void commande(const QString& c);
    /// permet de changer l'état de la pile
    void setPile(Pile& P){ LitAff=P; modificationEtat();}

    // partie memento
    /// Cette partie gère le memento (pour un Undo)
    Pile* getMementoAvant(){return memento.getMementoAvant();}
     /// Cette partie gère le memento (pour un Redo)
    Pile* getMementoApres(){return memento.getMementoApres();}
    ///permet de sauvegarder un etat de la pile
    void pushMemento(){memento.pushMemento(new Pile(LitAff));}
    /// permet de vérifier combien d'états de pile ont a sauvegardé
    int getNbMemento(){return memento.getNbMemento();}//mettre const
    int getNbFutur(){return memento.getNbFutur();}//mettre const
    void clearFutur(){memento.clearFutur();}
    Pile* montremoilepasse(){return memento.montremoilepasse();}

    // partie création de variables
    ///Cette méthode teste si le stringe envoyé est bien une variable du map de variables
    bool estUneVariable(const QString& c)const {
      for (QMap<Atome *, Litterale*>::const_iterator it = variable.constBegin(); it != variable.constEnd(); ++it) {
          if(it.key()->afficher()==c){
              return true;
            }
      }
      return false;
    }
    /// permet de créer une variable dans le map de variables
    void creationVariable(Atome* a,Litterale* l){
        variable[a]=l;
        setMessage(l->afficher()+" stocké dans "+a->afficher());
    }
    /// permet de connaitre le nombre de variables contenu dans le map de variables
    unsigned int getNbVariable(){return variable.size();}
    /// permet de récupérer le map de variables
    QMap<Atome*,Litterale*> getVar()const{return variable;}
       /// il y a un iterateur sur les variables
    class iterator_variable : public QMap<Atome*,Litterale*>::const_iterator {
    public :
        iterator_variable(QMap<Atome*,Litterale*>::const_iterator it):QMap<Atome*,Litterale*>::const_iterator(it){}
    };
    ///  retourne un iterateur sur le "premier" élément du map de variables
    iterator_variable begin_variable(){return iterator_variable(variable.constBegin());}

    ///  retourne un iterateur sur le "dernier" élément du map de variables
    iterator_variable end_variable(){return iterator_variable(variable.constEnd());}

signals:

    void modificationEtat();
    /// Ceci permet de changer de fenetre lors d'un EDIT
    void sendPrgm();

public slots :
    void slotOperator();
};

///\brief
bool estUnLitteraleNum(const QString s);
bool estUnEntier(const QString s);
bool estUnRationnel(const QString s);
bool estUnReel(const QString s);
bool estUnComplexe(const QString s);
bool estUnAtome(const QString s);
bool estUneExpression(const QString s);
bool estUnProgramme(const QString s);
bool isOperator(const QString s);
QString parseExpression(const QString& s);
bool isHigher(QString a, QString b);
int order(QString op);
bool isChar(QChar a);
bool isPartOperand(QChar a, QString s, int i);

#endif

