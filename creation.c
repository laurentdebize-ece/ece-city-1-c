//
// Created by masao on 31/10/2022.
//

#include "creation.h"

EceCity *creationEceCity() {
    EceCity * NewEceCity = (EceCity *) malloc(sizeof(EceCity));
    NewEceCity->matricePlateau = (Sol **) malloc(NBLIGNE * sizeof(Sol *));
    for (int i = 0; i < NBLIGNE; ++i) {
        NewEceCity->matricePlateau[i] = (Sol *) malloc(NBCOLONNE * sizeof(Sol));
    }
    return NewEceCity;
}