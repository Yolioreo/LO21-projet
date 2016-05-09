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
    QLineEdit* message;
    QTableWidget* vuePile;
    QLineEdit* commande;
    QVBoxLayout* couche;
    Pile* pile;
    Controleur* controleur;

    QVBoxLayout Fini,ligne1,ligne2,ligne3,finalC,op;
    QHBoxLayout chiffre,Compo;

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



public:
    explicit QComputer(QWidget *parent = 0);
    virtual ~QComputer();
public slots:
    void refresh();
    void getNextCommande();
};


#endif // QCOMPUTER
