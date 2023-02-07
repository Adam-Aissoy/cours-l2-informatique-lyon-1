#include <iostream>
#include <math.h>
using namespace std;

struct Vecteur3D {
    float x,y,z;
    };
// Calcule la norme d'un vecteur 3D
float Vecteur3DGetNorme(const Vecteur3D& v) {
    return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}
// Normalise le vecteur 3D
void Vecteur3DNormaliser(Vecteur3D& v) {
    float norme = Vecteur3DGetNorme(v);
    if (norme != 0.0) { // appel possible à !Vecteur3DEstNormalise(v) pour ne pas normaliser
                        // si le vecteur est déjà normalisé
    v.x /= norme; v.y /= norme; v.z /= norme;
}
}
// Teste si le vecteur est de norme 1
bool Vecteur3DEstNormalise(const Vecteur3D& v) {
    return fabs(Vecteur3DGetNorme(v)-1.0) < 10e-8;
}
// Additionne 2 vecteurs 3D
Vecteur3D Vecteur3DAdd(const Vecteur3D& v1, const Vecteur3D& v2){
    Vecteur3D somme;
    somme.x = v1.x + v2.x;
    somme.y = v1.y + v2.y;
    somme.z = v1.z + v2.z;
    return somme;
}
// Affiche un vecteur 3D sous la forme (x,y,z)
void Vecteur3DAfficher(const Vecteur3D& v) {
    cout << "(" << v.x << "," << v.y << "," << v.z << ")";
}


//Exercice 4 ) 

// Remplit le tableau de vecteurs avec n vecteurs aux valeurs aleatoires [-10,10]
void Vecteur3DRemplirTabVecteurs(Vecteur3D tab[], int taille){
    for (int i=0; i<taille; i++) {
        tab[i].x = ((rand()%201)/10.0)-10.0;
        tab[i].y = ((rand()%201)/10.0)-10.0;
        tab[i].z = ((rand()%201)/10.0)-10.0;
    }
}
// Affiche le tableau de n vecteurs sous la forme vec1 ; vec2 ; ...
void Vecteur3DAfficherTabVecteurs(const Vecteur3D tab[], int taille){
    for (int i=0; i<taille; i++) {
        Vecteur3DAfficher(tab[i]);
        if (i!=taille-1) cout << " ; ";
    }
}
// Retourne l'indice du vecteur de plus grande norme
int Vecteur3DMaxTabVecteurs(const Vecteur3D tab[], int taille){
    if (taille <= 0) return -1;
    float maxNorme = Vecteur3DGetNorme(tab[0]);
    int maxIndice = 0;
    for (int i=1; i<taille; i++) {
        if (Vecteur3DGetNorme(tab[i]) > maxNorme) {
            maxNorme = Vecteur3DGetNorme(tab[i]);
            maxIndice = i;
        }
    }
    return maxIndice;
}
/*
int main() {//main Exercie 4 
    Vecteur3D tab [10];
    srand((unsigned int)time(NULL));
    Vecteur3DRemplirTabVecteurs(tab,10);
    cout << "tab: ";
    Vecteur3DAfficherTabVecteurs(tab,10);
    cout << endl;
    cout << "max tab: ";
    Vecteur3DAfficher(tab[Vecteur3DMaxTabVecteurs(tab,10)]);
    cout << endl;
    return 0;
}

*/

//Exercice 5

// Concatene les deux premiers tableaux dans le troisième
void Vecteur3DConcatenationTabVecteurs(Vecteur3D tab1 [], int taille1, Vecteur3D tab2 [], int
taille2, Vecteur3D tab3 []) {
    for (int i=0; i<taille1; i++) tab3[i] = tab1[i];
    for (int i=0; i<taille2; i++) tab3[i+taille1] = tab2[i];
}
// Inverse le tableau
void Vecteur3DInverseTabVecteurs(Vecteur3D tab [], int taille) {
    Vecteur3D tmp;
    for (int i=0; i<taille/2; i++) {
        tmp = tab[i];
        tab[i] = tab[taille-i-1];
        tab[taille-i-1] = tmp;
    }
}

/*
int main () {// main Exercice 5 
Vecteur3D tab1[5]; Vecteur3D tab2[6];
srand((unsigned int)time(NULL));
Vecteur3DRemplirTabVecteurs(tab1,5); Vecteur3DRemplirTabVecteurs(tab2,6);
Vecteur3D tab3[5+6];
Vecteur3DConcatenationTabVecteurs(tab1,5,tab2,6,tab3);
cout << "tab1: "; Vecteur3DAfficherTabVecteurs(tab1,5); cout << endl;
cout << "tab2: "; Vecteur3DAfficherTabVecteurs(tab2,6); cout << endl;
cout << "tab3: "; Vecteur3DAfficherTabVecteurs(tab3,5+6); cout << endl;
Vecteur3DInverseTabVecteurs(tab3,5+6);
cout << "tab3: "; Vecteur3DAfficherTabVecteurs(tab3,5+6); cout << endl;
return 0 ;
}


*/


/*
int main () { // main globale 
    Vecteur3D vecteur1 = {5,2,1};
    Vecteur3D vecteur2 = {0,3,2};
    cout << "vecteur1 non normalise: ";
    Vecteur3DAfficher(vecteur1);
    cout << endl;
    cout << "vecteur2 non normalise: ";
    Vecteur3DAfficher(vecteur2);
    cout << endl;
    cout << "somme: ";
    Vecteur3DAfficher(Vecteur3DAdd(vecteur1,vecteur2));
    cout << endl;
    Vecteur3DNormaliser(vecteur1);
    Vecteur3DNormaliser(vecteur2);
    cout << "vecteur1 normalise: ";
    Vecteur3DAfficher(vecteur1);
    cout << endl;
    cout << "vecteur2 normalise: ";
    Vecteur3DAfficher(vecteur2);
    cout << endl;
    cout << "somme: ";
    Vecteur3D somme = Vecteur3DAdd(vecteur1,vecteur2);
    Vecteur3DAfficher(somme);
    if (Vecteur3DEstNormalise(somme)) cout << " est normalise" << endl;
    else cout << " n'est pas normalise" << endl;
    return 0 ; 
}

*/


// ***************************************************** TP2 **********************************

int main (){// main TP2 ADAM
    float monFloat; 
    Vecteur3D monTab[4] ; 
    int monTab1 [] = {45, 21 , 9 , 6} ;
    cout << "Adresse de monFloat : " << (long int) &monFloat<< endl;
    cout << "Taille occupée par monTab : " << sizeof(monTab) << endl;
    cout << "Taille occupée par monTab1 : " << sizeof(monTab1)<< endl;


    cout << "Adresse de monTab[0] : " <<  (long int) &monTab[0]<< endl;
    cout << "Adresse de monTab[1] : " << (long int) &monTab[1]<< endl;
    cout << "Adresse de monTab[2] : " << (long int) &monTab[2]<< endl;
    
    cout << "Adresse de monTab1[0] : " <<  (long int) &monTab1[0]<< endl;
    cout << "Adresse de monTab1[1] : " << (long int) &monTab1[1]<< endl;
    cout << "Adresse de monTab1[2] : " << (long int) &monTab1[2]<< endl;
    
    return 0 ; 
}

//Exercie 2 

