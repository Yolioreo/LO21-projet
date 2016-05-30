#include "operande.h"
#include "computer.h"
#include "interface_graphique.h"

void addition::additionExpression(Litterale* L1,Litterale* L2){
  Controleur* controle=&Controleur::getInstance();
  QString retour;
  QString S1;
  QString S2;

  if (estUneExpression(L1->afficher())){
      S1=L1->afficher().left(L1->afficher().size()-1);
    }
  else{
      S1="'"+L1->afficher();
    }
  if (estUneExpression(L2->afficher())){
      S2=L2->afficher().right(L2->afficher().size()-1);
    }
  else{
      S2=L2->afficher()+"'";
    }

  retour=S1+"+"+S2;

  controle->push(controle->addLitterale(retour));
}


bool operande::verifierNumArite2(){

    bool test=false;
    Controleur* controle=&Controleur::getInstance();


    if(controle->getNbLitterale()<2){
        controle->setMessage("Erreur : Il n'y a pas d'argument dans la pile");
        return false;
    }

     Litterale* L2=controle->top();
     controle->pop();
     Litterale* L1=controle->top();
     controle->pop();


     if(estUnLitteraleNum(L1->afficher())||estUnComplexe(L1->afficher())||estUneExpression(L1->afficher())){ // test sur le 1er élément de la pile

            if(estUnLitteraleNum(L2->afficher())||estUnComplexe(L2->afficher())||estUneExpression(L2->afficher()))// test sur le 2ème élément de la pile
            test=true;
     }

     controle->push(L1);

     controle->push(L2);

     return test;


}

bool operande::verifierNumArite1(){

    bool test=false;
    Controleur* controle=&Controleur::getInstance();


    if(controle->getNbLitterale()<1){
        controle->setMessage("Erreur : Il n'y a pas d'argument dans la pile");
        return false;
    }

     Litterale* L2=controle->top();
     controle->pop();

     if(estUnLitteraleNum(L2->afficher())||estUnComplexe(L2->afficher())||estUneExpression(L2->afficher()))// test sur le 1er élément de la pile
        test=true;

     controle->push(L2);

     return test;


}

const QString operande::creationStringLitterale(int tempRN, int tempRD, int tempIN, int tempID){


    if(tempIN==0){ // c'est pas un complexe
        if(tempRD==1)// c'est pas un rationnel
        {
         return QString::number(tempRN);

        }
        else{

            return QString::number(tempRN)+"/"+QString::number(tempRD);


        }
    }else{

        if(tempRD==1)// c'est pas un rationnelR
        {

            if(tempID==1)// c'est pas un rationnelI
            {
             return QString::number(tempRN)+"$"+QString::number(tempIN);

            }
            else{
                return QString::number(tempRN)+"$"+QString::number(tempIN)+"/"+QString::number(tempID);

            }

        }
        else{

            if(tempID==1)// c'est pas un rationnelI
            {
             return QString::number(tempRN)+"/"+QString::number(tempRD)+"$"+QString::number(tempIN);

            }
            else{

               return QString::number(tempRN)+"/"+QString::number(tempRD)+"$"+QString::number(tempIN)+"/"+QString::number(tempID);

            }

        }

    }

}

void addition::operator() (){



            Controleur* controle=&Controleur::getInstance();
            double tempIN,tempID,tempRN,tempRD;
            QString a;

            if (!verifierNumArite2()){
                return;
            }
            qDebug("On est dans addition");

            Litterale* L2=controle->top();
            controle->pop();
            Litterale* L1=controle->top();
            controle->pop();



            //faire de le cas d'une expression
            if(estUneExpression(L1->afficher())||estUneExpression(L2->afficher())){
              this->additionExpression(L1,L2);
              return;
            }

            double RN1=L1->getRNumerateur();
            double RD1=L1->getRDenominateur();
            double IN1=L1->getINumerateur();
            double ID1=L1->getIDenominateur();

            double RN2=L2->getRNumerateur();
            double RD2=L2->getRDenominateur();
            double IN2=L2->getINumerateur();
            double ID2=L2->getIDenominateur();



            //partie reel
            tempRN=RN1*RD2+RN2*RD1;
            tempRD=RD1*RD2;
            //partie imaginaire
            tempIN=IN1*ID2+IN2*ID1;
            tempID=ID1*ID2;




            controle->push(controle->addLitterale(creationStringLitterale(tempRN,tempRD,tempIN,tempID)));







}
//*/

