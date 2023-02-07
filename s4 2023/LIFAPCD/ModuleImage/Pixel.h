/* Classe Pixel

 privé :

   r,g,b : entier (0..255)   // les composantes du pixel, unsigned char en C++

 public :

   // Constructeur par défaut de la classe: initialise le pixel à la couleur noire
   Constructeur Pixel ()

   // Constructeur de la classe: initialise r,g,b avec les paramètres
   Constructeur Pixel (nr, ng, nb : donnée entier)

   // Accesseur : récupère la composante rouge du pixel
   Fonction getRouge () -> entier

   // Accesseur : récupère la composante verte du pixel
   Fonction getVert () -> entier

   // Accesseur : récupère la composante bleue du pixel
   Fonction getBleu () -> entier

   // Mutateur : modifie la composante rouge du pixel
   Procédure setRouge (nr : donnée entier)

   // Mutateur : modifie la composante verte du pixel
   Procédure setVert (ng : donnée entier)

   // Mutateur : modifie la composante bleue du pixel
   Procédure setBleu (nb : donnée entier)

FinClasse

*/

class Pixel {
    private: 
        unsigned char r,g,b;
    public:
    // Constructeur par défaut de la classe: initialise le pixel à la couleur noire
   Pixel (); 

   // Constructeur de la classe: initialise r,g,b avec les paramètres
   Pixel (int nr, int ng, int nb);

   // Accesseur : récupère la composante rouge du pixel
   int getRouge (); 

   // Accesseur : récupère la composante verte du pixel
   int getVert (); 


   // Accesseur : récupère la composante bleue du pixel
   int getBleu (); 

   // Mutateur : modifie la composante rouge du pixel
   void setRouge (int nr );

   // Mutateur : modifie la composante verte du pixel
   void setVert (int ng);

   // Mutateur : modifie la composante bleue du pixel
   void setBleu (int nb);

}