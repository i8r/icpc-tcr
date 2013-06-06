#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "flow.h"

#define NONE -1
#define INF INT_MAX/2

int N;
int capacity[SIZE_MAX][SIZE_MAX];
int flow[SIZE_MAX][SIZE_MAX];
int queue[SIZE_MAX], *head, *tail;
int state[SIZE_MAX];
int pred[SIZE_MAX];

enum { UNVISITED, WAITING, PROCESSED };

void enqueue( int x){
    *tail++ = x;
    state[x] = WAITING;
}

int dequeue(){
    int x = *head++;
    state[x] = PROCESSED;
    return x;
}

void reset(){
    int i, j;
    for(i=0; i<SIZE;i++){
        memset( capacity[i], 0, sizeof(int)*SIZE );
    }
}

int bfs( int start, int target){
    int u, v;
    for( u=0; u< SIZE; u++){
        state[u] = UNVISITED;
    }
    head = tail = queue;
    pred[start] = NONE;
    
    enqueue(start);
    
    while( head < tail){
        u = dequeue();
        
        for( v= 0; v< SIZE; v++){
            if( state[v] == UNVISITED &&
                capacity[u][v] - flow[u][v] > 0){
            
                enqueue(v);
                pred[v] = u;
            }
        }
    }
    
    return state[target] == PROCESSED;
}

int maxFlow(){
    int max_flow = 0;
    int u;

    int i, j;
    for(i=0; i<SIZE;i++){
        memset( flow[i], 0, sizeof(int)*SIZE );
    }
    
    while( bfs( QUELLE, SENKE)){
        int increment = INF, temp;
        
        for( u= SENKE; pred[u] != NONE; u = pred[u]){
            temp = capacity[pred[u]][u] - flow[pred[u]][u];
            if( temp < increment){
                increment = temp;
            }
        }
        
        for( u= SENKE; pred[u] != NONE; u = pred[u]){
            flow[pred[u]][u] += increment;
            flow[u][pred[u]] -= increment;
        }
        
        max_flow += increment;
    }
    
    return max_flow;
}
