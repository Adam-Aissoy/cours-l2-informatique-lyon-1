#include <iostream>
struct  Couleur
{
    char  R, V , B;
};
void remplirCouleur (Couleur &c, string s){
    std::cout << "saisir la couleur souhaiter"<<std::endl;
    std::cin>>s;
    if(s=="rouge"){
        s = c.R;
    }else if(s=="bleu") {
        s = c.B
    }else{
        s.v
    }
}
void afficherCouleur(Couleur c){
    std::cout<< "["<<c.R<<","<<c.V<<","<<c.B<<"]"<<std::endl;
}
int plusGrand (Couleur c1,Couleur c2 , char carat){
    if (c1.R < c2.R){
        return c2.R;
    }
}

int main(){
    Couleur rouge;
    Couleur bleu;
    afficherCouleur(rouge);
    afficherCouleur(bleu);
    plusGrand(rouge, bleu);
}