void soustraction::operator() (){



            Controleur* controle=&Controleur::getInstance();
            double tempIN,tempID,tempRN,tempRD;
            QString a;

            if (!verifierNumArite2()){
                return;
            }
            qDebug("On est dans addition");

            Litterale* L2=controle->top();
            controle->pop();
            Litterale* L1=controle->top();
            controle->pop();


            //faire de le cas d'une expression


            double RN1=L1->getRNumerateur();
            double RD1=L1->getRDenominateur();
            double IN1=L1->getINumerateur();
            double ID1=L1->getIDenominateur();

            double RN2=L2->getRNumerateur();
            double RD2=L2->getRDenominateur();
            double IN2=L2->getINumerateur();
            double ID2=L2->getIDenominateur();

            //partie reel
            tempRN=RN1*RD2-RN2*RD1;
            tempRD=RD1*RD2;
            //partie imaginaire
            tempIN=IN1*ID2-IN2*ID1;
            tempID=ID1*ID2;

            controle->push(controle->addLitterale(creationStringLitterale(tempRN,tempRD,tempIN,tempID)));
}

void multiplication::operator() (){



            Controleur* controle=&Controleur::getInstance();
            double tempIN,tempID,tempRN,tempRD;
            QString a;

            if (!verifierNumArite2()){
                return;
            }
            qDebug("On est dans addition");

            Litterale* L2=controle->top();
            controle->pop();
            Litterale* L1=controle->top();
            controle->pop();


            //faire de le cas d'une expression


            double RN1=L1->getRNumerateur();
            double RD1=L1->getRDenominateur();
            double IN1=L1->getINumerateur();
            double ID1=L1->getIDenominateur();

            double RN2=L2->getRNumerateur();
            double RD2=L2->getRDenominateur();
            double IN2=L2->getINumerateur();
            double ID2=L2->getIDenominateur();

            //partie reel
            tempRN=RN1*RN2*ID1*ID2-IN1*IN2*RD1*RD2;
            tempRD=RD1*RD2*ID1*ID2;
            //partie imaginaire
            tempIN=RN1*IN2*ID1*RD2+IN1*RN2*RD1*ID2;
            tempID=tempRD;

            controle->push(controle->addLitterale(creationStringLitterale(tempRN,tempRD,tempIN,tempID)));
}


void division::operator() (){



            Controleur* controle=&Controleur::getInstance();
            double tempIN,tempID,tempRN,tempRD;
            QString a;

            if (!verifierNumArite2()){
                return;
            }

            Litterale* L2=controle->top();
            controle->pop();
            Litterale* L1=controle->top();
            controle->pop();


            //faire de le cas d'une expression


            double RN1=L1->getRNumerateur();
            double RD1=L1->getRDenominateur();
            double IN1=L1->getINumerateur();
            double ID1=L1->getIDenominateur();

            double RN2=L2->getRNumerateur();
            double RD2=L2->getRDenominateur();
            double IN2=L2->getINumerateur();
            double ID2=L2->getIDenominateur();

            //partie reel
            tempRN=RD2*RD2*ID2*ID2*(RN2*RN1*ID1*ID2+IN1*IN2*RD1*RD2);
            tempRD=RD1*RD2*ID1*ID2*RN2*RN2*ID2*ID2+RD1*RD2*ID1*ID2*IN2*IN2*RD2*RD2;
            //partie imaginaire
            tempIN=RD2*RD2*ID2*ID2*IN1*RN2*RD1*ID2-RD2*RD2*ID2*ID2*RN1*IN2*ID1*RD2;
            tempID=tempRD;

            controle->push(controle->addLitterale(creationStringLitterale(tempRN,tempRD,tempIN,tempID)));

}

void complexise::operator ()(){

    Controleur* controle=&Controleur::getInstance();

    if (!verifierNumArite2()){
        return;
    }
    qDebug("On est dans la complexisation");

    Litterale* L2=controle->top();
    controle->pop();
    Litterale* L1=controle->top();
    controle->pop();
    QString a=L1->afficher()+"$"+L2->afficher();
    controle->push(controle->addLitterale(a));

}

