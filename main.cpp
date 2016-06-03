

#include "include.h"
#include "interface_graphique.h"
#include "computer.h"
#include "litterale.h"
#include "memento.h"
#include "operande.h"



int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    Ui::MainWindow fenetre;
    fenetre.show();
    return app.exec();
}
