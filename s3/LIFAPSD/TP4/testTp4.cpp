#include <iostream>
using namespace std;
class Date {
    public:
        int jour, mois, annee;

        void saisir() {
            cout << "Saisir le jour:";
            cin >> jour;
            cout << "Saisir le mois:";
            cin >> mois;
            cout << "Saisir l’annee:";
            cin >> annee;
        }
        void afficher() {
            cout << jour << "/" << mois << "/" << annee;
        }
        
        Date() {
            jour = 1; mois = 1; annee = 1990;
        }
        Date(int j, int m, int a) {
            jour = j; mois = m; annee = a;
        }
        ~Date() {
            cout << "Date détruite";
        }
        const Date operator + (const Date& operandeDroite) {
            Date resultatAddition;
            resultatAddition.jour = jour + operandeDroite.jour;
            resultatAddition.mois = mois + operandeDroite.mois;
            resultatAddition.annee = annee + operandeDroite.annee;
            // + vérification j < 28,29,30,31 et m < 12 et mise à jour
            return resultatAddition;
        }
        bool operator < (const Date& operandeDroite) {
            if (annee < operandeDroite.annee) return true;
            if (annee > operandeDroite.annee) return false;
            if (mois < operandeDroite.mois) return true;
            if (mois > operandeDroite.mois) return false;
            if (jour < operandeDroite.jour) return true;
            return false;
        }

        Date& operator = (const Date& operandeDroite) {
            jour = operandeDroite.jour;
            mois = operandeDroite.mois;
            annee = operandeDroite.annee;
            return *this;
        }
        int& operator [] (int indice) {
            switch (indice) {
                case 0 : return jour;
                case 1 : return mois;
                case 2 : return annee;
                default : return jour;
            }
        }
        friend std::ostream& operator << (std::ostream& flux, const Date& d) {
            flux << d.jour << " / " << d.mois << " / " << d.annee;
            return flux;
        }
}
int main () {
    Date dateDebut(7,9,2016); // début de semestre
    Date dateFin(10,1,2017); // fin de semestre
    Date tempsTP1(0,1,0); // prévision temps travail pour TP1
    Date tempsTP2(15,0,0); // prévision temps travail pour TP2
    Date tempsTP3(15,1,0); // prévision temps travail pour TP3
    Date tempsNecessaire; // constructeur par défaut
    tempsNecessaire = tempsTP1 + tempsTP2 + tempsTP3;
    if (dateDebut + tempsNecessaire < dateFin)
        cout << "Estimation OK" ;
    else
        cout << "Mauvaise estimation, date de fin prévue: " << dateDebut +
        tempsNecessaire << "dépasse la fin du semestre: " << dateFin;
    return 0;
}