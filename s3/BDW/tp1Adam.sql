#TP1

1) SELECT DISTINCT département as liste_dep FROM Forêts; 
2) SELECT * FROM Forêts WHERE superficie > 500 and superficie < 4000; 
3) SELECT * FROM Forêts WHERE nomf LIKE '%cha%';
4) SELECT nomf, nomg FROM Forêts F,Gestionnaires G WHERE F.idg = G.idg;
5)
6)
7) SELECT * FROM Gestionnaires WHERE type IS NOT NULL AND idg >3;
8) SELECT idf, nomf FROM Forêts WHERE département = ( SELECT département FROM Forêts WHERE nomf = 'forêt de Bonnevaux');
9) 
/* a finir chez moi */
SELECT F1.idf , F2.idf 
    FROM Forêts F1, Forêts F2 , Gestionnaires G1 ,Gestionnaires G2
    WHERE 
        ( SELECT FIND_IN_SET ( G1.nomg, G2.nomg ) ) >0
        /*AND F1.idf < F2.idf*/
        AND F1.idg < F2.idg;