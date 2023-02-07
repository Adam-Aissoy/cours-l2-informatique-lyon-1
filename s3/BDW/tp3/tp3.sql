1) SELECT COUNT(*) FROM Miels GROUP BY variété ; 
2) 
/*
envoie fichier by powershell Adam 
scp -r fichier_ou_repertoire_local p2110686@bdw.univ-lyon1.fr/:/var/www/p2110686/
*/

6) 

SELECT 
FROM 
WHERE nom IN (
    SELECT nom , COUNT(*) AS occu FROM Miels GROUP BY idm, nom HAVING COUNT(*) >= 2 ;
)
OR nom IN (
    SELECT nom FROM Miels WHERE variété LIKE 'fleurs';
)
GROUP BY ...;

6-a ) SELECT COUNT(*) AS occ
FROM Miels
GROUP BY nom
HAVING COUNT(*) >= 2