#include "initialisation.h"

void initialisationEceCity(EceCity *eceCity) {
    eceCity->eceFlouz = FLOUZDEPART;
    for (int i = 0; i < NBLIGNE; ++i) {
        for (int j = 0; j < NBCOLONNE; ++j) {
            eceCity->matricePlateau[i][j].type = 0;
            eceCity->matricePlateau[i][j].plateau.x = i;
            eceCity->matricePlateau[i][j].plateau.y = j;
        }
    }
}
