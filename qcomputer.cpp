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



    QLineEdit instruction(this);
    instruction.setMaxLength(180);

    QPushButton* button0=new QPushButton("0",this);
    QPushButton* button1=new QPushButton("1",this);
    QPushButton* button2=new QPushButton("2",this);
    QPushButton* button3=new QPushButton("3",this);
    QPushButton* button4=new QPushButton("4",this);
    QPushButton* button5=new QPushButton("5",this);
    QPushButton* button6=new QPushButton("6",this);
    QPushButton* button7=new QPushButton("7",this);
    QPushButton* button8=new QPushButton("8",this);
    QPushButton* button9=new QPushButton("9",this);
    QPushButton* buttonP=new QPushButton("+",this);
    QPushButton* buttonM=new QPushButton("-",this);
    QPushButton* buttonF=new QPushButton("*",this);
    QPushButton* buttonD=new QPushButton("/",this);
    QPushButton* button$=new QPushButton("$",this);
    QPushButton* buttonE=new QPushButton("Entrée",this);
    QPushButton* buttonA=new QPushButton("Annuler",this);

    button0->setFixedSize(90,30);
    button1->setFixedSize(30,30);
    button2->setFixedSize(30,30);
    button3->setFixedSize(30,30);
    button4->setFixedSize(30,30);
    button5->setFixedSize(30,30);
    button6->setFixedSize(30,30);
    button7->setFixedSize(30,30);
    button8->setFixedSize(30,30);
    button9->setFixedSize(30,30);
    buttonE->setFixedSize(80,40);

    ligne1.addWidget(button7);
    ligne1.addWidget(button4);
    ligne1.addWidget(button1);

    ligne2.addWidget(button8);
    ligne2.addWidget(button5);
    ligne2.addWidget(button2);

    ligne3.addWidget(button9);
    ligne3.addWidget(button6);
    ligne3.addWidget(button3);

      chiffre.addLayout(&ligne1);
    chiffre.addLayout(&ligne2);
    chiffre.addLayout(&ligne3);

    finalC.addLayout(&chiffre);
    finalC.addWidget(button0);


    op.addWidget(buttonP);
    op.addWidget(buttonM);
    op.addWidget(buttonF);
    op.addWidget(buttonD);
    op.addWidget(button$);

    op.addWidget(buttonE);
    op.addWidget(buttonA);


    Compo.addLayout(&finalC);
    Compo.addLayout(&op);

    Fini.addWidget(&instruction);
    Fini.addLayout(&Compo);
    couche->addLayout(&Fini);


    connect(commande,SIGNAL(returnPressed()),this,SLOT(getNextCommande()));

    connect(pile,SIGNAL(modificationEtat()),this,SLOT(refresh()));



}
QComputer::~QComputer(){

    qDebug()<< "Destruction";
    delete controleur;
    delete pile;

}
void QComputer::refresh(){


    message->setText(pile->getMessage());


    for(unsigned int i=0;i<pile->getNbLitteraleToAffiche();i++)
        vuePile->item(i,0)->setText("");


    unsigned int nb=0;
    for (Litterale* it=pile->PileLit.begin();(it!=pile->PileLit.end()&&(nb<(pile->getNbLitteraleToAffiche())));++it){
       vuePile->item(pile->getNbLitteraleToAffiche()-nb-1,0)->setText(it->afficher());
        nb++;
    }
    qDebug()<< "Ta mere suce";

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
