#ifndef ECE_CITY_1_C_JEU_H
#define ECE_CITY_1_C_JEU_H

#include "main.h"

void bouclePrincipale(EceCity *eceCity);

void menuAcceuil(EceCity *eceCity);

void menuChoixDuMode(EceCity *eceCity);

void menuJeu(EceCity *eceCity);

void menuParametres(EceCity *eceCity);

bool verifSiEspaceBatiment(EceCity *eceCity);

void construireBatiment(EceCity *eceCity);

void changerCompteurConstruction(EceCity *eceCity);

bool verifSiRouteACote(EceCity *eceCity);

void gereDepEau(EceCity *eceCity);

void detectionSouris(EceCity *eceCity);

void boutonPresse(EceCity *eceCity);

void deplacerPlateau(EceCity *eceCity);

void ajouterBatimentTab(EceCity *eceCity);

void parcourBFSCentrales(EceCity *eceCity);

void remonterParPredEtCompterDistanceElec(EceCity *eceCity);

void parcourBFSChateauDeau(EceCity *eceCity);

void gereDepElec(EceCity *eceCity);

void remonterParPredEtCompterDistanceEau(EceCity *eceCity);

#endif //ECE_CITY_1_C_JEU_H