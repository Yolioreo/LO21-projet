#ifndef QCOMPUTER
#define QCOMPUTER
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QSlider>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QDebug>
#include "computer.h"

class QComputer : public QWidget{

    Q_OBJECT
  //Widget gérant les onglets calculatrice, variable, programme
  QTabWidget* onglets;
  //widget affichant les message d'erreur
    QLineEdit* message;
    //widget permettant d'afficher la pile
    QTableWidget* vuePile;
    //widget où l'utilisateur entre ses commandes
    QLineEdit* commande;


    QVBoxLayout* Variables;
    QVBoxLayout* Programmes;




    QVBoxLayout* couche;
    //pile dans laquelle on stockent les littéraux
    Pile* pile;
    LitteraleManager* Manager;
    //gére les opérations
    Controleur* controleur;

    QVBoxLayout Fini,ligne1,ligne2,ligne3,finalC,op;
    QHBoxLayout chiffre,Compo,Parenthese,entre;

    //bouton clavier chiffres et opérateurs
    QPushButton* button0;
    QPushButton* button1;
    QPushButton* button2;
    QPushButton* button3;
    QPushButton* button4;
    QPushButton* button5;
    QPushButton* button6;
    QPushButton* button7;
    QPushButton* button8;
    QPushButton* button9;
    QPushButton* buttonP;
    QPushButton* buttonM;
    QPushButton* buttonF;
    QPushButton* buttonD;
    QPushButton* button$;
    QPushButton* buttonE;
    QPushButton* buttonA;
    QPushButton* buttonPG;
    QPushButton* buttonPD;
    QPushButton* buttonG;
    QPushButton* buttonES;
    QPushButton* buttonBS;



public:
    explicit QComputer(QWidget *parent = 0);
    virtual ~QComputer();
public slots:
    void ajoute_chiffre();
    void refresh();
    void getNextCommande();
};


#endif // QCOMPUTER
