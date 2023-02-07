/*
1 Tri à bulles
• Définir le prédicat bulle(L1,L2) qui construit la liste L2 qui est la liste L1 dans laquelle l’élément
le plus petit est remonté en première place.
• Définir le prédicat tribulle(L1,L2) qui implémente le tri à bulles.
*/

bulle([],[]).
bulle([X],[X]).
bulle([X|L1],[Y,X|L2]):- bulle(L1,[Y|L2]), X >= Y.
bulle([X|L1],[X,Y|L2]):- bulle(L1,[Y|L2]), X < Y.

tribulle(). 

/* 
Arbres binaires
• Définir un prédicat qui vérifie l’appartenance d’un élément à un arbre. Comment le prédicat se
comporte-t-il en génération ? Que se passe-t-il si on inverse l’ordre des clauses ?
• Définir un prédicat qui construit la liste des valeurs des feuilles d’un arbre

*/
estDansArbre(X,[X,_,_]).
estDansArbre(X,[Y,FG,_]):- X\== Y, estDansArbre(X,FG).
estDansArbre(X,[Y,_,FD]):- X\== Y, estDansArbre(X,FD).
monArbre([6,[5,[3,[2,[],[]],[4,[],[]]],[]],[8,[7,[],[]],[9,[],[]]]]).

plusGrand(X,[_,_,_],X).
construitArbre(L).


