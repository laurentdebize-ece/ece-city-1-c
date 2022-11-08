#include "main.h"
#include "affichageConsole.h"
#include "creation.h"
#include "initialisation.h"

int main() {

    EceCity *eceCity = creationEceCity();
    initialisationEceCity(eceCity);
    afficherPlateau(eceCity);
    printf("blabllvdkvrjgv\n");

    return 0;
}