#include <stdio.h>
#include <stdlib.h>

int lis( int *list, int n){
    int *sorted = malloc( n*sizeof(int)), sorted_n;
    int i, *lower, *upper, *mid, *pos;

    if( n == 0) return 0;

    sorted[0] = list[0];
    sorted_n = 1;

    for( i=1; i<n; i++){
        /* binaere Suche */
        lower = list;
        upper = list + sorted_n;
        mid = list + sorted_n / 2;


        while( lower < upper-1){
            if( list[i] < *mid){
                upper = mid;
            } else {
                lower = mid;
            }

            mid = lower + (upper-lower) / 2;
        }
        
	if( mid == list + sorted_n -1 && *mid < list[i]){
            *mid = list[i];
            sorted_n++;
        }

        if( list[i] < *mid){
            *mid = list[i];
        }
    }

    free( sorted);

    return sorted_n;
}

