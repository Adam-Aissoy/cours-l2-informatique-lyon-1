#include <iostream>
#include <math.h>
using namespace std ; 
struct Vecteur3D {
    float x,y,z ;
};


float Vecteur3DGetNorme ( const Vecteur3D&v){
    return (sqrt(v.x*v.x + v.y*v.y + v.z*v.z  ));
}

void Vecteur3DAfficher(Vecteur3D &v){
    cout << "vecteur " <<"{" << v.x << ","<< v.y << ","<< v.z << "}"<< endl;
}

void Vecteur3DNormaliser(Vecteur3D &v){
    double Vn = Vecteur3DGetNorme(v
/usr/include/c++/12/string_view:673:50: note:   pas de conversion connue pour convertir l'argumen

bool Vecteur3DEstNormalise(Vecteur3D &v){
    bool ok = Vecteur3DGetNorme(v) == 1.0 ; 

    if (ok ){
        cout << " vecteur est normaliser "<< endl ; 
        ok = true; }
    else {
        cout << " vecteur n'est pas normaliser "<< endl ; 
    }
    return ok;
}


int main(){    
    

    Vecteur3D vecteur1 = {5,2,1};
    Vecteur3D vecteur2 = {0,3,2};

    Vecteur3D vecteurTest = { 1,0,0};


    cout << "vecteur1 non normalise: ";
    Vecteur3DAfficher(vecteur1);
    cout << endl;
    cout << "vecteur2 non normalise: ";
    Vecteur3DAfficher(vecteur2);
    cout << endl;

    cout << "vecteurTest non normalise: ";
    Vecteur3DAfficher(vecteurTest);
    cout << endl;

    if (Vecteur3DEstNormalise(vecteur1)) cout << "vecteur 1 est normalise" << endl ;
    Vecteur3DEstNormalise(vecteur2);
    Vecteur3DEstNormalise(vecteurTest);

    /*
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

    */
   
    /*
    Vecteur3D vecteur1 = { 5, 2, 1}; 
    Vecteur3D vecteur2 = {0,3,2};
    cout << Vecteur3DGetNorme (vecteur1) << endl;
    cout << Vecteur3DGetNorme (vecteur2) << endl;
    Vecteur3DAfficher(vecteur1);
    Vecteur3DAfficher(vecteur2);
    Vecteur3DEstNormalise(vecteur1);
    Vecteur3DEstNormalise(vecteur2);
*/
    return 0;
}



