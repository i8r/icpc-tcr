#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lcs( char *a, char *b){
    int len = strlen( a);
    int lenb =strlen(b);
    
    int *zeile = malloc( (len+1) * sizeof(int)), *temp, 
        *neue = malloc( (len+1) * sizeof(int)), i, j;

    for(i=0; i<len+1; i++){
        zeile[i] = neue[i] = 0;
    }
    
    for(j=0; j<lenb; j++){
        for(i=0; i<len; i++){
            if( a[i] == b[j]){
                neue[i+1] = zeile[i] + 1;
            } else {
                neue[i+1] = neue[i] > zeile[i+1] ? neue[i] : zeile[i+1];
            }
        }
        temp = zeile;
        zeile = neue;
        neue = temp;
    }

    int res = zeile[len];
    free( zeile);
    free( neue);
    return res;
}
