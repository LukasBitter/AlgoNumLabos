*************************************************
*** Laboratoire 1, cours algorithme numerique ***
***                08.03.2015                 ***
*************************************************

But : 
 Developper la classe nombre reel sur 17 bits 
 avec e a 5 bits 

Participants :
 Divernois Margaux  <margaux.divernois@he-arc.ch>
 Bitter Lukas       <lukas.bitter@he-arc.ch>
 Visinand Steve     <steve.visinand@he-arc.ch>


*************************************************

*** Limites du programme:

les valeures maximum et minimum representable par 
l'encodage float sont 32752 et -32752. 
Ensuite le programme considerera les valeures
comme infini et moins infini.

on obtient cette limite ainsi :

  (2^n-1)/2^n * 2^e - d

  ou e = (2^nbits_e) - 2
  et n le nombre de bits de m


*** Précision du programme:

en dessous de 1.49012 *10^-8 ( et en dessus de
-1.49012 *10^-8) le programme considerera la 
valeure comme egale à 0.

on obtient cette precision ainsi :

  2^-n * 2^e-d

  ou e = 0 


*** choix du decalage d

d est fixe avec la formule 2^E-1 ou E est egal
au nombre de bit de "e"

d est donc = 15

