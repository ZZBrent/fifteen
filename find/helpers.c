/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    //Your implementation must return false immediately if n is non-positive.

    //Your implementation must return true if value is in values and false if value is not in values.

    //The running time of your implementation must be in O(log n).
    if(n < 0) {
        return false;
    }
    else {
        //M is the remaining elements to check (lower bound), n is total elements (upper bound).
        int m = 0;
        while (n >= m) {
            if(values[(n+m)/2] == value) {
                return true;
            }
            else if(values[(n+m)/2] <= value) {
                m = ((n+m)/2) + 1;
            }
            else if(values[(n+m)/2] >= value) {
                n = ((n+m)/2) - 1;
            }
            else {
                return false;
            }
        }
        return false;
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int countingArray[65537] = { 0 };
    for(int i = 0; i < n; i++) {
        countingArray[values[i]] += 1;
    }
    int arrayIndex = 0;
    for(int m = 0; m < 65537; m++) {
        while(countingArray[m] != 0) {
            values[arrayIndex] = m;
            countingArray[m]--;
            arrayIndex++;
        }
    }
    return;
}
