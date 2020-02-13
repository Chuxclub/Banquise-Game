#include <stdio.h>
#include <stdlib.h>

#define FLOE_SIZE 5

typedef struct
{
    int ice;
    int player;
    int object;
    int A;
    int B;
} square;

typedef struct
{
    square **square;
    int size;
}floe;

floe init_floe(int size)
{
    floe res_floe;

    res_floe.size = size;
    res_floe.square = (square **) malloc(sizeof(square *) * size);

    for(int i = 0; i < size;  i++)
        res_floe.square[i] = (square *) malloc(sizeof(square) * size);

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            res_floe.square[i][j].ice = 1;
            res_floe.square[i][j].player = 0;
            res_floe.square[i][j].object = 0;
            res_floe.square[i][j].A = 0;
            res_floe.square[i][j].B = 0;
        }

    }

    return res_floe;
}

void printFloe(floe *user_floe)
{
    //Upper line
    printf("\n");
    for(int i = 0; i < user_floe->size * 4 + 1; i++)
        printf("-");

    //Floe
    int counter = user_floe->size;

    for(int i = 0; i < user_floe->size; i++)
    {
        for(int j = 0; j < user_floe->size; j++)
        {
            if(counter == user_floe->size)
            {
                printf("\n");
                printf("| ");
                counter = 0;
            }

            if(user_floe->square[i][j].ice == 1)
                printf("# | ");

            counter++;
        }
    }

    //Down line
    printf("\n");
    for(int i = 0; i < user_floe->size * 4 + 1; i++)
        printf("-");

    //Newline
    printf("\n");
}

int main()
{
    //printf("Hey!");
    floe myFloe = init_floe(FLOE_SIZE);

    //printf("Taille banquise: %i", myFloe.square[0][0].ice);

    printFloe(&myFloe);

    return 0;
}