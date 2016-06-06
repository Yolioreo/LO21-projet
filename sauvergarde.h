#ifndef SAUVERGARDE_H
#define SAUVERGARDE_H

#include "include.h"
#include "computer.h"
class save_and_load_xml : public QObject{
    Q_OBJECT
public:
    save_and_load_xml(){}
public slots:
    void enregistrer_contexte(){
         QDomDocument dom("mon_xml");

         QFile doc_xml("xml_doc.xml");

         doc_xml.open(QIODevice::ReadWrite | QIODevice::Truncate);



         QDomElement utcomputer=dom.createElement("utcomputer");

         QDomElement pile=dom.createElement("pile");

         Controleur* controle=&Controleur::getInstance();


         unsigned int i;
         unsigned k=controle->getNbLitterale();
         for (i=0;i<k;i++){

             QDomElement litterale = dom.createElement("litterale");
             Litterale* L1=controle->top();
             controle->pop();
             litterale.setAttribute("id",i);
             litterale.setAttribute("value",L1->afficher());
             pile.appendChild(litterale);
         }
         utcomputer.appendChild(pile);

         QDomElement variables=dom.createElement("variables");
         for (Controleur::iterator_variable it = controle->begin_variable(); it != controle->end_variable(); ++it) {

             QDomElement variable = dom.createElement("variable");
             variable.setAttribute("var",it.key()->afficher());
             variable.setAttribute("value",it.value()->afficher());
             variables.appendChild(variable);
         }
         utcomputer.appendChild(variables);
         dom.appendChild(utcomputer);
         QString writeur = dom.toString();
         QTextStream stream (&doc_xml);
         stream<<writeur;
         doc_xml.close();
    }
    void charger_contexte(){
        qDebug()<<"YO ? ";
        QDomDocument dom("mon_xml");

        QFile doc_xml("xml_doc.xml");
        Controleur* controle=&Controleur::getInstance();

        doc_xml.open(QIODevice::ReadOnly | QIODevice::Truncate);
        dom.setContent(&doc_xml);
        doc_xml.close();



        QDomElement utcomputer1=dom.documentElement(); // contient utcomputer et tous ses noeuds

        QDomNode pile=utcomputer1.firstChild();
        QDomNode variables=pile.nextSibling();





        QDomElement n=pile.firstChildElement("litterale");
        QStack<QString> temp;
       while(!n.isNull()){

        temp.push_front(n.attribute("value"));

        n=n.nextSiblingElement("litterale");
        }

        while(!temp.isEmpty()){
           controle->push(controle->addLitterale(temp.front()));
           temp.pop_front();
        }

        Atome * atome;
        Litterale * valeur;

        QDomElement n1=variables.firstChildElement("variable");

        while(!n1.isNull()){
            atome=new Atome(n1.attribute("var"));
            valeur = controle->addLitterale(n1.attribute("value"));
            controle->creationVariable(atome,valeur);
            n1=n1.nextSiblingElement("variable");
        }
    }
};

#endif // SAUVERGARDE_H
