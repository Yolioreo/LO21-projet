
#include <QApplication>
#include "qcomputer.h"
#include "interface_graphique.h"
#include "computer.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    Ui::MainWindow fenetre;
    fenetre.show();
    return app.exec();
}
