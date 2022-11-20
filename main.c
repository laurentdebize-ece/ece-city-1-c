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

    destroyAll(eceCity);

    return 0;
}