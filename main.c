#include <stdio.h>
#include <stdlib.h>
#include "banquise.h"

#define BANQUISE_SIZE 6

int main()
{
    T_banquise myBanquise = initBanquise(BANQUISE_SIZE);
    addWater(&myBanquise);
    addRocks(&myBanquise);
    printBanquise(&myBanquise);

    return 0;
}