#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

void remplissage_pion1(int taille, int position_x, int position_y) { /*	Fonction qui place l'image du pion appartenant au joueur 1 dans la case cliquée/générée aléatoirement pour le bot	*/
	int x=((taille*60)/2), y=70, l=60, h=60;
	

	position_x=((position_x-x)/l);
	position_x=position_x*l+x;

	position_y=((position_y-y)/h);
	position_y=position_y*h+y;

	ChargerImage("./Img/pion_blanc.jpeg",position_x+10,position_y+10,0,0,47,50);
	
	

} 
