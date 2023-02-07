tp 2 ) 
Q1) SELECT nom FROM Miels WHERE variété LIKE '%e%' 
union 
    SELECT idm FROM Produire WHERE saison = 'automne';

Q4) SELECT ida FROM Abeilles WHERE ida NOT IN 
( SELECT ida FROM Produire );

Q8) SELECT année FROM Miels WHERE ida IN
(SELECT ida FROM Produire WHERE saison = 'été') 
AND
année = (AVG() );


SELECT année FROM Miels WHERE idm IN
(SELECT idm FROM Produire WHERE saison = 'été') 
AND
année = SELECT AVG(année) FROM Miels WHERE idm IN
(SELECT idm FROM Produire WHERE saison = 'été') ;

/* la table des années été */
SELECT année FROM Miels WHERE idm IN 
( SELECT idm FROM Produire WHERE saison = 'été' );


/*  question 8  a finir at Home*/

SELECT AVG(année) FROM(SELECT année FROM Miels WHERE idm IN 
( SELECT idm FROM Produire WHERE saison = 'été' ));

SELECT AVG(AN) FROM(SELECT année FROM Miels WHERE idm IN 
( SELECT idm FROM Produire WHERE saison = 'été' ) ) t ;

SELECT 
Q9) 