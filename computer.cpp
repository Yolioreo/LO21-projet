#include "computer.h"


//LitteraleManager::Handler LitteraleManager::handler=LitteraleManager::Handler();

//LitteraleManager& LitteraleManager::getInstance(){
//    if (handler.instance==nullptr) handler.instance=new LitteraleManager;
//    return *handler.instance;
//}

//void LitteraleManager::libererInstance(){
//    delete handler.instance;
//    handler.instance=nullptr;
//}
<<<<<<< HEAD
=======

void Controleur::slotOperator(){
  QPushButton* btn = qobject_cast<QPushButton*>(sender());
  if(btn==nullptr) {
      return;
  }
  if(!faitpartiedeMap(btn->text())){
      setMessage("Operateur n'existe pas");
      return;
    }
  faire[btn->text()]->operator ()();
}

>>>>>>> origin/master
Controleur::Handler1 Controleur::handler=Controleur::Handler1();

void Controleur::libererInstance(){
    delete handler.instance;
    handler.instance=nullptr;
}

Controleur& Controleur::getInstance(LitteraleManager& Mng,Pile& stack){
    if (handler.instance==nullptr) handler.instance=new Controleur(Mng,stack);
    return *handler.instance;
}
Controleur& Controleur::getInstance(){
    if(handler.instance==nullptr)qDebug()<<"Problème de passage de singleton";
    return *handler.instance;
}



Litterale* LitteraleManager::addLitterale(const QString& v){
    // analyser le string et pusher le bon litterale
   Litterale* YO;

    if (estUnEntier(v)&&(!v.contains("$")))
    {
        YO=new Entier(v.toInt());



    }
    if (estUnReel(v)&&(!v.contains("$")))
    {
        YO=new Reel(v.toDouble());



    }
    if (estUnRationnel(v)&&(!v.contains("$")))
    {

        QStringList r;
        r=v.split("/"); // on sépare les deux parties autour du "/"

        if(r[1].toInt()!=0){
            YO=new Rationnel(r[0].toInt(),r[1].toInt());
        }
        else
        {
            erreurDivZero();
            return nullptr;
        }



    }
    if(estUnComplexe(v)){
        QStringList ReIm,RE,IM;
        ReIm=v.split("$");


        RE=ReIm[0].split("/");
        IM=ReIm[1].split("/");
        LitteraleNum* r;
        LitteraleNum* i;



        if(IM.count()==2){
            if(IM[1]=="1")i=new Reel(IM[0].toDouble());
            else i=new Rationnel(IM[0].toInt(),IM[1].toInt());

        }
        else{

            i=new Reel(IM[0].toDouble());
        }

        if(RE.count()==2){
            if(RE[1]=="1")r=new Reel(RE[0].toDouble());
            else r=new Rationnel(RE[0].toInt(),RE[1].toInt());

        }
        else{

            r=new Reel(RE[0].toDouble());
        }

        YO=new Complexe(*r,*i);



    }
    if (estUneExpression(v)){
        YO =new Expression(v);


    }
    if (estUnProgramme(v)){
        YO=new Programme(v);


    }
    nb++;
    return YO;
}

void LitteraleManager::removeLitterale(Litterale* e){
    delete e;
}

LitteraleManager::~LitteraleManager(){
    // MEMENTO et destruction de tous les littéraux


}

void Pile::push(Litterale* e){
    // checker si c'est une fraction et denominateur =1
    // checker si c'est un complexe
    if(e!=nullptr)
    {
    PileLit.push_front(e);
    nb++;
    modificationEtat();
    }
}

void Pile::pop(){
    PileLit.pop_front();
    nb--;
    modificationEtat();
}

/*void Pile::affiche(QTextStream& f) const{
    f<<"********************************************* \n";
    f<<"M : "<<message<<"\n";
    f<<"---------------------------------------------\n";
    for(int i=nbAffiche; i>0; i--) {
        if (i<=nb) f<<i<<": "<<items[nb-i].getExpression().toString()<<"\n";
        else f<<i<<": \n";
    }
    f<<"---------------------------------------------\n";
}
*/


