#include "computer.h"
#include <algorithm>
#include <QRegExp>


//LitteraleManager::Handler LitteraleManager::handler=LitteraleManager::Handler();

//LitteraleManager& LitteraleManager::getInstance(){
//    if (handler.instance==nullptr) handler.instance=new LitteraleManager;
//    return *handler.instance;
//}

//void LitteraleManager::libererInstance(){
//    delete handler.instance;
//    handler.instance=nullptr;
//}

Controleur::Handler1 Controleur::handler=Controleur::Handler1();

void Controleur::libererInstance(){
    delete handler.instance;
    handler.instance=nullptr;
}

Controleur& Controleur::getInstance(LitteraleManager& Mng,Pile& stack){
    if (handler.instance==nullptr) handler.instance=new Controleur(Mng,stack);
    return *handler.instance;
}
Controleur& Controleur::getInstance(){
    if(handler.instance==nullptr)qDebug()<<"Problème de passage de singleton";
    return *handler.instance;
}



Litterale* LitteraleManager::addLitterale(const QString& v){
    // analyser le string et pusher le bon litterale
   Litterale* YO;
    qDebug()<<v;
    if (estUnEntier(v)&&(!v.contains("$")))
    {
        YO=new Entier(v.toInt());


        qDebug ("C'est un entier");
    }
    if (estUnReel(v)&&(!v.contains("$")))
    {
        YO=new Reel(v.toDouble());


        qDebug ("C'est un reel");
    }
    if (estUnRationnel(v)&&(!v.contains("$")))
    {   qDebug ("C'est un rationnel");

        QStringList r;
        r=v.split("/"); // on sépare les deux parties autour du "/"

        if(r[1].toInt()!=0){
            YO=new Rationnel(r[0].toInt(),r[1].toInt());
        }
        else
        {   qDebug("denominateur nul");
            erreurDivZero();
            return nullptr;
        }



    }
    if(estUnComplexe(v)){
        QStringList ReIm,RE,IM;
        ReIm=v.split("$");
        qDebug ("C'est un complexe");

        RE=ReIm[0].split("/");
        IM=ReIm[1].split("/");
        LitteraleNum* r;
        LitteraleNum* i;

        qDebug()<<RE[0]<<IM[0];

        if(IM.count()==2){
            if(IM[1]=="1")i=new Reel(IM[0].toDouble());
            else i=new Rationnel(IM[0].toInt(),IM[1].toInt());

        }
        else{
            qDebug()<<(IM[0].toDouble());
            i=new Reel(IM[0].toDouble());
        }

        if(RE.count()==2){
            if(RE[1]=="1")r=new Reel(RE[0].toDouble());
            else r=new Rationnel(RE[0].toInt(),RE[1].toInt());

        }
        else{
            qDebug()<<RE[0].toDouble();
            r=new Reel(RE[0].toDouble());
        }
        qDebug("je suis passé par là");
        YO=new Complexe(*r,*i);



    }
    if (estUneExpression(v)){
        YO =new Expression(v);
        qDebug ("C'est une expression");

    }
    if (estUnProgramme(v)){
        YO=new Programme(v);
        qDebug ("C'est un programme");

    }
    nb++;
    return YO;
}

void LitteraleManager::removeLitterale(Litterale* e){
    delete e;
}

LitteraleManager::~LitteraleManager(){
    // MEMENTO et destruction de tous les littéraux


}

void Pile::push(Litterale* e){
    // checker si c'est une fraction et denominateur =1
    // checker si c'est un complexe
    if(e!=nullptr)
    {
    PileLit.push_front(e);
    nb++;
    modificationEtat();
    }
}

