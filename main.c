#include "main.h"
#include "affichage.h"
#include "jeu.h"
#include "initialisation.h"

int main() {
    srand(time(NULL));

    initBiblioAllegro();

    EceCity *eceCity = creationEceCity();

    initialisationAll(eceCity);

    bouclePrincipale(eceCity);

    for (int i = 0; i < NBLIGNE; ++i) {
        for (int j = 0; j < NBCOLONNE; ++j) {
            if (eceCity->matricePlateau[i][j].firstMaison) {
                printf("%d:%d\n", j, i);
            }
        }
    }

    destroyAll(eceCity);

    return 0;
}
