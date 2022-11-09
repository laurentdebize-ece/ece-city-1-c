#include "main.h"
#include "affichage.h"
#include "creation.h"
#include "initialisation.h"

int main() {
    EceCity *eceCity = creationEceCity();
    initialisationEceCity(eceCity);
    afficherPlateau(eceCity);

    return 0;
}