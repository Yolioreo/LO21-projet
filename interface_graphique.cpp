#include "interface_graphique.h"
#include <QStringList>
#include <QDebug>

Ui::MainWindow::MainWindow(QWidget *parent=0){
  pile=new Pile;
  Manager=new LitteraleManager;
  controleur =&Controleur::getInstance(*Manager,*pile);

}

void Ui::MainWindow::refresh(){


    wAffichageErreur->setText(pile->getMessage());


    for(unsigned int i=0;i<pile->getNbLitteraleToAffiche();i++)
        wAffichagePil->item(i,0)->setText("");


    unsigned int nb=0;
    for (Litterale** it=pile->PileLit.begin();(it!=pile->PileLit.end()&&(nb<(pile->getNbLitteraleToAffiche())));++it){
       wAffichagePil->item(pile->getNbLitteraleToAffiche()-nb-1,0)->setText((*it)->afficher());
        nb++;
    }


}
void Ui::MainWindow::getNextCommande(){
    pile->setMessage("");

    QString c=wAffichageCommande->text();
    QTextStream stream(&c);
    QString com;
    stream>>com;
    if(estUneExpression(c)&&(!estUneExpression(com)))controleur->commande(c);
    if(estUnProgramme(c)&&(!estUnProgramme(com)))controleur->commande(c);
    stream<<com;
    if (c!=""){


        do{
            stream>>com;
            if (com!="")controleur->commande(com);
        }while(com!="");


    }
    else pile->setMessage("Pas d'argument à interpréter");
    wAffichageCommande->clear();

}
void Ui::MainWindow::connections(){

    QObject::connect(wAffichageCommande,SIGNAL(returnPressed()),this,SLOT(getNextCommande()));
    QObject::connect(boutonEntree,SIGNAL(clicked()),this,SLOT(getNextCommande()));

    // correspondance entre les chiffre et les caractère
    QObject::connect(bouton0,SIGNAL(clicked()),this,SLOT(ajoute_text()));
    QObject::connect(bouton1,SIGNAL(clicked()),this,SLOT(ajoute_text()));
    QObject::connect(bouton2,SIGNAL(clicked()),this,SLOT(ajoute_text()));
    QObject::connect(bouton3,SIGNAL(clicked()),this,SLOT(ajoute_text()));
    QObject::connect(bouton4,SIGNAL(clicked()),this,SLOT(ajoute_text()));
    QObject::connect(bouton5,SIGNAL(clicked()),this,SLOT(ajoute_text()));
    QObject::connect(bouton6,SIGNAL(clicked()),this,SLOT(ajoute_text()));
    QObject::connect(bouton7,SIGNAL(clicked()),this,SLOT(ajoute_text()));
    QObject::connect(bouton8,SIGNAL(clicked()),this,SLOT(ajoute_text()));
    QObject::connect(bouton9,SIGNAL(clicked()),this,SLOT(ajoute_text()));
    QObject::connect(boutonP,SIGNAL(clicked()),this,SLOT(ajoute_text()));
    QObject::connect(boutonM,SIGNAL(clicked()),this,SLOT(ajoute_text()));
    QObject::connect(boutonF,SIGNAL(clicked()),this,SLOT(ajoute_text()));
    QObject::connect(boutonComplexe,SIGNAL(clicked()),this,SLOT(ajoute_text()));
    QObject::connect(boutonD,SIGNAL(clicked()),this,SLOT(ajoute_text()));


    // actualisation de la pile
    QObject::connect(pile,SIGNAL(modificationEtat()),this,SLOT(refresh()));
}

void Ui::MainWindow::ajoute_text(){

    QPushButton* btn = qobject_cast<QPushButton*>(sender());

        if(btn==nullptr) {
            return;
        }
        if(btn->text()=="ESPACE") wAffichageCommande->insert(" ");
        else{
        wAffichageCommande->insert(btn->text());

        }
}
