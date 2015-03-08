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

  Les valeurs maximum et minimum representables par 
  l'encodage float sont 32752 et -32752. Les valeurs 
  suppérieures ou inférieures à celles-ci sont considérées 
  comme respectivement l'infini et moins l'infini.

 On obtient cette limite ainsi :

  (2^n-1)/2^n * 2^e - d

  ou e = (2^nbits_e) - 2
  et n le nombre de bits de m


*** Précision du programme:

  En dessous de 1.49012 * 10^-8 (et en dessus de
  -1.49012 * 10^-8) le programme considerera la 
  valeur comme égale à 0.

 On obtient cette precision ainsi :

  2^-n * 2^e-d
  ou e = 0 

*** Choix du decalage d

  d est fixe avec la formule 2^E-1 ou E est egal
  au nombre de bit de "e"

  d est donc = 15

