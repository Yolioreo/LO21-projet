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



Litterale& LitteraleManager::addLitterale(Litterale& v){
    lit.resize(nb+1);
    lit[nb++]=new Litterale(v);
    return *lit[nb-1];
}

void LitteraleManager::removeLitterale(Litterale& e){
    unsigned int i=0;
    while(i<nb && lit[i]!=&e) i++;
    if (i==nb) throw ComputerException("elimination d'une Expression inexistante");
    lit.erase(lit.begin()+i);
    nb--;
    lit.resize(nb);

}

LitteraleManager::~LitteraleManager(){
    for(unsigned int i=0; i<nb; i++) delete lit[i];
    lit.clear();
}






void Pile::push(Litterale& e){
    // checker si c'est une fraction et denominateur =1
    PileLit.push(&e);
    nb++;
    modificationEtat();
}

void Pile::pop(){
    nb--;
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

    if (nb==0) throw ComputerException("aucune expression sur la pile");
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

bool estUnNombre(const QString s){
   bool ok=false;
   s.toInt(&ok);
   return ok;
}


void Controleur::commande(const QString& c){ // A REVOIR : INTERPRETEUR
    if (estUnLitterale(c)){
        LitAff.push(LitMng.addExpression(c.toInt()));
    }else{

        if (estUnOperateur(c)){
            if (LitAff.getNbLitterale()>=2) {
                Litterale& v2=LitAff.top();
                LitMng.removeLitterale(LitAff.top());
                LitAff.pop();
                Litterale& v1=LitAff.top();
                LitMng.removeLitterale(LitAff.top());
                LitAff.pop();
                Litterale& res;
                if (c=="+") res=v1+v2;
                if (c=="-") res=v1-v2;
                if (c=="*") res=v1*v2;
                if (c=="/") {
                    if (v2!=0) res=v1/v2;
                    else {
                        LitAff.setMessage("Erreur : division par zéro");
                        res=v1;
                    }
                }
                Litterale& e=LitMng.addLitterale(res);
                LitAff.push(e);
            }else{
                LitAff.setMessage("Erreur : pas assez d'arguments");
            }
        }else LitAff.setMessage("Erreur : commande inconnue");
    }
}