void NEG::operator ()(){

    Controleur* controle=&Controleur::getInstance();

    if (!verifierNumArite1()){
        return;
    }
    qDebug("negation");

    Litterale* L2=controle->top();
    controle->pop();

    double RN2=L2->getRNumerateur();
    double RD2=L2->getRDenominateur();
    double IN2=L2->getINumerateur();
    double ID2=L2->getIDenominateur();

qDebug("negation");
    controle->push(controle->addLitterale(creationStringLitterale(-RN2,RD2,-IN2,ID2)));

}

void DEN::operator ()(){

    Controleur* controle=&Controleur::getInstance();

    if (!verifierNumArite1()){
        return;
    }
    qDebug("denumérateur");

    Litterale* L2=controle->top();
    controle->pop();
    double tempD;
    double RD2=L2->getRDenominateur();
    double ID2=L2->getIDenominateur();
    if (RD2!=ID2)
      tempD=RD2*ID2;
    else
      tempD=RD2;

qDebug("dénumérateur");
    controle->push(controle->addLitterale(creationStringLitterale(tempD,1,0,1)));

}

void NUM::operator ()(){

    Controleur* controle=&Controleur::getInstance();

    if (!verifierNumArite1()){
        return;
    }
    qDebug("numérateur");

    Litterale* L2=controle->top();
    controle->pop();

    double tempRN;
    double tempIN;
    double RN2=L2->getRNumerateur();
    double RD2=L2->getRDenominateur();
    double IN2=L2->getINumerateur();
    double ID2=L2->getIDenominateur();
    if (RD2==ID2){
      tempIN=IN2;
      tempRN=RN2;
      }
    else{
        tempIN=IN2*RD2;
        tempRN=RN2*ID2;
      }

qDebug("numérateur");
    controle->push(controle->addLitterale(creationStringLitterale(tempRN,1,tempIN,1)));

}

void DIV::operator() (){


            Controleur* controle=&Controleur::getInstance();
            QString a;
            qDebug("div");

            if (!verifierNumArite2()){
                return;
            }

            Litterale* L2=controle->top();
            controle->pop();
            Litterale* L1=controle->top();
            controle->pop();

            if (!estUnEntier(L1->afficher())||!estUnEntier(L2->afficher())){
                controle->push(L1);
                controle->push(L2);
                controle->setMessage("Impossible : division entière de littéraux non entier");
                return;
              }

            //faire de le cas d'une expression


            double E1=L1->getRNumerateur();

            double E2=L2->getRNumerateur();

            double resultatDIV=floor(E1/E2);

            controle->push(controle->addLitterale(creationStringLitterale(resultatDIV,1,0,1)));
}

void MOD::operator() (){


            Controleur* controle=&Controleur::getInstance();
            QString a;
            qDebug("div");

            if (!verifierNumArite2()){
                return;
            }

            Litterale* L2=controle->top();
            controle->pop();
            Litterale* L1=controle->top();
            controle->pop();

            if (!estUnEntier(L1->afficher())||!estUnEntier(L2->afficher())){
                controle->push(L1);
                controle->push(L2);
                controle->setMessage("Impossible : modula de littéraux non entier");
                return;
              }

            //faire de le cas d'une expression


            int E1=L1->getRNumerateur();

            int E2=L2->getRNumerateur();

            int resultatMOD=E1%E2;

            controle->push(controle->addLitterale(creationStringLitterale(resultatMOD,1,0,1)));
}

void difference::operator() (){

            Controleur* controle=&Controleur::getInstance();
            int test;
            QString a;

            if (!verifierNumArite2()){
                return;
            }

            Litterale* L2=controle->top();
            controle->pop();
            Litterale* L1=controle->top();
            controle->pop();


            //faire de le cas d'une expression


            double RN1=L1->getRNumerateur();
            double RD1=L1->getRDenominateur();
            double IN1=L1->getINumerateur();
            double ID1=L1->getIDenominateur();

            double RN2=L2->getRNumerateur();
            double RD2=L2->getRDenominateur();
            double IN2=L2->getINumerateur();
            double ID2=L2->getIDenominateur();

            if((RN1!=RN2)||(RD1!=RD2)||(ID1!=ID2)||(IN1!=IN2))
              test=1;
            else
              test=0;

            controle->push(controle->addLitterale(creationStringLitterale(test,1,0,1)));

}

