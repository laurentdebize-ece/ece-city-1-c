#include "affichageConsole.h"

void afficherPlateau(EceCity* eceCity){
    for (int i = 0; i < NBLIGNE; ++i) {
        for (int j = 0; j < NBCOLONNE; ++j) {
            printf("%d ", eceCity->matricePlateau[i][j].type);
        }
        printf("\n");
    }
}
