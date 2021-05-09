#include <stdio.h>
#include <stdlib.h>
#include <graph.h>



void remplissage_croix2(int taille, int position_x, int position_y) {	/*	Fonction qui place l'image de la croix appartenant au joueur 2 dans la case cliquée/générée aléatoirement pour le bot	*/
	int x=((taille*60)/2), y=70, l=60, h=60;
	

	position_x=((position_x-x)/l);
	position_x=position_x*l+x;

	position_y=((position_y-y)/h);
	position_y=position_y*h+y;
	
	ChargerImage("./Img/croix_noir.png",position_x+10,position_y+10,0,0,47,50);
	
	

}  