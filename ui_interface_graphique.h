/********************************************************************************
** Form generated from reading UI file 'interface_graphiqueh31716.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef INTERFACE_GRAPHIQUEH31716_H
#define INTERFACE_GRAPHIQUEH31716_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAffichage_clavier;
    QAction *actionActivation_Bip_Sonore;
    QAction *actionChanger_la_couleur;
    QWidget *centralwidget;
    QTabWidget *GereurOnglet;
    QWidget *CalculatriceTab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *wCommandePile;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *wAffichageErreur;
    QTableView *wAffichagePil;
    QLineEdit *wAffichageCommande;
    QWidget *wClavier;
    QWidget *layoutWidget1;
    QHBoxLayout *clavier;
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
    QVBoxLayout *clavierOperateur;
    QPushButton *boutonP;
    QPushButton *boutonM;
    QPushButton *boutonF;
    QPushButton *boutonD;
    QPushButton *boutonC;
    QPushButton *boutonNEG;
    QPushButton *boutonDIV;
    QPushButton *boutonEntree;
    QWidget *VariableTab;
    QTableView *TableauVarAffi;
    QWidget *ProgrammeTab;
    QPlainTextEdit *wAffichageProgramme;
    QMenuBar *menubar;
    QMenu *menuOption;
    QMenu *menuOptions_d_affichage;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(431, 611);
        actionAffichage_clavier = new QAction(MainWindow);
        actionAffichage_clavier->setObjectName(QStringLiteral("actionAffichage_clavier"));
        actionActivation_Bip_Sonore = new QAction(MainWindow);
        actionActivation_Bip_Sonore->setObjectName(QStringLiteral("actionActivation_Bip_Sonore"));
        actionChanger_la_couleur = new QAction(MainWindow);
        actionChanger_la_couleur->setObjectName(QStringLiteral("actionChanger_la_couleur"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        GereurOnglet = new QTabWidget(centralwidget);
        GereurOnglet->setObjectName(QStringLiteral("GereurOnglet"));
        GereurOnglet->setGeometry(QRect(10, 10, 411, 531));
        CalculatriceTab = new QWidget();
        CalculatriceTab->setObjectName(QStringLiteral("CalculatriceTab"));
        CalculatriceTab->setEnabled(false);
        CalculatriceTab->setAutoFillBackground(true);
        verticalLayoutWidget = new QWidget(CalculatriceTab);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 10, 391, 481));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        wCommandePile = new QWidget(verticalLayoutWidget);
        wCommandePile->setObjectName(QStringLiteral("wCommandePile"));
        layoutWidget = new QWidget(wCommandePile);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 371, 181));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wAffichageErreur = new QLineEdit(layoutWidget);
        wAffichageErreur->setObjectName(QStringLiteral("wAffichageErreur"));

        verticalLayout->addWidget(wAffichageErreur);

        wAffichagePil = new QTableView(layoutWidget);
        wAffichagePil->setObjectName(QStringLiteral("wAffichagePil"));

        verticalLayout->addWidget(wAffichagePil);

        wAffichageCommande = new QLineEdit(layoutWidget);
        wAffichageCommande->setObjectName(QStringLiteral("wAffichageCommande"));

        verticalLayout->addWidget(wAffichageCommande);


        verticalLayout_2->addWidget(wCommandePile);

        wClavier = new QWidget(verticalLayoutWidget);
        wClavier->setObjectName(QStringLiteral("wClavier"));
        wClavier->setEnabled(false);
        layoutWidget1 = new QWidget(wClavier);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 0, 341, 231));
        clavier = new QHBoxLayout(layoutWidget1);
        clavier->setObjectName(QStringLiteral("clavier"));
        clavier->setContentsMargins(0, 0, 0, 0);
        clavierChiffre = new QVBoxLayout();
        clavierChiffre->setObjectName(QStringLiteral("clavierChiffre"));
        ligne123 = new QHBoxLayout();
        ligne123->setObjectName(QStringLiteral("ligne123"));
        bouton1 = new QPushButton(layoutWidget1);
        bouton1->setObjectName(QStringLiteral("bouton1"));

        ligne123->addWidget(bouton1);

        bouton2 = new QPushButton(layoutWidget1);
        bouton2->setObjectName(QStringLiteral("bouton2"));

        ligne123->addWidget(bouton2);

        bouton3 = new QPushButton(layoutWidget1);
        bouton3->setObjectName(QStringLiteral("bouton3"));

        ligne123->addWidget(bouton3);


        clavierChiffre->addLayout(ligne123);

        ligne456 = new QHBoxLayout();
        ligne456->setObjectName(QStringLiteral("ligne456"));
        bouton4 = new QPushButton(layoutWidget1);
        bouton4->setObjectName(QStringLiteral("bouton4"));

        ligne456->addWidget(bouton4);

        bouton5 = new QPushButton(layoutWidget1);
        bouton5->setObjectName(QStringLiteral("bouton5"));

        ligne456->addWidget(bouton5);

        bouton6 = new QPushButton(layoutWidget1);
        bouton6->setObjectName(QStringLiteral("bouton6"));

        ligne456->addWidget(bouton6);


        clavierChiffre->addLayout(ligne456);

        ligne789 = new QHBoxLayout();
        ligne789->setObjectName(QStringLiteral("ligne789"));
        bouton7 = new QPushButton(layoutWidget1);
        bouton7->setObjectName(QStringLiteral("bouton7"));

        ligne789->addWidget(bouton7);

        bouton8 = new QPushButton(layoutWidget1);
        bouton8->setObjectName(QStringLiteral("bouton8"));

        ligne789->addWidget(bouton8);

        bouton9 = new QPushButton(layoutWidget1);
        bouton9->setObjectName(QStringLiteral("bouton9"));

        ligne789->addWidget(bouton9);


        clavierChiffre->addLayout(ligne789);

        ligne0BS = new QHBoxLayout();
        ligne0BS->setObjectName(QStringLiteral("ligne0BS"));
        bouton0 = new QPushButton(layoutWidget1);
        bouton0->setObjectName(QStringLiteral("bouton0"));
        bouton0->setEnabled(false);

        ligne0BS->addWidget(bouton0);

        boutonBS = new QPushButton(layoutWidget1);
        boutonBS->setObjectName(QStringLiteral("boutonBS"));

        ligne0BS->addWidget(boutonBS);


        clavierChiffre->addLayout(ligne0BS);


        clavier->addLayout(clavierChiffre);

        clavierOperateur = new QVBoxLayout();
        clavierOperateur->setObjectName(QStringLiteral("clavierOperateur"));
        boutonP = new QPushButton(layoutWidget1);
        boutonP->setObjectName(QStringLiteral("boutonP"));

        clavierOperateur->addWidget(boutonP);

        boutonM = new QPushButton(layoutWidget1);
        boutonM->setObjectName(QStringLiteral("boutonM"));

        clavierOperateur->addWidget(boutonM);

        boutonF = new QPushButton(layoutWidget1);
        boutonF->setObjectName(QStringLiteral("boutonF"));

        clavierOperateur->addWidget(boutonF);

        boutonD = new QPushButton(layoutWidget1);
        boutonD->setObjectName(QStringLiteral("boutonD"));

        clavierOperateur->addWidget(boutonD);

        boutonC = new QPushButton(layoutWidget1);
        boutonC->setObjectName(QStringLiteral("boutonC"));

        clavierOperateur->addWidget(boutonC);

        boutonNEG = new QPushButton(layoutWidget1);
        boutonNEG->setObjectName(QStringLiteral("boutonNEG"));

        clavierOperateur->addWidget(boutonNEG);

        boutonDIV = new QPushButton(layoutWidget1);
        boutonDIV->setObjectName(QStringLiteral("boutonDIV"));

        clavierOperateur->addWidget(boutonDIV);

        boutonEntree = new QPushButton(layoutWidget1);
        boutonEntree->setObjectName(QStringLiteral("boutonEntree"));

        clavierOperateur->addWidget(boutonEntree);


        clavier->addLayout(clavierOperateur);


        verticalLayout_2->addWidget(wClavier);

        GereurOnglet->addTab(CalculatriceTab, QString());
        VariableTab = new QWidget();
        VariableTab->setObjectName(QStringLiteral("VariableTab"));
        TableauVarAffi = new QTableView(VariableTab);
        TableauVarAffi->setObjectName(QStringLiteral("TableauVarAffi"));
        TableauVarAffi->setGeometry(QRect(10, 10, 271, 411));
        GereurOnglet->addTab(VariableTab, QString());
        ProgrammeTab = new QWidget();
        ProgrammeTab->setObjectName(QStringLiteral("ProgrammeTab"));
        wAffichageProgramme = new QPlainTextEdit(ProgrammeTab);
        wAffichageProgramme->setObjectName(QStringLiteral("wAffichageProgramme"));
        wAffichageProgramme->setGeometry(QRect(10, 10, 271, 421));
        GereurOnglet->addTab(ProgrammeTab, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 431, 25));
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
        QObject::connect(actionAffichage_clavier, SIGNAL(changed()), wClavier, SLOT(hide()));

        GereurOnglet->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAffichage_clavier->setText(QApplication::translate("MainWindow", "Affichage clavier", 0));
        actionActivation_Bip_Sonore->setText(QApplication::translate("MainWindow", "Activation Bip Sonore", 0));
        actionChanger_la_couleur->setText(QApplication::translate("MainWindow", "Changer la couleur ", 0));
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
        boutonBS->setText(QApplication::translate("MainWindow", "<=", 0));
        boutonP->setText(QApplication::translate("MainWindow", "+", 0));
        boutonM->setText(QApplication::translate("MainWindow", "-", 0));
        boutonF->setText(QApplication::translate("MainWindow", "*", 0));
        boutonD->setText(QApplication::translate("MainWindow", "/", 0));
        boutonC->setText(QApplication::translate("MainWindow", "$", 0));
        boutonNEG->setText(QApplication::translate("MainWindow", "NEG", 0));
        boutonDIV->setText(QApplication::translate("MainWindow", "DIV", 0));
        boutonEntree->setText(QApplication::translate("MainWindow", "Entr\303\251e", 0));
        GereurOnglet->setTabText(GereurOnglet->indexOf(CalculatriceTab), QApplication::translate("MainWindow", "Calculatrice", 0));
        GereurOnglet->setTabText(GereurOnglet->indexOf(VariableTab), QApplication::translate("MainWindow", "Variable", 0));
        GereurOnglet->setTabText(GereurOnglet->indexOf(ProgrammeTab), QApplication::translate("MainWindow", "Programme", 0));
        menuOption->setTitle(QApplication::translate("MainWindow", "Options", 0));
        menuOptions_d_affichage->setTitle(QApplication::translate("MainWindow", "Options d'affichage", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // INTERFACE_GRAPHIQUEH31716_H
