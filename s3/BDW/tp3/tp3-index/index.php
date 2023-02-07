<?php
/* UCBL - BDW1 - automne 2020
 * https://perso.liris.cnrs.fr/fabien.duchateau/BDW1
 * Ce fichier permet d'écrire des requêtes en SQL et de les exécuter via le connecteur PHP mysqli.
 * Vous devez modifier les variables de connexion au SGBD (ci-dessous).
 * Pour exécuter ce fichier, vous devez l'envoyer sur le serveur bdw1.univ-lyon1.fr (voir fichier aide-tp.pdf).
 */

$SERVER = "localhost";				// serveur = localhost (si exécution sur le serveur bdw1.univ-lyon1.fr)
$USER 	= "p2110686";				// login = numéro étudiant.e
$MDP	= "Revolt90Silly";		// mot de passe indiqué sur Tomuss
$DB		= "p2110686";  				// nom de la BD = numéro étudiant.e

$connexion = getConnexionBD($SERVER, $USER, $MDP, $DB); // connexion à la BD 

?>


<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>BDW1 - tp3</title>
	<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
</head>
<body class="container">
    <main>
		<h1 class="text-center">Requêtes SQL du TP3</h1>

		<article>
			<h2>Question 1</h2>
			<?php
				$requete = "SELECT * FROM Miels";
				printRequete($requete);
				$res = mysqli_query($connexion, $requete);
				printResults($res);
			?>
		</article>
		
		<article>
			<h2>Question 2</h2>
			<?php
				$requete = "SELECT COUNT(idA) AS nbAbeilles FROM Abeilles";
				printRequete($requete);
				$res = mysqli_query($connexion, $requete);
				printResults($res);
			?>
		</article>
		
		
		<!--
		
		Copiez-collez et modifiez un bloc <article> pour répondre aux requêtes suivantes.
		Normalement, vous n'avez besoin que de modifier la variable $requête !
		
		-->
		
		
		
	</main>
</body>
</html>



<?php

/*********************************************************************
*  Fonctions PHP (connexion, affichages) - ne pas modifier normalement
**********************************************************************/


function getConnexionBD($server, $user, $mdp, $db) {
	/*
	* Se connecte à la BD.
	* Retourne un objet de connexion (succès), ou affiche un message d'erreur et termine le script.
	*/
	$connexion = mysqli_connect($server, $user, $mdp, $db); // serveur, login, mdp, bd
	if (mysqli_connect_errno()) {
	    printf('<p class="bg-danger">Échec de la connexion : %s</p>', mysqli_connect_error());
		printf('<p class="bg-danger">Avez-vous modifié la ligne qui permet de se connecter à la BD (fonction getConnexionBD) ? <br><samp>mysqli_connect("localhost", "p1234567", "votre_mdp", "p1234567")</samp></p>');
	    exit();
	}
	mysqli_query($connexion,'SET NAMES UTF8'); // conversion chaines en UTF8 (si problème affichage)
	return $connexion;
}


function printRequete($requete) {
	/*
	* Affiche la requête passée en paramètre dans un bloc de code HTML.
	*/
	 printf('<p class="bg-light"><code>%s</code></p>', $requete);
}


function printResults($resultats) {
	/*
	* Affiche un résultat de requête : soit un message de succès (requête booléenne, en cas de succès), soit un tableau de tuples (requête de type SELECT, en cas de succès), soit un message d'erreur (autres cas).
	*/
	if($resultats === FALSE) { // échec, erreur
		global $connexion; // besoin de objet connexion pour récupérer le type d'erreur
		printf('<p class="bg-warning">Problème avec la requête ! Corrigez-la, testez-la dans PHPMyAdmin. Erreur retournée par MariaDB : <br><samp>%s</samp></p>', mysqli_error($connexion));
	}
	else if($resultats === TRUE) { // succès pour requête à résultat booléen (test avec égalité stricte)
		echo '<p class="bg-success">La requête (type insert, delete, update) a réussie.</p>';
	}
	else { // requête de type select, $resultats est un objet
		if(mysqli_num_rows($resultats) == 0) // aucun tuple
			echo '<p class="bg-info">Aucun tuple résultat !</p>';
		else { // des tuples à afficher
			echo '<table class="table table-striped table-bordered"><thead class="thead-dark"><tr>';
			$fields = mysqli_fetch_fields($resultats);
			foreach ($fields as $field) // affiche chaque nom d'attribut
				printf("<th>%s</th>", $field->name);
			echo "</tr></thead><tbody>";
			while ($row = mysqli_fetch_row($resultats)) { // pour chaque tuple
				echo "<tr>";
				foreach ($row as $val) // affiche la valeur de chaque attribut du tuple
					printf("<td>%s</td>", $val); 
				echo "</tr>";
			}
			echo "</tbody></table>";
		}
	}
}

?>