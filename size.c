#include <stdio.h>
#include <stdlib.h>
#include <graph.h>



int size(void) { /*	Fonction qui fait apparaître le premier écran, qui permet de choisir la taille du plateau et contre qui va jouer l'utilisateur ( bot ou joueur 2)	*/
	
	
	int choix=1,x,y,start=0;
	char numero[7];
	couleur c_cache,c_taille,c_titre;
	
	int taille=3;
	

	
	InitialiserGraphique();
	c_cache=CouleurParNom("white");
	c_taille=CouleurParNom("black");
	c_titre=CouleurParNom("red");
	CreerFenetre(400,300,800,600);
	DessinerRectangle(350,270,100,60);
	EcrireTexte(360,305,"Taille = ",1);
	DessinerRectangle(350,270,100,60);
	ChargerImage("./Img/fleche_haut.png",460,245,0,0,49,50);
	DessinerRectangle(350,270,100,60);
	ChargerImage("./Img/fleche_bas.png",460,295,0,0,50,50);
	
	DessinerRectangle(240,390,60,40);
	EcrireTexte(250,420,"Solo",1);
	DessinerRectangle(340,390,60,40);
	EcrireTexte(360,420,"Duo",1);
	DessinerRectangle(440,390,60,40);
	EcrireTexte(450,420,"Start",1);

	

	ChoisirCouleurDessin(c_titre);
	EcrireTexte(300,50,"Le jeu du blocus",2);	
	ChoisirCouleurDessin(c_taille);

				/* Barre qui montre le choix sélectionné*/
	RemplirRectangle(250,440,40,4);

	
	sprintf(&numero[0], "%d", taille);
	EcrireTexte(430,305,&numero[0],1);
	while (start==0) {

		if(SourisCliquee()) {
			x=_X;
			y=_Y;
			

			if(( x>460 && x<510)  && (y>245 && y<295) )	{
		if(taille>8) {
			taille--;
		} else {
		x++;
		y++;
		taille++;
		sprintf(&numero[0],"%d",taille);
			
		 								/* La variable c_cache a pour couleur "white" */
		ChoisirCouleurDessin(c_cache);	/*	Je choisi la couleur c_cache pour les prochains dessins */
		RemplirRectangle(430,290,15,16); /* Met donc un rectangle blanc par dessus la taille affichée pour caché et pouvoir afficher la suivante */
										/* même principe mais avec la couleur noir */
		ChoisirCouleurDessin(c_taille);		
		EcrireTexte(430,305,&numero[0],1);

		}

		}

		if(( x>460 && x<510 )  && (y>295 && y<345))	{
		if(taille<4) {
			taille++;
		} else {
		x++;
		y++;
		taille--;
		sprintf(&numero[0],"%d",taille);
		/*numero[0]=(char) taille;*/	
										/* La variable c_cache a pour couleur "white" */
		ChoisirCouleurDessin(c_cache);	/*	Je choisi la couleur c_cache pour les prochains dessins */
		RemplirRectangle(430,290,15,16); /* Met donc un rectangle blanc par dessus la taille affichée pour caché et pouvoir afficher la suivante */
										/* même principe mais avec la couleur noir */
		ChoisirCouleurDessin(c_taille);		
		EcrireTexte(430,305,&numero[0],1);

		}	

	}	
		

		if((x>239 && x<301)  && (y>389 && y<431))	{	/*	Définit le choix solo/duo	*/
			choix=1;	/*	Solo	*/

		ChoisirCouleurDessin(c_cache);
		RemplirRectangle(350,440,40,4);
		ChoisirCouleurDessin(c_taille);
		RemplirRectangle(250,440,40,4);

		}

		if((x>339 && x<401)  && (y>389 && y<431))	{	/*	Définit le choix solo/duo	*/
			choix=2;	/*	Duo	*/

		ChoisirCouleurDessin(c_cache);
		RemplirRectangle(250,440,40,4);
		ChoisirCouleurDessin(c_taille);
		RemplirRectangle(350,440,40,4);

		}

		
		if( (x>439 && x<501) && (y>389 && y<431) ) {
			start=1;
		}

		}

		
	}

	if (choix==1) {				/*	Je fais ça pour pouvoir return à la fois la taille et le choix 	*/

		taille=taille+10;
	} else {

		if (choix==2) {
			taille=taille+20;
		}
	}

	FermerGraphique();
	
	return taille;

}