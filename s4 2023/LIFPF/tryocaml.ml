(* Ceci est un éditeur pour OCaml
   Entrez votre programme ici, et envoyez-le au toplevel en utilisant le
   bouton "Évaluer le code" ci-dessous ou [Ctrl-e]. *)

3*2+5/2;;
let x = 2;;
let y = 3.0 let z = 6.0 in z *.y;; 
"ben"^"Aysoy";;
let a = true;;
let b = true;;
let c = false;;
a||b&&c;;
c||b;;
c&&b;;
(* d'ou le && est preriotaire sur || 'apres le test *)
3 < 2;;
(**3 < 2.0;;*)
(* on peut pa faire la comparaison entre float et int *)
float_of_int 2 ;;
float_of_int (3 +2 );;
(*  float_of_int 3 +2 ;; il faut les mettres en () *)