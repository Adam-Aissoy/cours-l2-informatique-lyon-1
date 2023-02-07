#include <iostream>
using namespace std;

class NbComplexe {
    public:
    float re, im;
};

void saisir() {
    cout << endl << "Saisir la partie reelle: ";
    cin >> re;
    cout << "Saisir la partie imaginaire: ";
    cin >> im;
}
void afficher() const {
    cout << re << " ";
    if (im >= 0.0) cout << "+";
    cout << im << " i";
    cout << endl;
}

//1)d)

cout << sizeof(NbComplexe);
// ou : cout << sizeof(unComplexe); avec unComplexe objet de type NbComplexe
/* NB: L’espace mémoire total requis pour un objet est la somme des espaces nécessaires pour chaque
donnée membre, plus un padding interne optionel. Quand un ordinateur moderne lit ou écrit vers une
addresse mémoire, il le fait sur des mots. Un alignement des données signifie mettre les données à une
adresse décalée égale à un multiple de la taille d’un mot, ce qui augmente les performances du système de
part la façon dont le CPU gère la mémoire. Pour aligner les données, il peut donc être nécessaire d’insérer
des octets (non significatifs) entre les données membres d’un objet.
*/

// Exercice 2 
//a) 

NbComplexe () : re(0), im(0) { }
NbComplexe (float a, float b) : re(a), im(b) { }
NbComplexe (const NbComplexe& c) {re = c.re; im = c.im;}
~NbComplexe () { }
//b) 

void multiplier (const NbComplexe& c){
    float saveRe = re;
    re = re*c.re - im*c.im;
    im = im*c.re + saveRe*c.im;
}

//c) 
NbComplexe complexe1 (unComplexe);
complexe1.afficher();
NbComplexe * complexe2 = new NbComplexe(5,2);
complexe2->afficher();
complexe2->multiplier(complexe1);
complexe2->afficher();
delete complexe2;
 //Exercice 3 

float module() const {
    return sqrt(re*re+im*im);
}
bool estPlusPetit (const NbComplexe & c) const {
    return module() < c.module();
}

//Exercice 4 
int taille;
cout << "Donner le nombre de complexes: ";
cin >> taille;
if (taille <= 0) return 0;
srand((unsigned int) time(NULL));
NbComplexe * tab = new NbComplexe[taille];
for (int i=0; i<taille; i++) {
    tab[i].re = ((rand()%201)/10.0)-10.0;
    tab[i].im = ((rand()%201)/10.0)-10.0;
    cout << "tab[" << i << "]= ";
    cout << "(mod= " << tab[i].module() << ") ";
    tab[i].afficher();
}
delete [] tab;

//Exercice 5 
void trierParSelection (NbComplexe * tab, int taille) {
    NbComplexe minComplexe;
    for (int i=0; i<taille-1; i++) {
        int indmin = i;
        for (int j=i+1; j<taille; j++) {
            if (tab[j].estPlusPetit(tab[indmin])) indmin = j;
        }
        minComplexe = tab[indmin];
        tab[indmin] = tab[i];
        tab[i] = minComplexe;
    }
}
//Exercie 6 
void trierParInsertion (NbComplexe * tab, int taille) {
    NbComplexe complexeAPlacer;
    for (int i=1; i<taille; i++) {
        complexeAPlacer = tab[i];
        int j = i - 1;
        while ( j >= 0 && complexeAPlacer.estPlusPetit(tab[j]) ) {
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1]=complexeAPlacer;
    }
}
//Le programme principal est identique à celui de la question précédente en changeant uniquement l’appel à la
//procédure de tri, ici : trierParInsertion(tab,taille);
int main () {
    NbComplexe unComplexe;
    unComplexe.afficher();
    unComplexe.saisir();
    unComplexe.afficher();
    //main exo5 Tp3
    int taille;
    cout << "Donner le nombre de complexes: ";
    cin >> taille;
    srand((unsigned int) time(NULL));
    if (taille <= 0) return 0;
    NbComplexe * tab = new NbComplexe[taille];
    for (int i=0; i<taille; i++) {
    tab[i].re = ((rand()%200)/10.0)-10.0;
    tab[i].im = ((rand()%200)/10.0)-10.0;
    cout << "tab[" << i << "]= ";
    cout << "(mod= " << tab[i].module() << ") ";
    tab[i].afficher();
    }
    trierParSelection(tab,taille);
    for (int i=0; i<taille; i++) {
    cout << "tab trie[" << i << "]= ";
    cout << "(mod= " << tab[i].module() << ") ";
    tab[i].afficher();
    }
    delete [] tab;
    return 0;
}
//On a le droit de faire les affections entre nombres complexes car les données membres sont deux réels, on n’a
//donc pas besoin de définir l’opérateur d’affectation ici.

