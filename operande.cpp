#include "operande.h"
#include "computer.h"

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

QString operande::creationStringLitterale(int tempRN, int tempRD, int tempIN, int tempID){


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
