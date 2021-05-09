#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>

int gen_rand(unsigned int from, unsigned int to) {	/*	génere une position x/y aléatoire pour le bot 	*/

	int i;

	
	i = rand()%(to-from+1) + from;
	

	return i;
}