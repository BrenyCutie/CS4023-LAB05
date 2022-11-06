//
// Created by breny on 28/10/2022.
//Checking if Number is within the specified boundarys
#include "utils.h"
int checker(float num, float ref, float tol) {
    float refLower = ref - tol;
    float refHigher = ref + tol;
    if (num >= refLower && num <= refHigher) {
        return 1;
    } else return 0;

}