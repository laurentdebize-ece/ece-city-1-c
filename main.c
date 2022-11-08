#include "main.h"
#include "affichageConsole.h"
#include "creation.h"
#include "initialisation.h"

int main() {
    EceCity *eceCity = creationEceCity();
    initialisationEceCity(eceCity);
    afficherPlateau(eceCity);
    printf("test\n");

    return 0;
}