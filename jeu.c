#include "jeu.h"

void BouclePrincipale(EceCity *eceCity) {
    while (!eceCity->end) {
        switch (eceCity->phaseDeJeu) {
            case ACCEUIL: {

                break;
            }
            case JEU: {

                break;
            }
            case PARAMETRES: {

                break;
            }
            default: {
                break;
            };
        }
    }
}

void construireBatiment(EceCity eceCity, Coord coord, int tailleLongueur, int tailleLargeur, int batiment) {
    if (verifSiEspaceBatiment(eceCity, coord, tailleLongueur, tailleLargeur)) {
        for (int i = 0; i < tailleLongueur; ++i) {
            for (int j = 0; j < tailleLargeur; ++j) {
                eceCity.matricePlateau[coord.x - 1 + i][coord.x - 1 + j].type = batiment;
            }
        }
    }
}


bool verifSiEspaceBatiment(EceCity eceCity, Coord coord, int tailleLongueur, int tailleLargueur) {
    bool verifCasesVide = true;
    for (int i = 0; i < tailleLongueur; i++) {
        for (int j = 0; j < tailleLargueur; j++) {
            if (eceCity.matricePlateau[coord.x - 1 + i][coord.x - 1 + j].type != VIDE &&
                eceCity.matricePlateau[coord.x - 1 + i][coord.x - 1 + j].type != ARBRE) {
                verifCasesVide = false;
            }
        }
    }
    return verifCasesVide;
}