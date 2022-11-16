#ifndef ECE_CITY_1_C_JEU_H
#define ECE_CITY_1_C_JEU_H

#include "main.h"

void bouclePrincipale(EceCity *eceCity);

void menuAcceuil(EceCity *eceCity);

void menuChoixDuMode(EceCity *eceCity);

void menuRegles(EceCity *eceCity);

void menuJeu(EceCity *eceCity);

void menuParametres(EceCity *eceCity);

bool verifSiEspaceBatiment(EceCity eceCity, Coord coord, int tailleLongueur, int tailleLargeur);

void construireBatiment(EceCity eceCity, Coord coord, int tailleLongueur, int tailleLargeur, int batiment);

void detectionSourisBouton(EceCity *eceCity);

#endif //ECE_CITY_1_C_JEU_H
