#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


/*  berechnet alle "Streifen" also
    1: 0, 1, 2, 3, ... , n-1
    2: 0-1, 1-2, 2-3, ... , (n-2)-(n-1)
    3: 0-2, 1-3, 2-4, ... , (n-3)-(n-1)
    ...
    n: 0-(n-1) */
void parts( int *base, int* sums, int n){
	int sum = 0, i, j, *prefix = malloc( n * sizeof(int));
	
	/* kopiere alle Streifen der Laenge 1 */
	memcpy( sums, base, n* sizeof(int));
	
	/* Präfixsummen berechnen */
	for( i=0; i< n; i++){
		prefix[i] = sum += base[i];
	}
	
	/* Alle Streifen der Lange i=2 bis n brechnen */
	sums += n;
	for( i=2; i<= n; i++){
        *sums++ = prefix[i-1]; /* Streifen 0 bis i */
        
		for( j=1; j< n-i+1; j++){
            /* Streifen j bis i+j */
			*sums++ = prefix[j+i-1] - prefix[j-1];
		}
	}
	
	/* Speicher freigeben */
	free(prefix);
}

int main(){
	int n;
	
	while( scanf("%d", &n) != EOF){
        
        int *matrix = malloc( n*n*sizeof(int)), *m = matrix,
            i=n*n, j, size = n*(n+1)/2, globalmax = INT_MIN;
        
        /* Matrix einlesen */
        while( i--){
        	scanf("%d", m++);
        }
        
        /* last enthält die Summen aller "Streifen" der vorherigen Zeile.
           curr enthält die Streifen der aktuellen Zeile */
        int *last = calloc( n* (n+1) / 2 , sizeof(int)),
            *curr = malloc( n* (n+1) / 2 * sizeof(int));
        
        /* iteriere über alle Zeilen */
        for(j=0; j<n; j++){
        
            /* berechne die Streifen der aktuellen zeile */
            parts(matrix+ j*n, curr, n);
            
            /* fasse die aktuellen und die vorherigen Streifen zusammen */
            for( i=0; i< size; i++){
            
                if( curr[i] + last[i] < 0){                
                    /* falls wir unter 0 geraten, ist es günstiger ein
                       neues Rechteck anzufangen */
                    last[i] = 0;                    
                } else {                
                    /* Den aktuellen Streifen zum Rechteck dazu addieren */
                    last[i] += curr[i];                    
                }
                
                /* eventuell haben wir eine neues globales Maximum */
                if( last[i] > globalmax ){
                    globalmax = last[i];
                }
            }
        }
        
        /* globales Maximum ausgeben */
        printf("%d\n", globalmax);
        
        /* Speicher freigeben */
        free( last);
        free( curr);
        free( matrix);
	}
	
	return EXIT_SUCCESS;
}
