//
//  altitude_file_alloc.c
//  Raise_the_terrain
//
//  Created by Nicholas Boutboul on 12/17/17.
//  Copyright © 2017 Raid Co. All rights reserved.
//

#include "iso_met.h"

int **altitude_grid(char *alt_file_path)
{
    int **grid;
    char *tok;
    char line[BUFF_SIZE];
    FILE *alt_file;
    int i = 0, j = 0;
    
    alt_file = fopen(alt_file_path, "r");
    
    grid = malloc(sizeof(int *) * GRID_SIZE);
    
    while(i < GRID_SIZE)
        grid[i] = malloc(sizeof(int) * GRID_SIZE), i++;
    
    for(i = 0; i < GRID_SIZE; i++)
        for(j = 0;j < GRID_SIZE ; j++)
            grid[i][j]=0;
    
    if(grid == NULL)
        return NULL;
    
    i = 0;
    while (fgets(line, sizeof(line), alt_file) != NULL)
    {
//        printf("line[%s]", line);

        j = 0, tok = strtok(line, " ");
        while (tok != NULL)
        {
//            printf("tok[%s]", tok);
            grid[i][j] = atoi(tok);
            tok = strtok(NULL, " ");
            j++;
//            printf("tokaft[%d]", grid[i][j - 1]);
        }
        i++;
    }
    
    for(i = 0; i < GRID_SIZE; i++)
    {
        for(j = 0; j < GRID_SIZE; j++)
        {
            printf("%d ",grid[i][j]);
            if(GRID_SIZE < GRID_SIZE - 1)
                printf("\t");
        }
        printf("\n");
    }

    fclose(alt_file);
    return grid;
}

void free_alt_grid(int **grid)
{
    int i = 0;
    
    while(i < GRID_SIZE)
        free(grid[i]), i++;

    free(grid);
}
