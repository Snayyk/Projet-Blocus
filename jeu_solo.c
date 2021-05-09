#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "gen_rand.h"
#include "adjacente.h"
#include "remplissage_carre.h"
#include "remplissage_pion1.h"
#include "remplissage_pion2.h"
#include "remplissage_croix1.h"
#include "remplissage_croix2.h"

int jeu_solo (int taille) {	/*	Fonction qui intègre les règles du jeu pour une partie avec un bot	*/
	/*	Les cases du tableau auront 3 états possibles : 0,1,2.	
		A zéro, la case est bloquée, à "un" un pion est sur la case, et à deux la case est libre.	*/
	int grille[taille][taille],l, h, fin, o, j, i, i2, z,position_x, position_y, position_xtab, position_ytab, x=((taille*60)/2), y=70, l_et_h=60,flag=0, remove_x, remove_y, remove_xtab, remove_ytab, remove_x2, remove_y2, remove_xtab2, remove_ytab2,nombre_tour,adjacent,test_x,test_y,gagnant,x_bot,y_bot,tab_xbot,tab_ybot;
	couleur c_cache;

	remplissage_carre(taille);
	for (h = 0; h < taille; h++)
	
	{
		for (l = 0; l < taille; l++) 
		{
			grille[l][h] = 2;
		}
	}


	for(i=0,i2=0,fin=0,z=1,nombre_tour=0;fin<1000;z++) {	/*	1001/1002 sont les valeurs qui détermineront la victoire de tel joueur	*/
		flag=0;
		
		
		if(z==5) {
			z=1;
			
		}

		
		while(flag != 1) {
			
		if(z==1 || z==2) {

		if(SourisCliquee()) {
		position_x=_X;	
		position_y=_Y;
		position_xtab=((position_x-x)/l_et_h);
		position_ytab=((position_y-y)/l_et_h);
		if((position_x>x && position_x<(x+(taille*l_et_h)) ) && (position_y>y && position_y<(y+(taille*l_et_h)))) { /*	Je teste si on est dans le plateau	*/

			if( nombre_tour==0 && z==1) {

				if ( position_ytab==taille-1  && (position_xtab>=0  && position_xtab<=taille-1  )) {

					grille[position_xtab][position_ytab]=1;
					remplissage_pion1(taille, position_x, position_y);
					remove_xtab=position_xtab;
					remove_ytab=position_ytab;
					remove_x=(position_xtab*l_et_h)+x;
					remove_y=(position_ytab*l_et_h)+y;
					i++;

					flag=1;
					nombre_tour++;
					
					
				}
			}

			

			

				if(grille[position_xtab][position_ytab]==2) {
					
					
					if(z==1) {
					
						if(z==1 && nombre_tour!=0) {

							
							adjacent=adjacente(remove_xtab,remove_ytab,position_xtab,position_ytab);

								if(adjacent==1) {
									

										if(z==1 && nombre_tour==10) {
									/*	Pion blanc	*/
											if(i>0){
											grille[remove_xtab][remove_ytab]=2;
											c_cache=CouleurParNom("white");	
											ChoisirCouleurDessin(c_cache);	
											RemplirRectangle(remove_x+1,remove_y+1,57,59);

											}

										grille[position_xtab][position_ytab]=1;
										remplissage_pion1(taille, position_x, position_y);
										remove_xtab=position_xtab;
										remove_ytab=position_ytab;
										remove_x=(position_xtab*l_et_h)+x;
										remove_y=(position_ytab*l_et_h)+y;
										i++;
										nombre_tour=11;
										flag=1;
										
										
										}

								}


						}	

					


					}

						if(z==2) {	/*	Croix rouge	*/
						grille[position_xtab][position_ytab]=0;
						remplissage_croix1(taille, position_x, position_y);
						flag=1;
						
						
						}

						

						
				
					
					}
			}


		}
	}
			if(z==3 || z==4) {

			x_bot=gen_rand(x,x+taille*l_et_h);
			y_bot=gen_rand(y,y+taille*l_et_h);
			
			tab_xbot=((x_bot-x)/l_et_h);
			tab_ybot=((y_bot-y)/l_et_h);
			

			if( nombre_tour==1 && z==3) {

				if ( tab_ybot==0  && (tab_xbot>=0  && tab_xbot<=taille-1  )) {
					
					if(grille[tab_xbot][tab_ybot]==2) {

					grille[tab_xbot][tab_ybot]=1;
					remplissage_pion2(taille, x_bot, y_bot);
					remove_xtab2=tab_xbot;
					remove_ytab2=tab_ybot;
					remove_x2=(tab_xbot*l_et_h)+x;
					remove_y2=(tab_ybot*l_et_h)+y;
					i2++;

					flag=1;
					
					
					nombre_tour=10;
					}
				}
			}


				if(grille[tab_xbot][tab_ybot]==2) {

					if(z==3 && nombre_tour!=1) {

							

							adjacent=adjacente(remove_xtab2,remove_ytab2,tab_xbot,tab_ybot);

								if(adjacent==1) {
									

									if(z==3 && nombre_tour==11) {  /*	Pion noir	*/

										if(i2>0){

										grille[remove_xtab2][remove_ytab2]=2;
										
										ChoisirCouleurDessin(c_cache);	
										RemplirRectangle(remove_x2+1,remove_y2+1,57,59);

										}

									grille[tab_xbot][tab_ybot]=1;
									remplissage_pion2(taille, x_bot, y_bot);
									remove_xtab2=tab_xbot;
									remove_ytab2=tab_ybot;
									remove_x2=(tab_xbot*l_et_h)+x;
									remove_y2=(tab_ybot*l_et_h)+y;
									i2++;
									nombre_tour=10;
									flag=1;
								
									
									}

								}

							
					}

						if(z==4) {  /*	Croix noir	*/
						grille[tab_xbot][tab_ybot]=0;
						remplissage_croix2(taille, x_bot, y_bot);
						flag=1;
						
						
						
						}

				}

			}
		
		} /* fin boucle while */

		if(nombre_tour>=10) {
			
			for(fin=0,test_x=remove_xtab-1,o=0;o<3;o++,test_x++) {
		
				
				for(test_y=remove_ytab-1,j=0;j<3;j++,test_y++) {

					if(o==0 && j==0 && (remove_xtab==0 || remove_xtab==taille-1) && (remove_ytab>0 && remove_ytab<taille-1) ){

							fin=fin+3;
							
							

						}

						if(o==0 && j==0 && (remove_ytab==0 || remove_ytab==taille-1) && (remove_xtab>0 && remove_xtab<taille-1) ){

							fin=fin+3;
							
							
						}

						if(o==0 && j==0 && (remove_xtab==0 || remove_xtab==taille-1) && (remove_ytab==0 || remove_ytab==taille-1) ){

							fin=fin+5;
							
							
						}


					if(grille[test_x][test_y]!=2) {

						if( (test_x>=0 && test_x<=taille-1) && (test_y>=0 && test_y<=taille-1) ) {
							fin++;	
							}
					}
						

						if (fin==9){

							fin=1001;	/*	Défaite du joueur 1	*/
							
						}
					
				}
			}
			

			if(fin!=1001) {
				for(fin=0,test_x=remove_xtab2-1,o=0;o<3;o++,test_x++) {


					
					
					for(test_y=remove_ytab2-1,j=0;j<3;j++,test_y++) {

						if(o==0 && j==0 && (remove_xtab2==0 || remove_xtab2==taille-1) && (remove_ytab2>0 && remove_ytab2<taille-1) ){

							fin=fin+3;
							
							

						}

						if(o==0 && j==0 && (remove_ytab2==0 || remove_ytab2==taille-1) && (remove_xtab2>0 && remove_xtab2<taille-1) ){

							fin=fin+3;
							
							
						}

						if(o==0 && j==0 && (remove_xtab2==0 || remove_xtab2==taille-1) && (remove_ytab2==0 || remove_ytab2==taille-1) ){

							fin=fin+5;
							
							
						}

						if(grille[test_x][test_y]!=2) {
							if( (test_x>=0 && test_x<=taille-1) && (test_y>=0 && test_y<=taille-1) ) {
							fin++;	
							}
							

						}
						
						if (fin==9){

							fin=1002;	/*	Défaite du joueur 2	*/
							
						}
						
					}
				}
			}
			
		}

			

			

			

			

	}/*Fin boucle for*/

			if (fin==1001) {

				gagnant=2;

			} else {
				gagnant=1;

			}

			
			

			return gagnant;
}