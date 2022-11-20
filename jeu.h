#ifndef ECE_CITY_1_C_JEU_H
#define ECE_CITY_1_C_JEU_H

#include "main.h"

void bouclePrincipale(EceCity*eceCity);

void menuAcceuil(EceCity*eceCity);

void menuChoixDuMode(EceCity* eceCity);

void menuJeu(EceCity*eceCity);

void menuParametres(EceCity* eceCity);

bool verifSiEspaceBatiment(EceCity* eceCity, int x, int y);

void construireBatiment(EceCity* eceCity);

void detectionSouris(EceCity*eceCity);

void boutonPresse(EceCity*eceCity);

void deplacerPlateau(EceCity *eceCity);

#endif //ECE_CITY_1_C_JEU_H