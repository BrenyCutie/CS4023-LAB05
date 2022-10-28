#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//argc = number of arguments
//argv = array of argyments
int main(int argc, char* argv[]){



    //read in row/column of 2d array
int rct, cct;
scanf("%d", &rct);
scanf("%d",&cct);

//
    float** rows = (float **) malloc(rct * sizeof(float *));
    if (rows == 0)
    {
        fprintf(stderr, "Couldn’t alocate sufficient space.\n");
        exit(1);
    }
    int i;
    for (i = 0; i < rct; i++)
    {
        float* row = (float *) malloc(cct * sizeof(float));
        if (row == 0)
        {
            fprintf(stderr, "Couldn’t alocate sufficient row space.\n");
            exit(1);
        }
        rows[i] = row;
    }


}
