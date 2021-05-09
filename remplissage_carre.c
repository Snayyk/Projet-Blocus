#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

void remplissage_carre(int taille) {	/*	Fonction qui va afficher le plateau (adaptation en fonction de la taille choisie)	*/
	int x=(taille*60)/2;
	int y=10;
	int l=60;
	int h=60;
	int i;
	for(i=0; i!=(taille*taille);i++) {
	if((i%taille)==0){
	x=(taille*60)/2;
	y=y+h;
	}	
	DessinerRectangle(x,y,l,h);
	x=x+l;

	}
}