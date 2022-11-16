#ifndef ECE_CITY_1_C_AFFICHAGE_H
#define ECE_CITY_1_C_AFFICHAGE_H

#include "main.h"

void affichageAcceuil(EceCity *eceCity);

void affichageChoixDuMode(EceCity *eceCity);

void affichageRegles(EceCity *eceCity);

void affichageJeu(EceCity *eceCity);

void affichageParametres(EceCity *eceCity);

void faireClignoterBouton(EceCity *eceCity);

void affichageBouton(EceCity* eceCity, ALLEGRO_FONT *police);

void affichageBitmapDeFond(EceCity* eceCity, int numBitmap);

#endif //ECE_CITY_1_C_AFFICHAGE_H
