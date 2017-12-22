//
//  altitude_file_alloc.c
//  Raise_the_terrain
//
//  Created by Nicholas Boutboul on 12/17/17.
//  Copyright © 2017 Raid Co. All rights reserved.
//

#include "iso_met.h"

void altitude_grid(char *alt_file_path)
{
    char *tok;
//    char line[BUFF_SIZE];
    FILE *alt_file = NULL;
    int filePresent;
    char *line = NULL;
    size_t line_len = 0;
    int i = 0, j = 0;
    
    if (alt_file_path == NULL)
        filePresent = 0;
    else
        alt_file = fopen(alt_file_path, "r"), filePresent = 1;
    
    instance->alt_grid = malloc(sizeof(int *) * GRID_SIZE);
    
    while(i < GRID_SIZE)
        instance->alt_grid[i] = malloc(sizeof(int) * GRID_SIZE), i++;
    
    if(instance->alt_grid == NULL)
    {
        perror("Malloc Failed to alloc spa-ice bihatch!!!");
        return;
    }
    //NULL init for 0 alt in case of no file passed
    for(i = 0; i < GRID_SIZE; i++)
        for(j = 0;j < GRID_SIZE ; j++)
            instance->alt_grid[i][j]=0;
    
    i = 0;
    while (filePresent &&
           getline(&line, &line_len, alt_file) != -1)
    {
//        printf("line[%s]", line);

        j = 0, tok = strtok(line, " \n\t");
        while (tok != NULL)
        {
//            printf("tok[%s]", tok);
            instance->alt_grid[i][j] = atoi(tok);
            tok = strtok(NULL, " \n\t");
            j++;
//            printf("tokaft[%d]", grid[i][j - 1]);
        }
        i++;
    }
    
    for(i = 0; i < GRID_SIZE; i++)
    {
        for(j = 0; j < GRID_SIZE; j++)
        {
            printf("%d ",instance->alt_grid[i][j]);
            if(GRID_SIZE < GRID_SIZE - 1)
                printf("\t");
        }
        printf("\n");
    }
    if (alt_file)
        fclose(alt_file);
}

void free_alt_grid(void)
{
    int i = 0;
    
    while(i < GRID_SIZE)
        free(instance->alt_grid[i]), i++;

    free(instance->alt_grid);
}
