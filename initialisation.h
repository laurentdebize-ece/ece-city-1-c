#ifndef ECE_CITY_1_C_INITIALISATION_H
#define ECE_CITY_1_C_INITIALISATION_H

#include "main.h"

void initialisationAll(EceCity *eceCity);

void get_desktop_resolution(int adapter, EceCity *eceCity);

void destroyAll(EceCity *eceCity);

EceCity *creationEceCity();

void initJoueur(EceCity *eceCity);

void initBitmaps(EceCity *eceCity);

void initBiblioAllegro();

void initTabBoutons(EceCity *eceCity);

void initPolice(EceCity *eceCity);

void initPlateau(EceCity *eceCity);

void initMusique(EceCity *eceCity);

void initTabTouches(EceCity *eceCity);

void initialisationEceCity(EceCity *eceCity);

void initAllegro(EceCity *city);

#endif //ECE_CITY_1_C_INITIALISATION_H