#include "computer.h"
#include <algorithm>
#include <QRegExp>

LitteraleManager::Handler LitteraleManager::handler=LitteraleManager::Handler();


LitteraleManager& LitteraleManager::getInstance(){
    if (handler.instance==nullptr) handler.instance=new LitteraleManager;
    return *handler.instance;
}

void LitteraleManager::libererInstance(){
    delete handler.instance;
    handler.instance=nullptr;
}



Litterale* LitteraleManager::addLitterale(const QString& v){
    // analyser le string et pusher le bon litterale
    if (estUnEntier(v))
    {
        Entier* YO=new Entier(v.toInt());

        lit.push_back(YO);
        qDebug ("C'est un entier");
    }
    if (estUnReel(v))
    {
        Reel* YO=new Reel(v.toDouble());

        lit.push_back(YO);
        qDebug ("C'est un reel");
    }
    if (estUnRationnel(v))
    {   qDebug ("C'est un rationnel");

        QStringList r;
        r=v.split("/"); // on sépare les deux parties autour du "/"

        if(r[1].toInt()!=0){
        Rationnel* YO=new Rationnel(r[0].toInt(),r[1].toInt());
        lit.push_back(YO);
        return lit.back();
        }
        else
        {   qDebug("denominateur nul");
            erreurDivZero();
            return nullptr;
        }



    }
    if (estUnComplexe(v))
    {
        QStringList r=v.split("$"); // on sépare les deux parties autour du "/"
        Complexe<double> *YO=new Complexe<double>(r[0].toDouble(),r[1].toDouble());
        qDebug ("C'est un complexe");

        lit.push_back(YO);
    }
    if (estUnAtome(v)){
        lit.push_back(new Entier(666));// simple test temporaire
    }

    return lit.back();
}

void LitteraleManager::removeLitterale(Litterale* e){
    int i=lit.indexOf(e,0);
    if (i==-1) throw ComputerException("elimination d'une Expression inexistante");

    lit.remove(i); // pas optimisé mais c'est pas grave



}

LitteraleManager::~LitteraleManager(){
    // MEMENTO et destruction de tous les littéraux

}

void Pile::push(Litterale* e){
    // checker si c'est une fraction et denominateur =1
    if(e!=nullptr)
    {
    PileLit.push_front(e);
    modificationEtat();
    }
}

void Pile::pop(){
    PileLit.pop();
    modificationEtat();
}

/*void Pile::affiche(QTextStream& f) const{
    f<<"********************************************* \n";
    f<<"M : "<<message<<"\n";
    f<<"---------------------------------------------\n";
    for(int i=nbAffiche; i>0; i--) {
        if (i<=nb) f<<i<<": "<<items[nb-i].getExpression().toString()<<"\n";
        else f<<i<<": \n";
    }
    f<<"---------------------------------------------\n";
}
*/


Pile::~Pile(){

}

Litterale& Pile::top() const {

    if (PileLit.size()==0) throw ComputerException("aucune expression sur la pile");
    return *(PileLit.top());
}



bool estUnOperateur(const QString s){
    if (s=="+") return true;
    if (s=="-") return true;
    if (s=="*") return true;
    if (s=="/") return true;
    if (s=="$") return true;
    return false;
}


bool estUnLitterale(const QString s){

   return (estUnAtome(s)||estUnComplexe(s)||estUnEntier(s)||estUnRationnel(s)||estUnReel(s));
}

bool estUnEntier(const QString s){
    bool test=false;
    if(s.toInt(&test))return test;
    return test;
}

bool estUnRationnel(const QString s){

    bool test=false;
    QRegExp r("^(\\d+)/(\\d+)$");
    if(s.contains(r))
            test=true;
    return test;
}


bool estUnReel(const QString s){

    bool test=false;
    if(s.toDouble(&test))return test;
    return test;
}

bool estUnComplexe(const QString s){

    bool test=false;
    QRegExp r("^(\\d+)(\\${1})(\\d+)$");
    if(s.contains(r))
            test=true;
    return test;
    return test;
}


bool estUnAtome(QString s){

    bool test=false;
    QRegExp rx("^[A-Z][A-Z0-9]{,5}$");
    if(s.contains(rx))test=true;
    if (test==true){
        if(s.compare("DIV")==0||s.compare("NEG")==0||s.compare("NUM")==0||s.compare("DEN")==0||s.compare("RE")==0|| s.compare("IM")==0)
    {
            test=false;
    }
    }
    return test;
}


bool estUneExpression(const QString s){

    return ((s[0]=='\'')&&(s[s.size()-1]=='\''));
}

bool estUnProgramme(const QString s){

    return ((s[0]=='[')&&(s[s.size()-1]==']'));
}

void Controleur::commandeEx(const QString& s) //gerer le cas d'une expression
{
    qDebug ("expression");

}


void Controleur::commandeP(const QString& s)//gerer le cas d'un Programme
{
    qDebug ("Programme");
}


void Controleur::commande(const QString& c){ // A REVOIR : INTERPRETEUR
//    if (estUnLitterale(c)){
//        LitAff.push(LitMng.addLitterale(c.toInt()));
//    }else{

//        if (estUnOperateur(c)){
//            if (LitAff.getNbLitterale()>=2) {
//                Litterale& v2=LitAff.top();
//                LitMng.removeLitterale(LitAff.top());
//                LitAff.pop();
//                Litterale& v1=LitAff.top();
//                LitMng.removeLitterale(LitAff.top());
//                LitAff.pop();
//                Litterale& res;
//                if (c=="+") res=v1+v2;
//                if (c=="-") res=v1-v2;
//                if (c=="*") res=v1*v2;
//                if (c=="/") {
//                    if (v2!=0) res=v1/v2;
//                    else {
//                        LitAff.setMessage("Erreur : division par zéro");
//                        res=v1;
//                    }
//                }
//                Litterale& e=LitMng.addLitterale(res);
//                LitAff.push(e);
//            }else{
//                LitAff.setMessage("Erreur : pas assez d'arguments");
//            }
//        }else LitAff.setMessage("Erreur : commande inconnue");
//    }

   if (estUneExpression(c))commandeEx(c);
    if(estUnProgramme(c))commandeP(c);

    if (estUnLitterale(c)){
        //checker cas d'un atome correspond à une opération
        qDebug("C'est un litterale");
       LitAff.push(LitMng.addLitterale(c));

    }else{
        if (estUnOperateur(c)){
            if(LitAff.getNbLitterale()>=2){


                Litterale& T1=LitAff.top();
                LitMng.removeLitterale(&LitAff.top());
                LitAff.pop();
                Litterale& T2=LitAff.top();
                LitMng.removeLitterale(&LitAff.top());
                LitAff.pop();
                // IL gérer ces fonctions DE FONCTIONS POUR CHAQUES CAS ou alors templates méthodes mais riqué
//                if (c=="+") division(T1,T2);
//                if (c=="-") soustraction(T1,T2);
//                if (c=="*") multplication(T1,T2);
//                if (c=="/") division(T1,T2);
//                if(c=="$")complexisation(T1,T2);

            }else{
                LitAff.setMessage("Erreur : Pas assez d'arguments");
            }
        }else{
            LitAff.setMessage("Erreur : commande inconnue");
        }

    }
}
