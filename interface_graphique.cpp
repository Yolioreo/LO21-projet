#include "interface_graphique.h"


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

void Ui::MainWindow::afficheProgramme(){
  qDebug("dans le afficheProgramme!");
  GereurOnglet->setCurrentIndex(GereurOnglet->currentIndex()+2);
  Litterale* L=controleur->top();
  controleur->pop();

  qDebug()<<L->afficher();
  wAffichageProgramme->setPlainText(L->afficher());
}

void Ui::MainWindow::sendProgrammePile(){
  controleur->push(controleur->addLitterale(wAffichageProgramme->toPlainText()));
  wAffichageProgramme->setPlainText("");
  GereurOnglet->setCurrentIndex(GereurOnglet->currentIndex()-2);
}

void Ui::MainWindow::getNextCommande(){
    pile->setMessage("");
    QString c=wAffichageCommande->text();
    QTextStream stream(&c);
    QString com;

    if(c==""){
        pile->setMessage("Pas d'argument à interpréter");
        return;
    }
    if(estUneExpression(c)){
        controleur->commande(c);
        wAffichageCommande->clear();
        return;
    }
    if(estUnProgramme(c)){
        controleur->commande(c);
        wAffichageCommande->clear();
        return ;
    }



    do{
        stream>>com;

        if (com!="")controleur->commande(com);
    }while(com!="");


    wAffichageCommande->clear();
}

void Ui::MainWindow::refresh(){
    Controleur* controle=&Controleur::getInstance();

    wAffichageErreur->setText(pile->getMessage());   
    for(unsigned int i=0;i<pile->getNbLitteraleToAffiche();i++)
        wAffichagePil->item(i,0)->setText("");


    unsigned int nb=0;
    for (Pile::iterator it=pile->begin();(it!=pile->end()&&(nb<pile->getNbLitteraleToAffiche()));++it){
       wAffichagePil->item(pile->getNbLitteraleToAffiche()-nb-1,0)->setText((*it)->afficher());
        nb++;
    }
    int nb1=0;
    TableauVarAffi->setRowCount(controle->getNbVariable());
    for(unsigned int i=0;i<controle->getNbVariable();i++){
        TableauVarAffi->setItem(i,0,new QTableWidgetItem(""));
        TableauVarAffi->setItem(i,1,new QTableWidgetItem(""));
      }

    for (QMap<Atome *, Litterale*>::const_iterator it = controle->getVar().cbegin(); it != controle->getVar().cend(); it++){
       TableauVarAffi->item(nb1,0)->setText(it.key()->afficher());
       TableauVarAffi->item(nb1,1)->setText(it.value()->afficher());

       nb1++;
    }

}

void Ui::MainWindow::connections(){

  //affichage optionel du clavier
  actionAffichage_clavier->setCheckable(true);
  connect(actionAffichage_clavier, SIGNAL(toggled(bool)), wClavier, SLOT(affichageClavier(bool)));
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

  //bip sonore
  actionActivation_Bip_Sonore->setCheckable(true);
  //SactionActivation_Bip_Sonore->setChecked(false);
  connect(pile,SIGNAL(bipsonore()),this,SLOT(bip_sonore()));

  //affichage des erreurs
  wAffichageErreur->setReadOnly(true);
  wAffichageErreur->setStyleSheet("background : black, color : white");

  //envoie des commandes avec entrée
  connect(wAffichageCommande,SIGNAL(returnPressed()),this,SLOT(getNextCommande()));
  connect(boutonEntree,SIGNAL(clicked()),this,SLOT(getNextCommande()));

  // actualisation de la pile
  connect(pile,SIGNAL(modificationEtat()),this,SLOT(refresh()));
  //connect(controleur,SIGNAL(modificationEtat()),this,SLOT(refresh()));

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
  connect(boutonPoint,SIGNAL(clicked()),wAffichageCommande,SLOT(ajoute_commande()));
  connect(boutonGuillemet,SIGNAL(clicked()),wAffichageCommande,SLOT(ajoute_commande()));
  connect(boutonParentheseO,SIGNAL(clicked()),wAffichageCommande,SLOT(ajoute_commande()));
  connect(boutonParentheseF,SIGNAL(clicked()),wAffichageCommande,SLOT(ajoute_commande()));
  connect(boutonBS,SIGNAL(clicked()),wAffichageCommande,SLOT(slotBackspace()));
  connect(boutonEspace,SIGNAL(clicked()),wAffichageCommande,SLOT(slotSpace()));



  // chargement contexte

  //connect(pile,SIGNAL(chargementcontexte()),&XML,SLOT(charger_contexte()));
//sauvegarde contexte
    //connect(bouton0,SIGNAL(clicked()),&XML,SLOT(enregistrer_contexte()));

  //edit programme
  connect(controleur,SIGNAL(sendPrgm()),this,SLOT(afficheProgramme()));
  connect(sendProgram,SIGNAL(clicked()),this,SLOT(sendProgrammePile()));


  //clavier operateur numerique
  connect(boutonP,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonM,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonF,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonComplexe,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonD,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonDIV,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonNEG,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonNUM,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonDEN,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonIM,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonRE,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonMOD,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));

  //clavier operateur exp et prgm
  connect(boutonSTO,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonEVAL,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonEDIT,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));


  //clavier operateur logique
  connect(boutonEgalite,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonDIFF,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonINF,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonSUP,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonINFEG,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonSUPEG,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonAND,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonOR,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonNOT,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));

  //clavier opérateur pile
  connect(boutonUNDO,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonREDO,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonCLEAR,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonSWAP,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonLAST_OP,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));
  connect(boutonLAST_ARGS,SIGNAL(clicked()),getControleur(),SLOT(slotOperator()));


  //afficahge variable
  TableauVarAffi->setRowCount(controleur->getNbVariable());
  TableauVarAffi->setColumnCount(2);
  for(unsigned int i=0;i<controleur->getNbVariable();i++){
      TableauVarAffi->setItem(i,0,new QTableWidgetItem(""));
      TableauVarAffi->setItem(i,1,new QTableWidgetItem(""));
    }

  TableauVarAffi->setEditTriggers(QAbstractItemView::DoubleClicked);
  TableauVarAffi->horizontalHeader()->setVisible(true);
  TableauVarAffi->horizontalHeader()->setStretchLastSection(true);
  TableauVarAffi->show();
  QApplication::beep();
  //QSound::play();
}

