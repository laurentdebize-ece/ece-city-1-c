#ifndef ECE_CITY_1_C_JEU_H
#define ECE_CITY_1_C_JEU_H

#include "main.h"

void BouclePrincipale(EceCity *eceCity);

bool verifSiEspaceBatiment(EceCity eceCity, Coord coord, int tailleLongueur, int tailleLargeur);

void construireBatiment(EceCity eceCity, Coord coord, int tailleLongueur, int tailleLargeur, int batiment);

#endif //ECE_CITY_1_C_JEU_H
