#include "computer.h"
#include <algorithm>

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
    Entier* YO=new Entier(v.toInt());
    lit.push_back(YO);
    return lit.back();
}

void LitteraleManager::removeLitterale(Litterale* e){
    unsigned int i=lit.indexOf(e,0);
    if (i==-1) throw ComputerException("elimination d'une Expression inexistante");

    lit.remove(i); // pas optimisé mais c'est pas grave



}

LitteraleManager::~LitteraleManager(){
    // MEMENTO
}






void Pile::push(Litterale& e){
    // checker si c'est une fraction et denominateur =1
    PileLit.push(&e);
    modificationEtat();
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
    PileLit.clear();
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
    bool test=true;
    for( int i=0;i<s.size();i++)
    {
        if(s[i]<'0'||s[i]>'9')
            test=false;
    }
    return test;
}

bool estUnRationnel(const QString s){
    int compteanomalie=0;
    bool test2=false;// on cherche le /
    int i=0;
    for(i=0;i<s.size();i++)
    {
        if(s[i]<'0'||s[i]>'9')
            compteanomalie++;
        if (s[i]=='/')
        {
            test2=true;
            break;
        }

    }
    if (compteanomalie!=1) return false;
    compteanomalie=0;
    int j=i+1;
    for (j;j<s.size();j++)
    {
        if(s[j]<'0'||s[j]>'9')
            compteanomalie++;
    }
    if (compteanomalie!=0) return false;

    return test2;
}


bool estUnReel(const QString s){
    int compteanomalie=0;
    bool test2=false;// on cherche le /
    int i=0;
    for(i;i<s.size();i++)
    {
        if(s[i]<'0'||s[i]>'9')
            compteanomalie++;
        if (s[i]=='.')
        {
            test2=true;
            break;
        }

    }
    if (compteanomalie!=1) return false;
    compteanomalie=0;
    for (int j=i+1;j<s.size();j++)
    {
        if(s[j]<'0'||s[j]>'9')
            compteanomalie++;
    }
    if (compteanomalie!=0) return false;

    return test2;
}

bool estUnComplexe(const QString s){
    int compteanomalie=0;
    bool test2=false;// on cherche le /
    int i=0;
    for(i;i<s.size();i++)
    {
        if(s[i]<'0'||s[i]>'9')
            compteanomalie++;
        if (s[i]=='$')
        {
            test2=true;
            break;
        }

    }
    if (compteanomalie!=1) return false;
    compteanomalie=0;
    int j=i+1;
    for (j;j<s.size();j++)
    {
        if(s[j]<'0'||s[j]>'9')
            compteanomalie++;
    }
    if (compteanomalie!=0) return false;

    return test2;
}


bool estUnAtome(QString s){
    if (s[0]<'A'||s[0]<'Z')return false;
    bool test=true;
    for(int i=0;i<s.size();i++)
    {
        if(!((s[i]>'0')&&(s[i]<'9')||((s[i]>'A')&&(s[i]<'Z')))){
                test=false;
                break;
        }

    }
    if (test=true){
        if(s.compare("DIV")==0||s.compare("NEG")==0||s.compare("NUM")==0||s.compare("DEN")==0||s.compare("RE")==0|| s.compare("IM")==0)
    {
            test=false;
    }
    }
    return test;
}


bool estUneExpression(const QString s){

    return ((s[0]=="'")&&(s[s.size()]=="'"));
}

bool estUnProgramme(const QString s){

    return ((s[0]=="[")&&(s[s.size()]=="]"));
}

void Controleur::commandeEx(const QString& s) //gerer le cas d'une expression
{

}


void Controleur::commandeP(const QString& s)//gerer le cas d'un Programme
{

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

   // if (estUneExpression(c))commandeEx(c);
    //if(estUnProgramme(c))commandeP(c);

    if (estUnLitterale(c)){
        //checker cas d'un atome correspond à une opération
        qDebug("salut");
       LitAff.push(*LitMng.addLitterale(c));

    }else{
        if (estUnOperateur(c)){
            if(LitAff.getNbLitterale()>=2){


                Litterale& T1=LitAff.top();
                LitMng.removeLitterale(&LitAff.top());
                LitAff.pop();
                Litterale& T2=LitAff.top();
                LitMng.removeLitterale(&LitAff.top());
                LitAff.pop();
                // IL FAUT CREER DES SURCHAGES DE FONCTIONS POUR CHAQUES CAS ou alors templates méthodes mais riqué
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
