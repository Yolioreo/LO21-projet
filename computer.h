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
    Q_OBJECT


    unsigned int nb;
public:
    LitteraleManager():nb(0){}
    ~LitteraleManager();

    Litterale* addLitterale(const QString& v);
    void removeLitterale(Litterale* e);
    unsigned int getNbLiterrale(){return nb;}
    static LitteraleManager& getInstance();
    static void libererInstance();
signals :
    void erreurDivZero();




};

class Pile : public QObject {
    Q_OBJECT



    QString message;
    unsigned int nb;
    unsigned int nbAffiche;
    friend class LitteraleManager;
    QStack<Litterale*> PileLit;
public:


    Pile():message(""),nb(0),nbAffiche(4){
        PileLit.clear();

    }
    Pile(const Pile& a):message(a.message),nb(a.nb),nbAffiche(a.nbAffiche),PileLit(a.PileLit){}

    ~Pile();
    Pile& operator=(Pile& a){
        message=a.message;
        nb=a.nb;
        nbAffiche=a.nbAffiche;
        for (unsigned int i=0; i<a.getNbLitterale();i++)
            PileLit[i]=a.PileLit[i];
        return *this;
    }
    void push(Litterale* e);
    void pop();
    bool estVide() const { return PileLit.isEmpty(); }

    void affiche(QTextStream& f) const;
    Litterale* top() const;
    void setNbLitteraleToAffiche(unsigned int n) { nbAffiche=n; }
    unsigned int getNbLitteraleToAffiche() const { return nbAffiche; }
    void setMessage(const QString& m) { message=m; modificationEtat(); }
    QString getMessage() const { return message; }
    unsigned int getNbLitterale(){return nb;}

    class iterator{
    QStack<Litterale*> current;
    unsigned int index;
    friend class Pile;
    public:
    iterator(QStack<Litterale*> p, unsigned int a):current(p),index(a){}
    Litterale* operator*(){return current[index];}
    bool operator!=(Pile::iterator a){return index!=a.index;}
    iterator operator++(){index++; return *this;}
    };

    Pile::iterator begin(){return iterator(PileLit,0);}
    Pile::iterator end(){return iterator(PileLit,nb);}

signals:
    void modificationEtat();
public slots:
    void afficheDivZero(){setMessage("Impossible il y a une division par zéro");}

};



class Controleur : public QObject{
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
    void initialisationMap();
    static Controleur& getInstance(LitteraleManager& Mng,Pile& stack);
    static Controleur& getInstance();
    static void libererInstance();

    unsigned int getNbLitterale(){
        return LitAff.getNbLitterale();
    }
    bool faitpartiedeMap(const QString s){return faire.contains(s);}
    void push(Litterale* e){ LitAff.push(e);}
    Litterale* top(){ return LitAff.top();}
    void pop(){LitAff.pop();}
    void setMessage(const QString& s) const {LitAff.setMessage(s);}
    QString getLastOperande(){return lastoperande;}
    Litterale* addLitterale(QString e){return LitMng.addLitterale(e);}
    void removeLitterale(Litterale* e){LitMng.removeLitterale(e);}
    void commande(const QString& c);
    void setPile(Pile& P){LitAff=P; modificationEtat();}

    // partie memento

    Pile* getMementoAvant(){return memento.getMementoAvant();}
    Pile* getMementoApres(){return memento.getMementoApres();}
    void pushMemento(){memento.pushMemento(new Pile(LitAff)); qDebug("On a sauvegardé la pile");}
    int getNbMemento(){return memento.getNbMemento();}
    int getNbFutur(){return memento.getNbFutur();}
    void clearFutur(){memento.clearFutur();}

    // partie création de variables

    bool estUneVariable(QString& c)const {
      for (QMap<Atome *, Litterale*>::const_iterator it = variable.constBegin(); it != variable.constEnd(); ++it) {
          if(it.key()->afficher()==c){
              return true;
            }
      }
      return false;
    }
    void creationVariable(Atome* a,Litterale* l){
        variable[a]=l;
        setMessage(l->afficher()+" stocké dans "+a->afficher());
    }
    unsigned int getNbVariable(){return variable.size();}
    QMap<Atome*,Litterale*> getVar()const{return variable;}

signals:
    void modificationEtat();
public slots :
    void slotOperator(); // à définir


};

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

