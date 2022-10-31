#include "main.h"

int main() {
    EceCity *eceCity = creationEceCity();
    initialisationEceCity(eceCity);
    afficherPlateau(eceCity);
    return 0;
}