#include <iostream>
using namespace std;

int x = 1;
int & rx = x;
int * px = &x;
void procedureAvecPointeur (int * ptr){
    cout << "la valeur du parametre : " << ptr << endl;
    cout << "l’adresse du paramètre : " <<&ptr << endl;

}

void procedureAvecReference (int& rf){
    cout << "la valeur du parametre : " << rf << endl;
    cout << "l’adresse du paramètre : " << &rf<< endl;
}

void procedureAvecInt (int val){
    cout << "la valeur du parametre : " << val<< endl;
    cout << "l’adresse du paramètre : " << &val<< endl;
}
 
int main (){
    int variable = 10;
    int * pointeur  = &variable ;
    int & reference = variable;

    procedureAvecPointeur(pointeur);
    procedureAvecReference(reference);
    procedureAvecInt(variable);


    cout <<"la valeur de x : " << x << endl ;
    cout << "la valeur de rx : " << rx << endl;
    cout << "la valeur de px : " << px << endl;

    

    cout <<"l’adresse mémoire de la variable x: " << &x << endl ;
    cout << "l’adresse mémoire de la variable rx : " << &rx << endl;
    cout << "l’adresse mémoire de la variable px : " << &px << endl;
    return 0;
}