void Pile::pop(){
    PileLit.pop_front();
    nb--;
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

Litterale* Pile::top() const {

    if (PileLit.size()==0) throw ComputerException("aucune expression sur la pile");
    return (PileLit.front());
}



bool estUnOperateurNum(const QString s){

    if (s=="+") return true;
    if (s=="-") return true;
    if (s=="*") return true;
    if (s=="/") return true;
    if (s=="$") return true;
    if (s=="DIV") return true;
    if (s=="NEG") return true;
    if (s=="NUM") return true;
    if (s=="DEN") return true;
    if (s=="IM") return true;
    if (s=="RE") return true;
    return false;
}
bool estUnOperateur2(const QString s){
    if (s=="+") return true;
    if (s=="-") return true;
    if (s=="*") return true;
    if (s=="/") return true;
    if (s=="$") return true;
    if (s=="DIV") return true;
    return false;
}
bool estUnOperateur1(const QString s){
    if (s=="NEG") return true;
    if (s=="NUM") return true;
    if (s=="DEN") return true;
    if (s=="IM") return true;
    if (s=="RE") return true;
    if (s=="NOT") return true;
    return false;
}


bool estUnOperateurLog(const QString s){

    if (s=="=") return true;
    if (s=="!=") return true;
    if (s=="=<") return true;
    if (s=="=>") return true;
    if (s=="<") return true;
    if (s==">") return true;
    if (s=="AND") return true;
    if (s=="OR") return true;
    if (s=="NOT") return true;


    return false;
}
bool estUnOperateur(const QString s){
    return (estUnOperateurLog(s)||estUnOperateurNum(s));
}



bool estUnLitteraleNum(const QString s){

   return (estUnEntier(s)||estUnRationnel(s)||estUnReel(s));
}

bool estUnEntier(const QString s){
    bool test=false;
    if(s.toInt(&test))return test;
    return test;
}

bool estUnRationnel(const QString s){

    bool test=false;
    QRegExp r("^(-?)(\\d+)/(-?)(\\d+)$");
    if(s.contains(r))
            test=true;
    return test;
}


bool estUnReel(const QString s){

    bool test=false;
    QRegExp r("^(-?)(\\d+).(-?)(\\d+)$");
    if(s.contains(r))
            test=true;
    return test;
}

bool estUnComplexe(const QString s){
    qDebug()<<s;
    bool test=false;
    QRegExp r("^(-?)(\\d+)([.||/]?)(-?)(\\d*)(\\$)(-?)(\\d+)([.||/]?)(-?)(\\d*)$");
    if(s.contains(r))
            test=true;
    qDebug()<<test;
    return test;
}


bool estUnAtome(QString s){

    Controleur* controle=&Controleur::getInstance();
    if(controle->faitpartiedeMap(s))return false;

    bool test=false;
    QRegExp rx("^[A-Z][A-Z0-9]{,5}$");
    if(s.contains(rx))test=true;

    return test;
}


bool estUneExpression(const QString s){

    return ((s[0]=='\'')&&(s[s.size()-1]=='\''));
}

bool estUnProgramme(const QString s){

    return ((s[0]=='[')&&(s[s.size()-1]==']'));
}

/*///////////// méthodes du controleur /////////////*/



void Controleur::initialisationMap(){

      faire["+"]=new addition;
      faire["-"]=new soustraction;
      faire["/"]=new division;
      faire["*"]=new multiplication;
      faire["$"]=new complexise;
      faire["NEG"]= new NEG;
      faire["DEN"]= new DEN;
      faire["NUM"]= new NUM;
      faire["DIV"]= new DIV;
      faire["MOD"]= new MOD;
      faire["!="]= new difference;
      faire["="]= new egalite;
      faire["<"]= new inferieur;

}

void Controleur::commandeEx(const QString& s) //gerer le cas d'une expression
{
    qDebug (" Gestion de l'expression");

}


void Controleur::commandeP(const QString& s)//gerer le cas d'un Programme
{
    qDebug ("Gestion du Programme");
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



    if (estUnComplexe(c)||estUnLitteraleNum(c)||estUneExpression(c)||estUnProgramme(c)){


       LitAff.push(LitMng.addLitterale(c));

    }else{
        /*if (estUnOperateur(c)){
            qDebug("C'est un opérateur");
            if(LitAff.getNbLitterale()==0){
                LitAff.setMessage("Erreur : Il n'y a pas d'argument dans la pile");
            return;
            }

            Litterale* L2=LitAff.top();


            qDebug("On vient de récupérer le top");
            //LitMng.removeLitterale((LitAff.top()));


            qDebug("On a détruit dans pile");

            if (estUnLitteraleNum(L2->afficher())||estUnComplexe(L2->afficher())){
                qDebug("le premier argument est un numérique ");
                if(estUnOperateurNum(c)){
                    qDebug("loperateur est numérique ");
                    if((LitAff.getNbLitterale()>=2)&&(estUnOperateur2(c))){
                        LitAff.pop();
                        Litterale* L1=LitAff.top();
                        LitAff.pop();
                        qDebug("On vient de récupérer le top");
                        //LitMng.removeLitterale(LitAff.top());



                        if(estUnLitteraleNum(L1->afficher())||estUnComplexe(L1->afficher())){

                            if(c=="+") addition(L1,L2);
                            if(c=="-")  soustraction(L1,L2);;
                            if(c=="*") multiplication(L1,L2);;
                            if(c=="/")division(L1,L2);
                            if(c=="DIV") divisionE(L1,L2);
                            if(c=="$") {

                                if(estUnComplexe(L2->afficher())&&estUnComplexe(L1->afficher()))complexise(L1,L2);
                                else LitAff.setMessage("Opération impossible Il y a deja un complexe");
                            }

                            return; // j'ai fini tout bien

                        }else{
                            if(estUnProgramme(L1->afficher())||estUnComplexe(L1->afficher())){
                                LitAff.push(LitMng.addLitterale(L1->afficher()));
                                LitAff.push(LitMng.addLitterale(L2->afficher()));
                                LitAff.setMessage("Erreur : Opération impossible le deuxième élément");
                                return;
                            }
                            if(estUneExpression(L1->afficher())){    // C'est pas mon taff c'est celui de commandeEX
                                LitAff.push(LitMng.addLitterale(L1->afficher()));
                                LitAff.push(LitMng.addLitterale(L2->afficher()));
                                commandeP(c);
                                return;
                            }
                        }
                    }

                    if(LitAff.getNbLitterale()>=1&&estUnOperateur1(c)){

                        if(c=="NEG") negationne(L2);
                        if(c=="NUM") Numerateur(L2);
                        if(c=="DEN" ) Denominateur(L2);

                        if(c=="RE"){

                            if(estUnComplexe(L2->afficher()))Reelise(L2);
                            else LitAff.setMessage("Opération impossible ce n'est pas un complexe");
                        }
                        if(c=="IM"){

                            if(estUnComplexe(L2->afficher()))Imagine(L2);
                            else LitAff.setMessage("Opération impossible ce n'est pas un complexe");
                        }

                        return ; // j'ai fini tout bien
                    }
                    qDebug("Si je suis la j'ai riens reconnu");
                    // si on arrive ici c'est pas ouf
                    //LitAff.push(LitMng.addLitterale(L2->afficher()));
                    LitAff.setMessage("Opération impossible sur cet/ces éléments");
                }
                // faire le cas d'opérateur sur la pile, opérateurs logiques
            }else{
               if(estUnProgramme(L2->afficher())){
                   LitAff.pop();
                   LitAff.setMessage("Erreur : Opération impossible sur le premier");
                   LitAff.push(LitMng.addLitterale(L2->afficher()));
                   return;
               }
               if(estUneExpression(L2->afficher())){
                   LitAff.pop();
                   LitAff.push(LitMng.addLitterale(L2->afficher()));
                   commandeP(c);
                   return;
               }

            }


        }  */

        if(faire.contains(c)){

            faire[c]->operator ()();
        }else{

            LitAff.setMessage("Erreur : commande inconnue");

        }
    }
}

