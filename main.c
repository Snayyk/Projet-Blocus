#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "ecran_fin.h"
#include "jeu_solo.h"
#include "jeu_duo.h"
#include "gen_rand.h"
#include "adjacente.h"
#include "remplissage_croix2.h"
#include "remplissage_croix1.h"
#include "remplissage_pion1.h"
#include "remplissage_pion2.h"
#include "remplissage_carre.h"
#include "size.h"



int main(int argc, char * argv[]) {


  	int taille,gagnant,rejouer=1;


  	while(rejouer==1) {

	taille=size();
	if(taille>10 && taille<20) {
		taille=taille-10;
		
		
		InitialiserGraphique();
	    CreerFenetre(100,100,((1920/15)*taille),((1080/12)*taille));
	 	gagnant=jeu_solo(taille);
	 	FermerGraphique();
	 	
	 	rejouer=ecran_fin(gagnant);
	 	

	} else {

		if (taille>20) {
			taille=taille-20;
			
			
			InitialiserGraphique();
		    CreerFenetre(100,100,((1920/15)*taille),((1080/12)*taille));
		 	gagnant=jeu_duo(taille);
		 	FermerGraphique();
		 	
		 	rejouer=ecran_fin(gagnant);
		 	
			}
	}
	
 	
    
    
	
	}

	return EXIT_SUCCESS;
}