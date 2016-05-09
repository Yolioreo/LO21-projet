
#include <QApplication>
#include "qcomputer.h"
#include "computer.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    QComputer fenetre;
    fenetre.show();
    return app.exec();
}