Pile::~Pile(){
    PileLit.clear();
}

Litterale* Pile::top() const {

    if (PileLit.size()==0) throw ComputerException("aucune expression sur la pile");
    return (PileLit.front());
}



bool isChar(QChar a) {
    if (a.isLetterOrNumber())
        return true;
    else return false;
}

bool isOperator(const QString s){
    if(s=="+") return true;
    if(s=="-") return true;
    if(s=="*") return true;
    if(s=="/") return true;
    if(s=="NEG") return true;
    if(s=="DIV") return true;
    if(s=="MOD") return true;
    if(s=="NUM") return true;
    if(s=="DEN") return true;
    if(s=="RE") return true;
    if(s=="IM") return true;
    if(s=="$") return true;

    return false;
}


bool isPartOperand(QChar a, QString s, int i){
    if(a=='-' && (i==0 || isOperator(QString(s[i-1]))))
        return true;
    else if(a=='$')
        return true;
    else if(a=='.'){
        return true;
    }
    return false;
}

int order(QString op) {
    if(op=="+" || op=="-")
        return 1;
    else if(op=="*" || "/")
        return 2;
    else
        return 0;
}


bool isHigher(QString a, QString b) {
    if(order(a)>=order(b)) return true;
    else return false;
}

QString parseExpression(const QString& s){
    QString infix = s;
    qDebug()<<infix;
    QString postfix = "";
    QStack<QString> stack;
    int i;
    for(i=0; i<infix.length(); i++) {
        qDebug()<<infix[i];
        bool isLongOperator = false;
        //we check if it's an operator composed by more than 1 QChar
        QString opTemp = "";
        int k=i;
        while(infix[k]!='(' && k-i<5 && k<infix.length()){
            opTemp.append(infix[k]);
            k++;
        }
        qDebug()<<"longOperator : "<<opTemp;
        if(isOperator(opTemp)){
            qDebug()<<"operator !!";
            isLongOperator=true;
        }
        //if operand
        if(!isLongOperator && (isChar(infix[i]) || isPartOperand(infix[i], infix, i))) {
            postfix.append(infix[i]);
            qDebug()<<"appending "<<infix[i];
        }
        //if operator
        else if(isOperator(QString(infix[i])) || isLongOperator || infix[i]=='(' || infix[i]==')') {
            QString op = QString(infix[i]);
            if(isLongOperator)
                op=opTemp;
            postfix.append(' ');
            //if stack is empty
            if(stack.isEmpty()) {
                stack.push(op);
            }
            //if stack not empty
            else if(!stack.isEmpty()) {

                //if (
                if(infix[i]=='(') {
                   stack.push(op);
                   }
                //if ) is encountered pop till ( to postfix
                else if(infix[i]==')') {

                    while(!stack.isEmpty() && *(stack.end()-1)!="(") {
                        qDebug()<<"loop";
                        postfix.append(*(stack.end()-1));
                        stack.pop();
                    }
                stack.pop();
                }
                else {
                    //pop until tos has lesser precedence or tos is null.
                    while(!stack.isEmpty() && isHigher(*(stack.end()-1),op) && *(stack.end()-1)!="(") {
                        qDebug()<<*(stack.end()-1);
                        if(*(stack.end()-1)!="(" && *(stack.end()-1)!=")"){//not appending ( and )
                            postfix.append(*(stack.end()-1));
                            postfix.append(' ');
                        }
                        stack.pop_back();
                    }

                    if(stack.isEmpty() || !(isHigher(*(stack.end()-1),op)) || *(stack.end()-1)=="(")
                        stack.push(op);
                    }
            }
            if(isLongOperator){
                qDebug()<<"op length : "<<op.length();
                i+=op.length();
                i--;
            }
        }
        qDebug()<<"stack :"<<stack;
    }

        while(!stack.isEmpty()) {
            QStack<QString>::iterator tos = stack.end() - 1;
            postfix.append(' ');
            if(*tos!="(" && *tos!=")"){
                postfix.append(*tos);
            }
            stack.pop();
        }
    qDebug()<<postfix;
    return postfix;
}




