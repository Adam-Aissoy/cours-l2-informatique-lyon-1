#include <iostream>
#include <string>
using namespace std;
#include <vector>

int main() {
	std::vector<int> mon_vecteur;
    mon_vecteur.push_back(4);
    mon_vecteur.push_back(2);
    mon_vecteur.push_back(5);
    // Pour parcourir un vector (même const) on peut utiliser les iterators ou les index
    for(std::size_t i=0;i<mon_vecteur.size();++i)
    std::cout << mon_vecteur[i] << ' ';
    std::vector<int> mon_vecteur2(5,69);
  return 0;
}
