#include "qcomputer.h"
#include <QStringList>
#include <QDebug>
QComputer::QComputer(QWidget* parent):QWidget(parent){

    this->setWindowTitle("Calculatrice");

    pile= new Pile;
    controleur =
    new Controleur(LitteraleManager::getInstance(),*pile);

    message = new QLineEdit(this);
    vuePile = new QTableWidget(pile->getNbLitteraleToAffiche(),1,this);


    for(unsigned int i=0;i<pile->getNbLitteraleToAffiche();i++){
        vuePile->setItem(i,0,new QTableWidgetItem(""));
        vuePile->item(i,0)->setBackground(Qt::red);
    }
    vuePile->horizontalHeader()->setVisible(false);
    vuePile->horizontalHeader()->setStretchLastSection(true);


    QStringList liste;
    for(unsigned int i=pile->getNbLitteraleToAffiche();i>0;i--){
       QString str=QString::number(i);
        str+=" :";
       liste << str;
    }
    vuePile->setVerticalHeaderLabels(liste);
    vuePile->setEditTriggers(QAbstractItemView::NoEditTriggers);


    commande = new QLineEdit(this);
    couche = new QVBoxLayout(this);


    couche->addWidget(message);
    couche->addWidget(vuePile);
    couche->addWidget(commande);

    message->setReadOnly(true);
    message->setStyleSheet("background: black; color : white");


    connect(commande,SIGNAL(returnPressed()),this,SLOT(getNextCommande()));

    connect(pile,SIGNAL(modificationEtat()),this,SLOT(refresh()));


}
QComputer::~QComputer(){

    delete controleur;
    delete pile;
}
void QComputer::refresh(){

    message->setText(pile->getMessage());


    for(unsigned int i=0;i<pile->getNbLitteraleToAffiche();i++)
        vuePile->item(i,0)->setText("");


    unsigned int nb=0;
    for (Pile::iterator it=pile->begin();it!=pile->end()&&nb<pile->getNbLitteraleToAffiche();++it){
        vuePile->item(pile->getLitteraleToAffiche()-nb-1,0)->setText((*it).toString());
        nb++;
    }

}
void QComputer::getNextCommande(){
    pile->setMessage("");

    QString c=commande->text();
    QTextStream stream(&c);
    QString com;

    do{
        stream>>com;
        if (com!="")controleur->commande(com);
    }while(com!="");



    commande->clear();
}