bool estUnLitteraleNum(const QString s){

   return (estUnEntier(s)||estUnRationnel(s)||estUnReel(s));
}

bool estUnEntier(const QString s){
    bool test=false;
    if(s.toInt(&test))return test;
    return test;
}

bool estUnRationnel(const QString s){

    bool test=false;
    QRegExp r("^(-?)(\\d+)/(-?)(\\d+)$");
    if(s.contains(r))
            test=true;
    return test;
}


bool estUnReel(const QString s){

    bool test=false;
    QRegExp r("^(-?)(\\d+).(-?)(\\d+)$");
    if(s.contains(r))
            test=true;
    return test;
}

bool estUnComplexe(const QString s){

    bool test=false;
    QRegExp r("^(-?)(\\d+)([.||/]?)(-?)(\\d*)(\\$)(-?)(\\d+)([.||/]?)(-?)(\\d*)$");
    if(s.contains(r))
            test=true;

    return test;
}


bool estUnAtome(QString s){

    Controleur* controle=&Controleur::getInstance();
    bool test=false;

    QRegExp rx("^[A-Z][A-Z0-9]{,5}$");
    if(s.contains(rx))test=true;

    if(controle->faitpartiedeMap(s)){
        controle->setMessage("Impossible : "+s+" est un opérateur");
        test=false;
    }
    return test;
}


bool estUneExpression(const QString s){

    return ((s[0]=='\'')&&(s[s.size()-1]=='\''));
}

bool estUnProgramme(const QString s){

    return ((s[0]=='[')&&(s[s.size()-1]==']'));
}

/*///////////// méthodes du controleur /////////////*/



void Controleur::initialisationMap(){
      faire["+"]=new addition;
      faire["-"]=new soustraction;
      faire["/"]=new division;
      faire["*"]=new multiplication;
      faire["$"]=new complexise;
      faire["NEG"]= new NEG;
      faire["DEN"]= new DEN;
      faire["NUM"]= new NUM;
      faire["DIV"]= new DIV;
      faire["MOD"]= new MOD;
      faire["RE"]=new RE;
      faire["IM"]=new IM;
      faire["!="]= new difference;
      faire["="]= new egalite;
      faire["<"]= new inferieur; 
      faire[">"]= new superieur;
      faire["<="]= new inferieur;
      faire[">="]= new superieur;
      faire["AND"]= new AND;
      faire["OR"]= new OR;
      faire["NOT"]= new NOT;
      faire["DUP"]= new dup;
      faire["DROP"]= new drop;
      faire["SWAP"]= new Swap;
      faire["CLEAR"]= new clear;
      faire["LASTOP"]= new lastop;
      faire["UNDO"]=new undo;
      faire["REDO"]=new redo;
      faire["EVAL"]=new eval;
      faire["STO"]=new sto;
      faire["IFT"]=new ift;
}



void Controleur::commande(const QString& c) { // A REVOIR : INTERPRETEUR

    //si la commande est un litterale
    if (estUnComplexe(c)||estUnLitteraleNum(c)||estUneExpression(c)||estUnProgramme(c)){
       LitAff.push(LitMng.addLitterale(c));
       pushMemento();
       clearFutur();
       return;
    }
    //si la commande est un opérateur
    if(faire.contains(c)){
      faire[c]->operator ()();
      lastoperande=c;
      pushMemento();
      if(c!="UNDO"&&c!="REDO")clearFutur();
      return;
    }
    //si la commande est un atome qui n'est pas un opérateur
    for (QMap<Atome *, Litterale*>::const_iterator it = variable.constBegin(); it != variable.constEnd(); ++it) {
        if(it.key()->afficher()==c){

            LitAff.push(it.value());
            return;
          }
    }

    //sinon
    LitAff.setMessage("Erreur : commande inconnue");
}

