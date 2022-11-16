#include "main.h"
#include "affichage.h"
#include "jeu.h"
#include "initialisation.h"

int main() {
    initBiblioAllegro();

    EceCity *eceCity = creationEceCity();

    initialisationAll(eceCity);

    bouclePrincipale(eceCity);

    destroyAll(eceCity);

    return 0;
}