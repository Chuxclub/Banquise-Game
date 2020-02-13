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
} T_case;

typedef struct
{
    T_case **square;
    int size;
}T_banquise;

T_banquise init_floe(int size)
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

void printFloe(T_banquise *banquise)
{
    //Upper line
    printf("\n");
    for(int i = 0; i < banquise->size * 4 + 1; i++)
        printf("-");

    //Floe
    int counter = banquise->size;

    for(int i = 0; i < banquise->size; i++)
    {
        for(int j = 0; j < banquise->size; j++)
        {
            if(counter == banquise->size)
            {
                printf("\n");
                printf("| ");
                counter = 0;
            }

            if(banquise->square[i][j].ice == 1)
                printf("# | ");

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

int main()
{
    //printf("Hey!");
    T_banquise myFloe = init_floe(FLOE_SIZE);

    //printf("Taille banquise: %i", myFloe.square[0][0].ice);

    printFloe(&myFloe);

    return 0;
}