void egalite::operator() (){

            Controleur* controle=&Controleur::getInstance();
            int test;
            QString a;

            if (!verifierNumArite2()){
                return;
            }

            Litterale* L2=controle->top();
            controle->pop();
            Litterale* L1=controle->top();
            controle->pop();


            //faire de le cas d'une expression


            double RN1=L1->getRNumerateur();
            double RD1=L1->getRDenominateur();
            double IN1=L1->getINumerateur();
            double ID1=L1->getIDenominateur();

            double RN2=L2->getRNumerateur();
            double RD2=L2->getRDenominateur();
            double IN2=L2->getINumerateur();
            double ID2=L2->getIDenominateur();

            if((RN1==RN2)&&(RD1==RD2)&&(ID1==ID2)&&(IN1==IN2))
              test=1;
            else
              test=0;

            controle->push(controle->addLitterale(creationStringLitterale(test,1,0,1)));

}

void inferieur::operator() (){

            Controleur* controle=&Controleur::getInstance();
            int test;
            QString a;

            if (!verifierNumArite2()){
                return;
            }

            Litterale* L2=controle->top();
            controle->pop();
            Litterale* L1=controle->top();
            controle->pop();

            if (estUnComplexe(L2->afficher())||estUnComplexe(L1->afficher())){
                controle->push(L1);
                controle->push(L2);
                controle->setMessage("Impossible : comparaison de complexe");
                return;
              }


            //faire de le cas d'une expression


            double RN1=L1->getRNumerateur();
            double RD1=L1->getRDenominateur();

            double RN2=L2->getRNumerateur();
            double RD2=L2->getRDenominateur();

            if((RN1/RD1)<(RN2/RD2))
              test=1;
            else
              test=0;

            controle->push(controle->addLitterale(creationStringLitterale(test,1,0,1)));

}

void superieur::operator() (){

            Controleur* controle=&Controleur::getInstance();
            int test;
            QString a;

            if (!verifierNumArite2()){
                return;
            }

            Litterale* L2=controle->top();
            controle->pop();
            Litterale* L1=controle->top();
            controle->pop();

            if (estUnComplexe(L2->afficher())||estUnComplexe(L1->afficher())){
                controle->push(L1);
                controle->push(L2);
                return;
              }


            //faire de le cas d'une expression


            double RN1=L1->getRNumerateur();
            double RD1=L1->getRDenominateur();

            double RN2=L2->getRNumerateur();
            double RD2=L2->getRDenominateur();

            if((RN1/RD1)>(RN2/RD2))
              test=1;
            else
              test=0;

            controle->push(controle->addLitterale(creationStringLitterale(test,1,0,1)));

}

void inferieurOuEgale::operator() (){

            Controleur* controle=&Controleur::getInstance();
            int test;
            QString a;

            if (!verifierNumArite2()){
                return;
            }

            Litterale* L2=controle->top();
            controle->pop();
            Litterale* L1=controle->top();
            controle->pop();

            if (estUnComplexe(L2->afficher())||estUnComplexe(L1->afficher())){
                controle->push(L1);
                controle->push(L2);
                controle->setMessage("Impossible : comparaison de complexe");
                return;
              }


            //faire de le cas d'une expression


            double RN1=L1->getRNumerateur();
            double RD1=L1->getRDenominateur();

            double RN2=L2->getRNumerateur();
            double RD2=L2->getRDenominateur();

            if((RN1/RD1)<=(RN2/RD2))
              test=1;
            else
              test=0;

            controle->push(controle->addLitterale(creationStringLitterale(test,1,0,1)));

}

