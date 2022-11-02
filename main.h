#ifndef ECE_CITY_1_C_MAIN_H
#define ECE_CITY_1_C_MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



#define NBLIGNE 35
#define NBCOLONNE 45
#define FLOUZDEPART 5000

typedef struct {
    int x,y;
}Coord;

typedef struct {
    int type;
    Coord plateau;
}Sol;

typedef struct {
    int eceFlouz;
    Sol** matricePlateau;
}EceCity;

#endif //ECE_CITY_1_C_MAIN_H

