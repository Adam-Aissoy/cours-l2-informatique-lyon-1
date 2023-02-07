#include <iostream>
#include <cmath>
class NbComplexe{
    public : 
        float re, im ;
    void saisirNbComplexe(){
        std::cout << "saisir la partie reel de votre nombre complexe : "<<std::endl;
        std::cin >> re; 
        std::cout << "saisir la partie imaginaire de votre nombre complexe : "<<std::endl;
        std::cin >> im; 

    }
    void afficherNbComplexe (){
        if (im > 0){
            std::cout <<" z = "<<re<< " + " <<im<<"i"<<std::endl;
        }else if (im == 0){
            std::cout <<" z = "<<re<<std::endl;
        }else{
            std::cout <<" z = "<<re<<im<<"i"<<std::endl;
        }
    }

    NbComplexe(){re = 0 ; im = 0 ;} // Explication de cette partie 
    NbComplexe(float partieReel , float partieImaginaire){
        re = partieReel; 
        im = partieImaginaire;
    }
    NbComplexe(const NbComplexe & NbComplexeParCopie ){
        re = NbComplexeParCopie.re;
        im = NbComplexeParCopie.im;
    }
    ~NbComplexe(){
        std::cout<< "Nombre complexe detruite"<<std::endl;
    }
    //Rappel : (𝑟𝑒1 + 𝑖𝑚1 𝑖) × (𝑟𝑒2 + 𝑖𝑚2 𝑖) = (𝑟𝑒1 × 𝑟𝑒2 − 𝑖𝑚1 × 𝑖𝑚2) + (𝑖𝑚1 × 𝑟𝑒2 + 𝑟𝑒1 × 𝑖𝑚2) 𝑖
    
    void multiplier(NbComplexe Nc1){
        this->re = (re*Nc1.re - im*Nc1.im) ;
        this->im = (im*Nc1.re + re*Nc1.im);
    }

    // Exercice 3 
    // Rappel : |𝑟𝑒 + 𝑖𝑚 𝑖| = √𝑟𝑒2 + 𝑖𝑚2
    float module(){
        return (sqrt (re*re + im*im));
    }
};

int main(){
    NbComplexe MonNbC; 
    MonNbC.afficherNbComplexe();
    MonNbC.saisirNbComplexe();
    MonNbC.afficherNbComplexe();
    NbComplexe c2(2.0, 3.1) ;
    c2.afficherNbComplexe() ;
    NbComplexe c3(c2) ;
    c3.afficherNbComplexe();
    MonNbC.multiplier(c2);
    MonNbC.afficherNbComplexe();
    MonNbC.module();
    std::cout<<MonNbC.module;
    return 0;
}