#include <iostream>
#include "ElementTD.h"
#include "TableauDynamique.h"
//TableauDynamique::TableauDynamique();
TableauDynamique::TableauDynamique(){
    ad = new ElementTD [1];
    capacite = 1;
    taille_utilisee = 0;
}
TableauDynamique::~TableauDynamique () {
    if (ad != NULL) {
        delete [] ad;
        ad = NULL;
    }
    capacite = 0;
    taille_utilisee = 0;
}
void TableauDynamique::vider(){
    delete [] ad ;
    ad = new ElementTD [1];
    capacite = 1;
    taille_utilisee = 0;    
}
void TableauDynamique::ajouterElement (ElementTD e) {
    if (taille_utilisee == capacite) { // tableau plein, on double la capacité
        ElementTD * temp = ad;
        ad = new ElementTD [2*capacite];
        capacite *= 2;
        for (unsigned int i = 0; i < taille_utilisee; i++) ad[i] = temp[i];
            delete [] temp;
    }
    ad[taille_utilisee] = e;
    taille_utilisee++;
}
ElementTD TableauDynamique::valeurIemeElement (unsigned int indice) const{
    return ad[indice];
}
void TableauDynamique::modifierValeurIemeElement(ElementTD e, unsigned int indice){
    ad[indice]=e;
}
void TableauDynamique::afficher ()const{
    for (unsigned int i = 0; i < taille_utilisee; i++)
    {
        /* code */
    }
    
}
void afficheTableau (const int * tab) {
for (unsigned int i = 0; i < sizeof(tab); i++) {
cout << tab[i] << " ";
}
}