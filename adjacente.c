#include <stdio.h>
#include <stdlib.h>

int adjacente(int old_x,int old_y,int x,int y) { /*	Fonction qui va déterminer si la case cliquée/généré aléatoirement est adjacente au pion	*/

	int adjacent=0;

	if (x==old_x && y==old_y+1) {

		adjacent=1;
	}

	if (x==old_x && y==old_y-1) {

		adjacent=1;

	}

	if (x==old_x+1 && y==old_y) {

		adjacent=1;
	}

	if (x==old_x-1 && y==old_y) {

		adjacent=1;
	}

	if (x==old_x+1 && y==old_y+1) {

		adjacent=1;
	}

	if (x==old_x+1 && y==old_y-1) {

		adjacent=1;
	}

	if (x==old_x-1 && y==old_y+1) {

		adjacent=1;
	}

	if (x==old_x-1 && y==old_y-1) {

		adjacent=1;
	}



	return adjacent;
}
