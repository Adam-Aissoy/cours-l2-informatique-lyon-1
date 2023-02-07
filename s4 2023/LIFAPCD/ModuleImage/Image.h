Classe Image

 privé :

   tab : tableau de Pixel     // le tableau 1D de pixel
   dimx, dimy : entier        // les dimensions de l'image

 public :

   // Constructeur par défaut de la classe: initialise dimx et dimy à 0
   // ce constructeur n'alloue pas de pixel
   Constructeur Image ()

   // Constructeur de la classe: initialise dimx et dimy (après vérification)
   // puis alloue le tableau de pixel dans le tas (image noire)
   Constructeur Image (dimensionX, dimensionY : donnée entier);

   // Destructeur de la classe: déallocation de la mémoire du tableau de pixels
   // et mise à jour des champs dimx et dimy à 0
   Destructeur Image ()

   // Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
   // la formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x]
   Fonction getPix (x,y : donnée entier) -> 'Pixel' (l'original, pas une copie)

   // Mutateur : modifie le pixel de coordonnées (x,y)
   Procédure setPix (x,y : donnée entier; couleur : donnée Pixel)

   // Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
   Procédure dessinerRectangle (Xmin,Ymin,Xmax,Ymax : donnée entier; couleur : donnée Pixel)

   // Efface l'image en la remplissant de la couleur en paramètre
   // (en appelant dessinerRectangle avec le bon rectangle)
   Procédure effacer (couleur : donnée Pixel)

   // Effectue une série de tests vérifiant que le module fonctionne et
   // que les données membres de l'objet sont conformes
   Procédure testRegression ()

FinClasse