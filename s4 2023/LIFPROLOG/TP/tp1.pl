homme(albert).
homme(jean).
homme(paul).
homme(bertrand).
homme(dominique).
homme(benoit).
femme(germaine).
femme(christiane).
femme(simone).
femme(marie).
femme(sophie).
pere(albert,jean).
pere(jean,paul).
pere(paul,bertrand).
pere(paul,sophie).
pere(jean,simone).
pere(louis,benoit).
mere(germaine,jean).
mere(christiane,simone).
mere(christiane,paul).
mere(simone,benoit).
mere(marie,bertrand).
mere(marie,sophie).
/* 2.3  */
parent(X,Y):-mere(X,Y).
parent(X,Y):-pere(X,Y).
fils(X,Y):- homme(X),parent(Y,X).
fille(X,Y):- femme(X),parent(Y,X).
grand_pere(X,Y):-pere(X,Z),parent(Z,Y).
grand_mere(X,Y):-mere(X,Z),parent(Z,Y).
soeur(X,Y):- femme(x),parent(T,X),parent(T,Y),X\==Y.
/* 3 */
aime(marie,vin). 
voleur(pierre).
aime(pierre,Y):-aime(Y,vin). 
vole(X,Y):- voleur(X),aime(X,Y).
vole(X,Y).

/*4 */
/*
pierre=marie.
X=jean.
X=Y.
pierre=aime(X,Y).
pere(X,Y)=aime(T,jean).
X=parent(Y,paul).
[X,Y]=[a,b,c].
[X,Y|L]=[a,b,c].
[X|L]=[X,Y|L2].
pere(X,fille(X))=pere(jean,Y).
*/
/* 5 */
maListe([a,b,c,d]).
longueur([],0).
longueur([J|K],M) :- longueur(K,P),M is P+1.

liste1([a,b,c]).
liste2([d,e,f]).

concat([],[],[]).
concat([],L2,L2).
concat(L1,[],L1).
concat([Xl1|L1],L2,L3):- concat(L1,L2,[Xl1|L3]).
/* concat(L1,[Xl2|L2],L3):- concat(L1,L2,[L3|Xl2]). */


concat1([],[],[]).
concat1([],L2,L2).
concat1(L1,[],L1).
concat1(L1,L2,L3):- L3 is [L1|L2].

/*
palindrome(L)
rang_pair(X,Y)
*/
