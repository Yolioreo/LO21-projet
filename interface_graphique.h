
#ifndef INTERFACE_GRAPHIQUETT5446_H
#define INTERFACE_GRAPHIQUETT5446_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QAbstractTableModel>
#include "computer.h"

QT_BEGIN_NAMESPACE

class CommandLine : public QLineEdit{
  Q_OBJECT
public :
  CommandLine(QWidget* parent=nullptr) : QLineEdit(parent){}
public slots :
  void ajoute_commande();
  void slotBackspace();
  void slotSpace();
};

class Clavier : public QWidget{
  Q_OBJECT
public :
  Clavier(QWidget* parent=nullptr) : QWidget(parent){}
public slots :
  void affichageClavier(bool checked){
    if(checked)
      this->show();
    else
      this->hide();
  }
};


class Ui_MainWindow
{
public:
    QAction *actionAffichage_clavier;
    QAction *actionActivation_Bip_Sonore;
    QAction *actionChanger_la_couleur;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QTabWidget *GereurOnglet;
    QWidget *CalculatriceTab;
    QGridLayout *gridLayout_2;
    QWidget *wCommandePile;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *wAffichageErreur;
    QTableWidget *wAffichagePil;
    CommandLine *wAffichageCommande;
    Clavier *wClavier;
    QGridLayout *gridLayout_4;
    QVBoxLayout *clavierOperateur;
    QHBoxLayout *clavierOperateurNumerique;
    QVBoxLayout *operateur1;
    QPushButton *boutonP;
    QPushButton *boutonM;
    QPushButton *boutonD;
    QPushButton *boutonF;
    QPushButton *boutonComplexe;
    QPushButton *boutonDIV;
    QVBoxLayout *operateur2;
    QPushButton *boutonNEG;
    QPushButton *boutonNUM;
    QPushButton *boutonDEN;
    QPushButton *boutonRE;
    QPushButton *boutonIM;
    QPushButton *boutonMOD;
    QVBoxLayout *operateurExpPrgm;
    QPushButton *boutonSTO;
    QPushButton *boutonEVAL;
    QPushButton *boutonEDIT;
    QVBoxLayout *operateurLogiqueLayout;
    QPushButton *boutonEgalite;
    QPushButton *boutonDIFF;
    QPushButton *boutonINF;
    QPushButton *boutonSUP;
    QPushButton *boutonINFEG;
    QPushButton *boutonSUPEG;
    QPushButton *boutonAND;
    QPushButton *boutonOR;
    QPushButton *boutonNOT;
    QVBoxLayout *operateurPileLayout;
    QPushButton *boutonUNDO;
    QPushButton *boutonREDO;
    QPushButton *boutonCLEAR;
    QPushButton *boutonSWAP;
    QPushButton *boutonLAST_OP;
    QPushButton *boutonLAST_ARGS;
    QVBoxLayout *clavierChiffre;
    QHBoxLayout *ligne123;
    QPushButton *bouton1;
    QPushButton *bouton2;
    QPushButton *bouton3;
    QHBoxLayout *ligne456;
    QPushButton *bouton4;
    QPushButton *bouton5;
    QPushButton *bouton6;
    QHBoxLayout *ligne789;
    QPushButton *bouton7;
    QPushButton *bouton8;
    QPushButton *bouton9;
    QHBoxLayout *ligne0BS;
    QPushButton *bouton0;
    QPushButton *boutonBS;
    QPushButton *boutonEspace;
    QHBoxLayout *caractereSpeciaux;
    QPushButton *boutonPoint;
    QPushButton *boutonGuillemet;
    QPushButton *boutonParentheseO;
    QPushButton *boutonParentheseF;
    QPushButton *boutonEntree;
    QWidget *VariableTab;
    QGridLayout *gridLayout_5;
    QTableWidget *TableauVarAffi;
    QWidget *ProgrammeTab;
    QGridLayout *gridLayout_6;
    QPlainTextEdit *wAffichageProgramme;
    QPushButton *sendProgram;
    QMenuBar *menubar;
    QMenu *menuOption;
    QMenu *menuOptions_d_affichage;
    QStatusBar *statusbar;


    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(710, 656);
        actionAffichage_clavier = new QAction(MainWindow);
        actionAffichage_clavier->setObjectName(QStringLiteral("actionAffichage_clavier"));
        actionActivation_Bip_Sonore = new QAction(MainWindow);
        actionActivation_Bip_Sonore->setObjectName(QStringLiteral("actionActivation_Bip_Sonore"));
        actionChanger_la_couleur = new QAction(MainWindow);
        actionChanger_la_couleur->setObjectName(QStringLiteral("actionChanger_la_couleur"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        GereurOnglet = new QTabWidget(centralwidget);
        GereurOnglet->setObjectName(QStringLiteral("GereurOnglet"));
        CalculatriceTab = new QWidget();
        CalculatriceTab->setObjectName(QStringLiteral("CalculatriceTab"));
        CalculatriceTab->setEnabled(true);
        CalculatriceTab->setAutoFillBackground(false);
        gridLayout_2 = new QGridLayout(CalculatriceTab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        wCommandePile = new QWidget(CalculatriceTab);
        wCommandePile->setObjectName(QStringLiteral("wCommandePile"));
        gridLayout = new QGridLayout(wCommandePile);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        wAffichageErreur = new QLineEdit(wCommandePile);
        wAffichageErreur->setObjectName(QStringLiteral("wAffichageErreur"));

        verticalLayout->addWidget(wAffichageErreur);

        wAffichagePil = new QTableWidget(wCommandePile);
        wAffichagePil->setObjectName(QStringLiteral("wAffichagePil"));

        verticalLayout->addWidget(wAffichagePil);

        wAffichageCommande = new CommandLine(wCommandePile);
        wAffichageCommande->setObjectName(QStringLiteral("wAffichageCommande"));

        verticalLayout->addWidget(wAffichageCommande);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_2->addWidget(wCommandePile, 0, 0, 1, 1);

        wClavier = new Clavier(CalculatriceTab);
        wClavier->setObjectName(QStringLiteral("wClavier"));
        wClavier->setEnabled(true);
        gridLayout_4 = new QGridLayout(wClavier);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        clavierOperateur = new QVBoxLayout();
        clavierOperateur->setObjectName(QStringLiteral("clavierOperateur"));
        clavierOperateurNumerique = new QHBoxLayout();
        clavierOperateurNumerique->setObjectName(QStringLiteral("clavierOperateurNumerique"));
        operateur1 = new QVBoxLayout();
        operateur1->setObjectName(QStringLiteral("operateur1"));
        boutonP = new QPushButton(wClavier);
        boutonP->setObjectName(QStringLiteral("boutonP"));

        operateur1->addWidget(boutonP);

        boutonM = new QPushButton(wClavier);
        boutonM->setObjectName(QStringLiteral("boutonM"));

        operateur1->addWidget(boutonM);

        boutonD = new QPushButton(wClavier);
        boutonD->setObjectName(QStringLiteral("boutonD"));

        operateur1->addWidget(boutonD);

        boutonF = new QPushButton(wClavier);
        boutonF->setObjectName(QStringLiteral("boutonF"));

        operateur1->addWidget(boutonF);

        boutonComplexe = new QPushButton(wClavier);
        boutonComplexe->setObjectName(QStringLiteral("boutonComplexe"));

        operateur1->addWidget(boutonComplexe);

        boutonDIV = new QPushButton(wClavier);
        boutonDIV->setObjectName(QStringLiteral("boutonDIV"));

        operateur1->addWidget(boutonDIV);


        clavierOperateurNumerique->addLayout(operateur1);

        operateur2 = new QVBoxLayout();
        operateur2->setObjectName(QStringLiteral("operateur2"));
        boutonNEG = new QPushButton(wClavier);
        boutonNEG->setObjectName(QStringLiteral("boutonNEG"));

        operateur2->addWidget(boutonNEG);

        boutonNUM = new QPushButton(wClavier);
        boutonNUM->setObjectName(QStringLiteral("boutonNUM"));

        operateur2->addWidget(boutonNUM);

        boutonDEN = new QPushButton(wClavier);
        boutonDEN->setObjectName(QStringLiteral("boutonDEN"));

        operateur2->addWidget(boutonDEN);

        boutonRE = new QPushButton(wClavier);
        boutonRE->setObjectName(QStringLiteral("boutonRE"));

        operateur2->addWidget(boutonRE);

        boutonIM = new QPushButton(wClavier);
        boutonIM->setObjectName(QStringLiteral("boutonIM"));

        operateur2->addWidget(boutonIM);

        boutonMOD = new QPushButton(wClavier);
        boutonMOD->setObjectName(QStringLiteral("boutonMOD"));

        operateur2->addWidget(boutonMOD);


        clavierOperateurNumerique->addLayout(operateur2);


        clavierOperateur->addLayout(clavierOperateurNumerique);


        gridLayout_4->addLayout(clavierOperateur, 1, 1, 1, 1);

        operateurLogiqueLayout = new QVBoxLayout();
        operateurLogiqueLayout->setObjectName(QStringLiteral("operateurLogiqueLayout"));
        boutonEgalite = new QPushButton(wClavier);
        boutonEgalite->setObjectName(QStringLiteral("boutonEgalite"));

        operateurLogiqueLayout->addWidget(boutonEgalite);

        boutonDIFF = new QPushButton(wClavier);
        boutonDIFF->setObjectName(QStringLiteral("boutonDIFF"));

        operateurLogiqueLayout->addWidget(boutonDIFF);

        boutonINF = new QPushButton(wClavier);
        boutonINF->setObjectName(QStringLiteral("boutonINF"));

        operateurLogiqueLayout->addWidget(boutonINF);

        boutonSUP = new QPushButton(wClavier);
        boutonSUP->setObjectName(QStringLiteral("boutonSUP"));

        operateurLogiqueLayout->addWidget(boutonSUP);

        boutonINFEG = new QPushButton(wClavier);
        boutonINFEG->setObjectName(QStringLiteral("boutonINFEG"));

        operateurLogiqueLayout->addWidget(boutonINFEG);

        boutonSUPEG = new QPushButton(wClavier);
        boutonSUPEG->setObjectName(QStringLiteral("boutonSUPEG"));

        operateurLogiqueLayout->addWidget(boutonSUPEG);

        boutonAND = new QPushButton(wClavier);
        boutonAND->setObjectName(QStringLiteral("boutonAND"));

        operateurLogiqueLayout->addWidget(boutonAND);

        boutonOR = new QPushButton(wClavier);
        boutonOR->setObjectName(QStringLiteral("boutonOR"));

        operateurLogiqueLayout->addWidget(boutonOR);

        boutonNOT = new QPushButton(wClavier);
        boutonNOT->setObjectName(QStringLiteral("boutonNOT"));

        operateurLogiqueLayout->addWidget(boutonNOT);


        gridLayout_4->addLayout(operateurLogiqueLayout, 1, 2, 1, 1);

        operateurPileLayout = new QVBoxLayout();
        operateurPileLayout->setObjectName(QStringLiteral("operateurPileLayout"));
        boutonUNDO = new QPushButton(wClavier);
        boutonUNDO->setObjectName(QStringLiteral("boutonUNDO"));

        operateurPileLayout->addWidget(boutonUNDO);

        boutonREDO = new QPushButton(wClavier);
        boutonREDO->setObjectName(QStringLiteral("boutonREDO"));

        operateurPileLayout->addWidget(boutonREDO);

        boutonCLEAR = new QPushButton(wClavier);
        boutonCLEAR->setObjectName(QStringLiteral("boutonCLEAR"));

        operateurPileLayout->addWidget(boutonCLEAR);

        boutonSWAP = new QPushButton(wClavier);
        boutonSWAP->setObjectName(QStringLiteral("boutonSWAP"));

        operateurPileLayout->addWidget(boutonSWAP);

        boutonLAST_OP = new QPushButton(wClavier);
        boutonLAST_OP->setObjectName(QStringLiteral("boutonLAST_OP"));

        operateurPileLayout->addWidget(boutonLAST_OP);

        boutonLAST_ARGS = new QPushButton(wClavier);
        boutonLAST_ARGS->setObjectName(QStringLiteral("boutonLAST_ARGS"));

        operateurPileLayout->addWidget(boutonLAST_ARGS);


        gridLayout_4->addLayout(operateurPileLayout, 1, 3, 1, 1);

        operateurExpPrgm = new QVBoxLayout();
        operateurExpPrgm->setObjectName(QStringLiteral("operateurExpPrgm"));
        boutonSTO = new QPushButton(wClavier);
        boutonSTO->setObjectName(QStringLiteral("boutonSTO"));

        operateurExpPrgm->addWidget(boutonSTO);

        boutonEVAL = new QPushButton(wClavier);
        boutonEVAL->setObjectName(QStringLiteral("boutonEVAL"));

        operateurExpPrgm->addWidget(boutonEVAL);

        boutonEDIT = new QPushButton(wClavier);
        boutonEDIT->setObjectName(QStringLiteral("boutonEDIT"));

        operateurExpPrgm->addWidget(boutonEDIT);

        gridLayout_4->addLayout(operateurExpPrgm, 1, 4, 1, 1);

        clavierChiffre = new QVBoxLayout();
        clavierChiffre->setObjectName(QStringLiteral("clavierChiffre"));
        ligne123 = new QHBoxLayout();
        ligne123->setObjectName(QStringLiteral("ligne123"));
        bouton1 = new QPushButton(wClavier);
        bouton1->setObjectName(QStringLiteral("bouton1"));

        ligne123->addWidget(bouton1);

        bouton2 = new QPushButton(wClavier);
        bouton2->setObjectName(QStringLiteral("bouton2"));

        ligne123->addWidget(bouton2);

        bouton3 = new QPushButton(wClavier);
        bouton3->setObjectName(QStringLiteral("bouton3"));

        ligne123->addWidget(bouton3);


        clavierChiffre->addLayout(ligne123);

        ligne456 = new QHBoxLayout();
        ligne456->setObjectName(QStringLiteral("ligne456"));
        bouton4 = new QPushButton(wClavier);
        bouton4->setObjectName(QStringLiteral("bouton4"));

        ligne456->addWidget(bouton4);

        bouton5 = new QPushButton(wClavier);
        bouton5->setObjectName(QStringLiteral("bouton5"));

        ligne456->addWidget(bouton5);

        bouton6 = new QPushButton(wClavier);
        bouton6->setObjectName(QStringLiteral("bouton6"));

        ligne456->addWidget(bouton6);


        clavierChiffre->addLayout(ligne456);

        ligne789 = new QHBoxLayout();
        ligne789->setObjectName(QStringLiteral("ligne789"));
        bouton7 = new QPushButton(wClavier);
        bouton7->setObjectName(QStringLiteral("bouton7"));

        ligne789->addWidget(bouton7);

        bouton8 = new QPushButton(wClavier);
        bouton8->setObjectName(QStringLiteral("bouton8"));

        ligne789->addWidget(bouton8);

        bouton9 = new QPushButton(wClavier);
        bouton9->setObjectName(QStringLiteral("bouton9"));

        ligne789->addWidget(bouton9);


        clavierChiffre->addLayout(ligne789);

        caractereSpeciaux = new QHBoxLayout();
        caractereSpeciaux->setObjectName(QStringLiteral("caractereSpeciaux"));
        boutonPoint = new QPushButton(wClavier);
        boutonPoint->setObjectName(QStringLiteral("boutonPoint"));

        caractereSpeciaux->addWidget(boutonPoint);

        boutonGuillemet = new QPushButton(wClavier);
        boutonGuillemet->setObjectName(QStringLiteral("boutonGuillemet"));

        caractereSpeciaux->addWidget(boutonGuillemet);

        boutonParentheseO = new QPushButton(wClavier);
        boutonParentheseO->setObjectName(QStringLiteral("boutonParentheseO"));

        caractereSpeciaux->addWidget(boutonParentheseO);

        boutonParentheseF = new QPushButton(wClavier);
        boutonParentheseF->setObjectName(QStringLiteral("boutonParentheseF"));

        caractereSpeciaux->addWidget(boutonParentheseF);

        clavierChiffre->addLayout(caractereSpeciaux);

        ligne0BS = new QHBoxLayout();
        ligne0BS->setObjectName(QStringLiteral("ligne0BS"));
        bouton0 = new QPushButton(wClavier);
        bouton0->setObjectName(QStringLiteral("bouton0"));
        bouton0->setEnabled(true);

        ligne0BS->addWidget(bouton0);

        boutonBS = new QPushButton(wClavier);
        boutonBS->setObjectName(QStringLiteral("boutonBS"));

        ligne0BS->addWidget(boutonBS);

        boutonEspace = new QPushButton(wClavier);
        boutonEspace->setObjectName(QStringLiteral("boutonBS"));

        ligne0BS->addWidget(boutonEspace);


        clavierChiffre->addLayout(ligne0BS);


        gridLayout_4->addLayout(clavierChiffre, 1, 0, 1, 1);

        boutonEntree = new QPushButton(wClavier);
        boutonEntree->setObjectName(QStringLiteral("boutonEntree"));
        boutonEntree->setMinimumSize(QSize(0, 52));

        gridLayout_4->addWidget(boutonEntree, 2, 0, 1, 1);


        gridLayout_2->addWidget(wClavier, 1, 0, 1, 1);

        GereurOnglet->addTab(CalculatriceTab, QString());
        VariableTab = new QWidget();
        VariableTab->setObjectName(QStringLiteral("VariableTab"));
        gridLayout_5 = new QGridLayout(VariableTab);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        TableauVarAffi = new QTableWidget(VariableTab);
        TableauVarAffi->setObjectName(QStringLiteral("TableauVarAffi"));

        gridLayout_5->addWidget(TableauVarAffi, 0, 0, 1, 1);

        GereurOnglet->addTab(VariableTab, QString());
        ProgrammeTab = new QWidget();
        ProgrammeTab->setObjectName(QStringLiteral("ProgrammeTab"));
        gridLayout_6 = new QGridLayout(ProgrammeTab);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        wAffichageProgramme = new QPlainTextEdit(ProgrammeTab);
        wAffichageProgramme->setObjectName(QStringLiteral("wAffichageProgramme"));
        sendProgram = new QPushButton(ProgrammeTab);
        sendProgram->setObjectName(QStringLiteral("sendProgram"));


        gridLayout_6->addWidget(wAffichageProgramme, 0, 0, 1, 1);
        gridLayout_6->addWidget(sendProgram,1,0,1,1);

        GereurOnglet->addTab(ProgrammeTab, QString());

        gridLayout_3->addWidget(GereurOnglet, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 710, 25));
        menuOption = new QMenu(menubar);
        menuOption->setObjectName(QStringLiteral("menuOption"));
        menuOptions_d_affichage = new QMenu(menuOption);
        menuOptions_d_affichage->setObjectName(QStringLiteral("menuOptions_d_affichage"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOption->menuAction());
        menuOption->addAction(actionAffichage_clavier);
        menuOption->addAction(actionActivation_Bip_Sonore);
        menuOption->addAction(menuOptions_d_affichage->menuAction());
        menuOptions_d_affichage->addAction(actionChanger_la_couleur);

        retranslateUi(MainWindow);

    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculatrice", 0));
        actionAffichage_clavier->setText(QApplication::translate("MainWindow", "Affichage clavier", 0));
        actionActivation_Bip_Sonore->setText(QApplication::translate("MainWindow", "Activation Bip Sonore", 0));
        actionChanger_la_couleur->setText(QApplication::translate("MainWindow", "Changer la couleur ", 0));
        boutonP->setText(QApplication::translate("MainWindow", "+", 0));
        boutonM->setText(QApplication::translate("MainWindow", "-", 0));
        boutonD->setText(QApplication::translate("MainWindow", "/", 0));
        boutonF->setText(QApplication::translate("MainWindow", "*", 0));
        boutonComplexe->setText(QApplication::translate("MainWindow", "$", 0));
        boutonDIV->setText(QApplication::translate("MainWindow", "DIV", 0));
        boutonNEG->setText(QApplication::translate("MainWindow", "NEG", 0));
        boutonNUM->setText(QApplication::translate("MainWindow", "NUM", 0));
        boutonDEN->setText(QApplication::translate("MainWindow", "DEN", 0));
        boutonRE->setText(QApplication::translate("MainWindow", "RE", 0));
        boutonIM->setText(QApplication::translate("MainWindow", "IM", 0));
        boutonMOD->setText(QApplication::translate("MainWindow", "MOD", 0));
        boutonEgalite->setText(QApplication::translate("MainWindow", "=", 0));
        boutonDIFF->setText(QApplication::translate("MainWindow", "!=", 0));
        boutonINF->setText(QApplication::translate("MainWindow", "<", 0));
        boutonSUP->setText(QApplication::translate("MainWindow", ">", 0));
        boutonINFEG->setText(QApplication::translate("MainWindow", "<=", 0));
        boutonSUPEG->setText(QApplication::translate("MainWindow", ">=", 0));
        boutonAND->setText(QApplication::translate("MainWindow", "AND", 0));
        boutonOR->setText(QApplication::translate("MainWindow", "OR", 0));
        boutonNOT->setText(QApplication::translate("MainWindow", "NOT", 0));
        boutonUNDO->setText(QApplication::translate("MainWindow", "UNDO", 0));
        boutonREDO->setText(QApplication::translate("MainWindow", "REDO", 0));
        boutonCLEAR->setText(QApplication::translate("MainWindow", "CLEAR", 0));
        boutonSWAP->setText(QApplication::translate("MainWindow", "SWAP", 0));
        boutonLAST_OP->setText(QApplication::translate("MainWindow", "LASTOP", 0));
        boutonLAST_ARGS->setText(QApplication::translate("MainWindow", "LASTARGS", 0));
        boutonSTO->setText(QApplication::translate("MainWindow", "STO", 0));
        boutonEVAL->setText(QApplication::translate("MainWindow", "EVAL", 0));
        boutonEDIT->setText(QApplication::translate("MainWindow", "EDIT", 0));
        bouton1->setText(QApplication::translate("MainWindow", "1", 0));
        bouton2->setText(QApplication::translate("MainWindow", "2", 0));
        bouton3->setText(QApplication::translate("MainWindow", "3", 0));
        bouton4->setText(QApplication::translate("MainWindow", "4", 0));
        bouton5->setText(QApplication::translate("MainWindow", "5", 0));
        bouton6->setText(QApplication::translate("MainWindow", "6", 0));
        bouton7->setText(QApplication::translate("MainWindow", "7", 0));
        bouton8->setText(QApplication::translate("MainWindow", "8", 0));
        bouton9->setText(QApplication::translate("MainWindow", "9", 0));
        bouton0->setText(QApplication::translate("MainWindow", "0", 0));
        boutonBS->setText(QApplication::translate("MainWindow", "BACKSPACE", 0));
        boutonEspace->setText(QApplication::translate("MainWindow", "SPACE", 0));
        boutonEntree->setText(QApplication::translate("MainWindow", "Entr\303\251e", 0));
        boutonPoint->setText(QApplication::translate("MainWindow", ",", 0));
        boutonGuillemet->setText(QApplication::translate("MainWindow", "'", 0));
        boutonParentheseO->setText(QApplication::translate("MainWindow", "[", 0));
        boutonParentheseF->setText(QApplication::translate("MainWindow", "]", 0));
        GereurOnglet->setTabText(GereurOnglet->indexOf(CalculatriceTab), QApplication::translate("MainWindow", "Calculatrice", 0));
        GereurOnglet->setTabText(GereurOnglet->indexOf(VariableTab), QApplication::translate("MainWindow", "Variable", 0));
        GereurOnglet->setTabText(GereurOnglet->indexOf(ProgrammeTab), QApplication::translate("MainWindow", "Programme", 0));
        sendProgram->setText(QApplication::translate("MainWindow","Envoyer",0));
        menuOption->setTitle(QApplication::translate("MainWindow", "Options", 0));
        menuOptions_d_affichage->setTitle(QApplication::translate("MainWindow", "Options d'affichage", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public QMainWindow, public Ui_MainWindow {
      Q_OBJECT
        //pile dans laquelle on stockent les littéraux
        Pile* pile;
        //gére les opérations
        Controleur* controleur;
        //gére les expressions
        LitteraleManager* manager;
    public:
        MainWindow(QWidget *parent = nullptr) : QMainWindow(parent){

          pile=new Pile;
          manager=new LitteraleManager;
          controleur=&Controleur::getInstance(*manager,*pile);
          Ui_MainWindow::setupUi(this);
          connections();

        }
        virtual ~MainWindow(){Controleur::libererInstance();}
        void connections();
    public slots:
        void refresh();
        void getNextCommande();
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // INTERFACE_GRAPHIQUETT5446_H

