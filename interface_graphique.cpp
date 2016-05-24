#include "interface_graphique.h"
#include <QStringList>
#include <QDebug>



void CommandLine::ajoute_commande(){
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if(btn==nullptr) {
        return;
    }
    this->insert(btn->text());
}

void CommandLine::slotSpace(){
    this->insert(" ");
}

void CommandLine::slotBackspace(){
    this->backspace();
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

void Ui::MainWindow::connections(){

  //affichage optionel du clavier
  connect(actionAffichage_clavier, SIGNAL(triggered()), wClavier, SLOT(hide()));
  GereurOnglet->setCurrentIndex(0);

  //affichage de la pile
  wAffichagePil->setRowCount(pile->getNbLitteraleToAffiche());
  wAffichagePil->setColumnCount(1);
  for(unsigned int i=0;i<pile->getNbLitteraleToAffiche();i++){
      wAffichagePil->setItem(i,0,new QTableWidgetItem(""));
    }
  QStringList liste;
  for(unsigned int i=pile->getNbLitteraleToAffiche();i>0;i--){
     QString str=QString::number(i);
      str+=" :";
     liste << str;
  }
  wAffichagePil->setVerticalHeaderLabels(liste);
  wAffichagePil->setEditTriggers(QAbstractItemView::NoEditTriggers);
  wAffichagePil->horizontalHeader()->setVisible(false);
  wAffichagePil->horizontalHeader()->setStretchLastSection(true);
  wAffichagePil->show();

  //affichage des erreurs
  wAffichageErreur->setReadOnly(true);
  wAffichageErreur->setStyleSheet("background : black, color : white");

  //envoie des commandes avec entrée
  connect(wAffichageCommande,SIGNAL(returnPressed()),this,SLOT(getNextCommande()));
  connect(boutonEntree,SIGNAL(clicked()),this,SLOT(getNextCommande()));

  // actualisation de la pile
  connect(pile,SIGNAL(modificationEtat()),this,SLOT(refresh()));

  //connection clavier numérique
  connect(bouton0,SIGNAL(clicked()),wAffichageCommande,SLOT(ajoute_commande()));
  connect(bouton1,SIGNAL(clicked()),wAffichageCommande,SLOT(ajoute_commande()));
  connect(bouton2,SIGNAL(clicked()),wAffichageCommande,SLOT(ajoute_commande()));
  connect(bouton3,SIGNAL(clicked()),wAffichageCommande,SLOT(ajoute_commande()));
  connect(bouton4,SIGNAL(clicked()),wAffichageCommande,SLOT(ajoute_commande()));
  connect(bouton5,SIGNAL(clicked()),wAffichageCommande,SLOT(ajoute_commande()));
  connect(bouton6,SIGNAL(clicked()),wAffichageCommande,SLOT(ajoute_commande()));
  connect(bouton7,SIGNAL(clicked()),wAffichageCommande,SLOT(ajoute_commande()));
  connect(bouton8,SIGNAL(clicked()),wAffichageCommande,SLOT(ajoute_commande()));
  connect(bouton9,SIGNAL(clicked()),wAffichageCommande,SLOT(ajoute_commande()));
  connect(boutonBS,SIGNAL(clicked()),wAffichageCommande,SLOT(slotBackspace()));
  connect(boutonEspace,SIGNAL(clicked()),wAffichageCommande,SLOT(slotSpace()));

  //clavier operateur
//  connect(boutonP,SIGNAL(clicked()),this,SLOT(ajoute_commande()));
//  connect(boutonM,SIGNAL(clicked()),this,SLOT(ajoute_commande()));
//  connect(boutonF,SIGNAL(clicked()),this,SLOT(ajoute_commande()));
//  connect(boutonComplexe,SIGNAL(clicked()),this,SLOT(ajoute_commande()));
//  connect(boutonD,SIGNAL(clicked()),this,SLOT(ajoute_commande()));
//  connect(boutonDIV,SIGNAL(clicked()),this,SLOT(ajoute_commande()));
//  connect(boutonNEG,SIGNAL(clicked()),this,SLOT(ajoute_commande()));
//  connect(boutonNUM,SIGNAL(clicked()),this,SLOT(ajoute_commande()));
//  connect(boutonDEN,SIGNAL(clicked()),this,SLOT(ajoute_commande()));
//  connect(boutonIM,SIGNAL(clicked()),this,SLOT(ajoute_commande()));
//  connect(boutonRE,SIGNAL(clicked()),this,SLOT(ajoute_commande()));
}

