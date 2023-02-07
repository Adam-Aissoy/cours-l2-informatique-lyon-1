#include <iostream>
#include <cstdlib>

using namespace std;

/*Code source pour le TP3 de LIFSE */

int main(int argc, char *argv[]) {




  if(argc != 2){
    cerr << "il faut exactement 2 arguments ";
    return 1; 
    /*
    il faut toujours essayer de retourner une valeur plus petit positif 
    */
  }

    /* Le code ci-dessous sera à commenter par la suite */
  cout << "la commande lancée est " << argv[0] << " avec " << argc << " argument(s): " << endl;
  // impression de la suite d'arguments.
  for (int i = 0 ; i < argc; i++){
    cout << argv[i] << ",";
  }
  cout << endl;

  /* test pour les arguments 
    // impression de la suite d'arguments.
  for (int j = 0 ; j < 10; j++){
    cout << argv[j] << ",";
  }
  cout << endl;

  */
  return 0;
}
