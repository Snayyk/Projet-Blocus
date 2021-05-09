	# CHAPITRE 1 : BUT FINAL

but : blocus

# CHAPITRE 2 : VARIABLES
EXE = blocus

OFILES = size.o \
		 remplissage_carre.o \
		 remplissage_pion1.o \
 		 remplissage_pion2.o \
		 remplissage_croix1.o \
		 remplissage_croix2.o \
		 adjacente.o \
		 gen_rand.o \
		 jeu_duo.o \
		 jeu_solo.o \
		 ecran_fin.o \
         main.o

CC = gcc

CFLAGS = -Wall -ansi -pedantic -g

# CHAPITRE 3 : DEPENDANCES (REGLES IMPLICITES)


size.o : size.h

remplissage_carre.o : remplissage_carre.h

remplissage_pion1.o : remplissage_pion1.h

remplissage_pion2.o : remplissage_pion2.h

remplissage_croix1.o : remplissage_croix1.h

remplissage_croix2.o : remplissage_croix2.h

adjacente.o : adjacente.h

gen_rand.o : gen_rand.h

jeu_duo.o : jeu_duo.h remplissage_carre.h remplissage_pion1.h remplissage_pion2.h remplissage_croix1.h remplissage_croix2.h adjacente.h

jeu_solo.o : jeu_solo.h remplissage_carre.h remplissage_pion1.h remplissage_pion2.h remplissage_croix1.h remplissage_croix2.h adjacente.h gen_rand.h

ecran_fin.o : ecran_fin.h 	

main.o : size.h remplissage_carre.h remplissage_pion1.h remplissage_pion2.h remplissage_croix1.h remplissage_croix2.h adjacente.h gen_rand.h jeu_duo.h jeu_solo.h ecran_fin.h

#CHAPITRE 4 : DEPENDANCES AVEC COMMANDES


${EXE} : $(OFILES)
	$(CC) $(CFLAGS) -o ${EXE} $(OFILES) -lgraph

#CHAPITRE 5 : NETTOYAGE DES FICHIERS GENERES

clean :
	-rm -f $(OFILES) 

#CHAPITRE 6 : BUTS FACTICES

.PHONY : but clean

run : 
	./${EXE}