void superieurOuEgale::operator() (){

            Controleur* controle=&Controleur::getInstance();
            int test;
            QString a;

            if (!verifierNumArite2()){
                return;
            }

            Litterale* L2=controle->top();
            controle->pop();
            Litterale* L1=controle->top();
            controle->pop();

            if (estUnComplexe(L2->afficher())||estUnComplexe(L1->afficher())){
                controle->push(L1);
                controle->push(L2);
                controle->setMessage("Impossible : comparaison de complexe");
                return;
              }


            //faire de le cas d'une expression


            double RN1=L1->getRNumerateur();
            double RD1=L1->getRDenominateur();

            double RN2=L2->getRNumerateur();
            double RD2=L2->getRDenominateur();

            if((RN1/RD1)>=(RN2/RD2))
              test=1;
            else
              test=0;

            controle->push(controle->addLitterale(creationStringLitterale(test,1,0,1)));

}

void AND::operator() (){

            Controleur* controle=&Controleur::getInstance();
            int test;
            QString a;

            if (!verifierNumArite2()){
                return;
            }

            Litterale* L2=controle->top();
            controle->pop();
            Litterale* L1=controle->top();
            controle->pop();


            //faire de le cas d'une expression


            double RN1=L1->getRNumerateur();
            double IN1=L1->getINumerateur();

            double RN2=L2->getRNumerateur();
            double IN2=L2->getINumerateur();

            if(((RN1==0)&&(IN1==0))||((RN2==0)&&(IN2==0)))
              test=0;
            else
              test=1;

            controle->push(controle->addLitterale(creationStringLitterale(test,1,0,1)));

}

void OR::operator() (){

            Controleur* controle=&Controleur::getInstance();
            int test;
            QString a;

            if (!verifierNumArite2()){
                return;
            }

            Litterale* L2=controle->top();
            controle->pop();
            Litterale* L1=controle->top();
            controle->pop();


            //faire de le cas d'une expression


            double RN1=L1->getRNumerateur();
            double IN1=L1->getINumerateur();

            double RN2=L2->getRNumerateur();
            double IN2=L2->getINumerateur();

            if(((RN1==0)&&(IN1==0))&&((RN2==0)&&(IN2==0)))
              test=0;
            else
              test=1;

            controle->push(controle->addLitterale(creationStringLitterale(test,1,0,1)));

}

void NOT::operator() (){

            Controleur* controle=&Controleur::getInstance();
            int test;
            QString a;

            if (!verifierNumArite1()){
                return;
            }

            Litterale* L1=controle->top();
            controle->pop();

            //faire de le cas d'une expression


            double RN1=L1->getRNumerateur();
            double IN1=L1->getINumerateur();

            if(((RN1==0)&&(IN1==0)))
              test=1;
            else
              test=0;

            controle->push(controle->addLitterale(creationStringLitterale(test,1,0,1)));

}

void dup::operator ()(){

    Controleur* controle=&Controleur::getInstance();

    if(controle->getNbLitterale()<1) {
        controle->setMessage("Pas assez d'arguments pour l'opération");
    }
    qDebug("On est dans la duplication");



    controle->push(controle->addLitterale(controle->top()->afficher()));

}

void drop::operator ()(){

    Controleur* controle=&Controleur::getInstance();

    if(controle->getNbLitterale()<1) {
        controle->setMessage("Pas assez d'arguments pour l'opération");
        return;
    }
    qDebug("On est dans la dropisation");


    controle->pop();


}

void Swap::operator ()(){

    Controleur* controle=&Controleur::getInstance();

    if(controle->getNbLitterale()<2) {
        controle->setMessage("Pas assez d'arguments pour l'opération");
        return;
    }
    qDebug("On est dans la dropisation");


    Litterale* L2=controle->top();
    controle->pop();
    Litterale* L1=controle->top();
    controle->pop();

    controle->push(controle->addLitterale(L2->afficher()));
    controle->push(controle->addLitterale(L1->afficher()));


}
void clear::operator ()(){

    Controleur* controle=&Controleur::getInstance();


    qDebug("On est dans la clearisation");


    while(controle->getNbLitterale()>0){
        controle->pop();

    }
}
void lastop::operator ()(){

    Controleur* controle=&Controleur::getInstance();


    qDebug("On est dans la réutilisation du dernier opérateur");
    if(controle->getLastOperande()==""){
        controle->setMessage("Il n'y a pas eu d'opérateur avant celui-là");
        return;
    }
    controle->commande(controle->getLastOperande());
}
