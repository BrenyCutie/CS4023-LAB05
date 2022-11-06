#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"

//argc = number of arguments
//argv = array of argyments




int main(int argc, char *argv[]) {


    struct tm *local;
    time_t start, end;
    time(&start); // read and record clock
    local = localtime(&start);
    printf("# Start time and date: %s", asctime(local));

    float ref;
    float tol;

    //Switches the ref and tol value depending on way its entered
    if (strcmp(argv[1], "-r") == 0) {
        ref = strtof(argv[2], NULL);
        tol = strtof(argv[4], NULL);
    } else {
        ref = strtof(argv[4], NULL);
        tol = strtof(argv[2], NULL);
    }

    //read in row/column of 2d array
    int rct;
    int cct;
    scanf("%d", &rct);
    scanf("%d", &cct);

    //allocating memory for float x rct
    float** rows = (float **) malloc(rct * sizeof(float *));
    if (rows == 0) {

        //print error
        fprintf(stderr, "Insufficient Space.\n");
        exit(1);
    }


    int i;


    //i < row
    for (i = 0; i < rct; i++) {
        //allocating memory for float x cct
        float *row = (float *) malloc(cct * sizeof(float));
        if (row == 0) {
            //print error
            fprintf(stderr, "Couldnâ€™t alocate sufficient row space.\n");
            exit(1);
        }
        //setting each row individually
        rows[i] = row;
    }

    //scans values from from standard input and puts them into an array
    for (int i = 0; i < rct; i++) {
        for (int j = 0; j < cct; j++) {
            scanf("%f", &rows[i][j]);
        }
    }

    int numOfEquals = 0;

    //if true format print out row column and value(At specified Row/Column)

    for(int i = 0; i < rct; i++){
        for(int j = 0; j<cct; j++){
            if(checker(rows[i][j], ref, tol) == 1){
                printf("r=%03d, c=%03d: %10.6f\n",i,j,rows[i][j]);
                numOfEquals++;
            }
        }
    }

    //freeing up memory

    for(int i = 0; i < rct; i++){
        free(rows[i]);
    }
    free(rows);

    //finish time

    time(&end);
    local = localtime(&end);
    printf("# END TIME& DATE : %s", asctime(local));
    exit(0);

}




