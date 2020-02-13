//
// Created by florian on 13/02/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "banquise.h"
#include "termcolor.h"

#define RAND_MAX 101

//Crée un simple tableau de glace uniquement
T_banquise initBanquise(int size)
{
    T_banquise res;

    res.size = size;
    res.square = (T_case **) malloc(sizeof(T_case *) * size);

    for(int i = 0; i < size;  i++)
        res.square[i] = (T_case *) malloc(sizeof(T_case) * size);

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            res.square[i][j].ice = 1;
            res.square[i][j].player = 0;
            res.square[i][j].object = 0;
            res.square[i][j].A = 0;
            res.square[i][j].B = 0;
        }

    }

    return res;
}

//Ajoute de l'eau aléatoirement dans la banquise, remplace la glace
void addWater(T_banquise *banquise)
{
    srand(time(NULL));

    for(int i = 0; i < banquise->size; i++)
    {
        for(int j = 0; j < banquise->size; j++)
        {
            int loto = rand() % RAND_MAX;

            if(loto < 20)
                banquise->square[i][j].ice = 0;
        }
    }
}


//Ajoute des rochers aléatoirement sur la banquise, remplace la glace
//Mais ne remplace pas l'eau! Code pour rocher: object = 1
void addRocks(T_banquise *banquise)
{
    srand(time(NULL));

    for(int i = 0; i < banquise->size; i++)
    {
        for(int j = 0; j < banquise->size; j++)
        {
            int loto = rand() % RAND_MAX;

            if(loto < 25 && banquise->square[i][j].ice == 1)
                banquise->square[i][j].object = 1;
        }
    }
}

//Affiche l'état de la banquise à l'instant de son appel
void printBanquise(T_banquise *banquise)
{
    //Upper line
    printf("\n");
    for(int i = 0; i < banquise->size * 4 + 1; i++)
        printf("-", text_white(stdout));

    //Floe
    int counter = banquise->size;

    for(int i = 0; i < banquise->size; i++)
    {
        for(int j = 0; j < banquise->size; j++)
        {
            if(counter == banquise->size)
            {
                printf("\n");
                printf("| ", text_white(stdout));
                counter = 0;
            }

            if(banquise->square[i][j].object == 1)
            {
                printf("o", text_yellow(stdout));
                printf(" | ", text_white(stdout));
            }


            else if(banquise->square[i][j].ice == 1)
            {
                printf("#", text_bold(stdout));
                printf(" | ", text_white(stdout));
            }

            else if(banquise->square[i][j].ice == 0)
            {
                printf("~", text_blue(stdout));
                printf(" | ", text_white(stdout));
            }

            counter++;
        }
    }

    //Down line
    printf("\n");
    for(int i = 0; i < banquise->size * 4 + 1; i++)
        printf("-");

    //Newline
    printf("\n");
}