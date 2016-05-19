#include "qcomputer.h"
#include <QStringList>
#include <QDebug>
QComputer::QComputer(QWidget* parent):QWidget(parent){

    this->setWindowTitle("Calculatrice"); //retranscrit

    pile= new Pile;
    Manager=new LitteraleManager;

    controleur =&Controleur::getInstance(*Manager,*pile);

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

    button0=new QPushButton("0",this);
    button1=new QPushButton("1",this);
    button2=new QPushButton("2",this);
    button3=new QPushButton("3",this);
    button4=new QPushButton("4",this);
    button5=new QPushButton("5",this);
    button6=new QPushButton("6",this);
    button7=new QPushButton("7",this);
    button8=new QPushButton("8",this);
    button9=new QPushButton("9",this);
    buttonP=new QPushButton("+",this);
    buttonM=new QPushButton("-",this);
    buttonF=new QPushButton("*",this);
    buttonD=new QPushButton("/",this);
    button$=new QPushButton("$",this);
    buttonE=new QPushButton("Entrée",this);
    buttonA=new QPushButton("Annuler",this);
    buttonPG=new QPushButton("[",this);
    buttonPD=new QPushButton("]",this);
    buttonG=new QPushButton("'",this);
    buttonES=new QPushButton("ESPACE",this);
    buttonBS=new QPushButton("BACKSPACE",this);


    button0->setFixedSize(40,40);
    button1->setFixedSize(40,40);
    button2->setFixedSize(40,40);
    button3->setFixedSize(40,40);
    button4->setFixedSize(40,40);
    button5->setFixedSize(40,40);
    button6->setFixedSize(40,40);
    button7->setFixedSize(40,40);
    button8->setFixedSize(40,40);
    button9->setFixedSize(40,40);
    buttonE->setFixedSize(80,40);
    buttonA->setFixedSize(80,40);
    buttonBS->setFixedSize(40,40);

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

    Parenthese.addWidget(buttonPG);

    Parenthese.addWidget(buttonPD);
    op.addWidget(buttonP);
    op.addWidget(buttonM);
    op.addWidget(buttonF);
    op.addWidget(buttonD);
    op.addWidget(button$);

    op.addLayout(&Parenthese);
    op.addWidget(buttonG);
    entre.addWidget(buttonE);
    entre.addWidget(buttonA);
    op.addLayout(&entre);
    op.addWidget(buttonES);

    Compo.addLayout(&finalC);
    Compo.addLayout(&op);

    Fini.addWidget(&instruction);
    Fini.addLayout(&Compo);
    couche->addLayout(&Fini);

    // Entrée par touche ou  clavier
    connect(commande,SIGNAL(returnPressed()),this,SLOT(getNextCommande()));
    connect(buttonE,SIGNAL(clicked()),this,SLOT(getNextCommande()));

    // correspondance entre les chiffre et les caractère
    connect(button0,SIGNAL(clicked()),this,SLOT(ajoute_chiffre()));
    connect(button1,SIGNAL(clicked()),this,SLOT(ajoute_chiffre()));
    connect(button2,SIGNAL(clicked()),this,SLOT(ajoute_chiffre()));
    connect(button3,SIGNAL(clicked()),this,SLOT(ajoute_chiffre()));
    connect(button4,SIGNAL(clicked()),this,SLOT(ajoute_chiffre()));
    connect(button5,SIGNAL(clicked()),this,SLOT(ajoute_chiffre()));
    connect(button6,SIGNAL(clicked()),this,SLOT(ajoute_chiffre()));
    connect(button7,SIGNAL(clicked()),this,SLOT(ajoute_chiffre()));
    connect(button8,SIGNAL(clicked()),this,SLOT(ajoute_chiffre()));
    connect(button9,SIGNAL(clicked()),this,SLOT(ajoute_chiffre()));
    connect(buttonP,SIGNAL(clicked()),this,SLOT(ajoute_chiffre()));
    connect(buttonM,SIGNAL(clicked()),this,SLOT(ajoute_chiffre()));
    connect(buttonF,SIGNAL(clicked()),this,SLOT(ajoute_chiffre()));
    connect(button$,SIGNAL(clicked()),this,SLOT(ajoute_chiffre()));
    connect(buttonD,SIGNAL(clicked()),this,SLOT(ajoute_chiffre()));
    connect(buttonPD,SIGNAL(clicked()),this,SLOT(ajoute_chiffre()));
    connect(buttonPG,SIGNAL(clicked()),this,SLOT(ajoute_chiffre()));
    connect(buttonG,SIGNAL(clicked()),this,SLOT(ajoute_chiffre()));

    // actualisation de la pile
    connect(pile,SIGNAL(modificationEtat()),this,SLOT(refresh()));


    //connect(controleur,SIGNAL(jeconnaispas(QString&)),pile,SLOT(affiche(QString&))





}
QComputer::~QComputer(){

    delete pile;
    Controleur::libererInstance();
}
void QComputer::refresh(){


    message->setText(pile->getMessage());


    for(unsigned int i=0;i<pile->getNbLitteraleToAffiche();i++)
        vuePile->item(i,0)->setText("");


    unsigned int nb=0;
    for (Litterale** it=pile->PileLit.begin();(it!=pile->PileLit.end()&&(nb<(pile->getNbLitteraleToAffiche())));++it){
       vuePile->item(pile->getNbLitteraleToAffiche()-nb-1,0)->setText((*it)->afficher());
        nb++;
    }


}
void QComputer::getNextCommande(){
    pile->setMessage("");

    QString c=commande->text();
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
    commande->clear();

}

void QComputer::ajoute_chiffre(){

    QPushButton* btn = qobject_cast<QPushButton*>(sender());

        if(btn==nullptr) {
            return;
        }
        if(btn->text()=="ESPACE") commande->insert(" ");
        else{
        commande->insert(btn->text());

        }
}

