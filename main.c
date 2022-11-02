#include "main.h"
#include "creation.h"
#include "initialisation.h"
#include "affichageConsole.h"

int main() {
    EceCity *eceCity = creationEceCity();
    initialisationEceCity(eceCity);
    afficherPlateau(eceCity);
    printf("test\n");
    return 0;
}