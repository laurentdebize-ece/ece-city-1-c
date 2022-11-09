#include "main.h"
#include "affichage.h"
#include "jeu.h"
#include "initialisation.h"

int main() {
    EceCity *eceCity = creationEceCity();

    initialisationAll(eceCity);

    BouclePrincipale(eceCity);

    return 0;
}