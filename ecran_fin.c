#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

int ecran_fin(int gagnant) {	/*	Ecran qui s'affiche à la fin de la partie, qui annonce le vainqueur et qui propose de rejouer ou quitter	*/

	int rejouer=2,x,y;

	InitialiserGraphique();
	CreerFenetre(400,300,800,600);
	if (gagnant==1) {

		EcrireTexte(300,50,"Victoire du joueur 1",2);	

	}	else {
		EcrireTexte(300,50,"Victoire du joueur 2",2);	

	}

	DessinerRectangle(230,290,80,40);
	EcrireTexte(240,310,"rejouer",1);
	DessinerRectangle(330,290,80,40);
	EcrireTexte(340,310,"quitter",1);

	while (rejouer==2) {

		if(SourisCliquee()) {
			x=_X;
			y=_Y;

			if ( (x>229 && x<311)  && (y>289 && y<331) ) {

				rejouer=1;
			} else {

				if( (x>329 && x<411)  && (y>289 && y<331) ) {

					rejouer=0;
				}
			}
		}

	}
	FermerGraphique();
	return rejouer;
}