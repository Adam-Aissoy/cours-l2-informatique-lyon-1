#include <iostream>
#include <math.h>
using namespace std;

// Exercice 3
struct  Vecteur3D
{
    float x , y , z  ; 
};
float Vecteur3DGetNorme (const Vecteur3D & v){
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z) ;
}
void Vecteur3DNormaliser(Vecteur3D & v){
    float norme = Vecteur3DGetNorme(v);
    if (norme != 0.0 ){
        v.x /= norme; 
        v.y /= norme;
        v.z /= norme; 

    }
}
int Vecteur3DEstNormalise (Vecteur3D & v){
    if (sqrt(v.x*v.x + v.y*v.y + v.z*v.z) == 1) {
        cout<< "votre vecteur est normaliser"<<endl;
        return 1;
    }else{
        cout<< "votre vecteur n'est normaliser pas "<<endl;
        return 0 ;
    } 
}
Vecteur3D Vecteur3DAdd(const Vecteur3D & v1 , const Vecteur3D & v2){
    Vecteur3D SommeVecteurs = {v1.x + v2.x ,v1.y + v2.y ,v1.z + v2.z  };
    return  SommeVecteurs;    
}
void Vecteur3DAfficher (const Vecteur3D &v){
    cout  << "("<<v.x<<","<<v.y<<","<<v.z<< ")"<< endl ; 
}
int main () {
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
    // test rajouter par Adam
    // pour normaliser le vecteur (sommme) 
    Vecteur3DNormaliser(somme);
    //fin
    if (Vecteur3DEstNormalise(somme)) cout << " est normalise" << endl;
    else cout << " n'est pas normalise" << endl;
    return 0;
}