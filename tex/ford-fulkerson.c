#include <stdio.h>
#include <limits.h>

#define n_MAX 36
#define m_MAX 30
#define SIZE (m+6+2)
#define SIZE_MAX 38
#define QUELLE (m+6)
#define SENKE (m+7)
#define NONE -1
#define INF INT_MAX/2

int n, m;
int capacity[SIZE_MAX][SIZE_MAX];
int flow[SIZE_MAX][SIZE_MAX];
int queue[SIZE_MAX], *head, *tail;
int state[SIZE_MAX];
int pred[SIZE_MAX];

enum { XS, S, M, L, XL, XXL };
enum { UNVISITED, WAITING, PROCESSED };

int strToOffset( char *str);
int maxFlow( int quelle, int senke);

int main(){

    int numOfProps;
    scanf("%d\n", &numOfProps);
    
    while( numOfProps--){
        scanf("%d %d\n", &n, &m);
        
        int i, j;
        
        /* Matrix initialisieren */
        for( i=0; i< SIZE; i++){
            for( j=0; j< SIZE; j++){
                capacity[i][j] = flow[i][j] = 0;
                
                if( i == QUELLE && j < m){
                    capacity[i][j] = 1;
                    continue;
                }
                
                if( j == SENKE && i >= m && i < QUELLE){
                    capacity[i][j] = n/6;
                    continue;
                }
            }
        }
        
        char str[4];
        
        /* Matrix einlesen */
        for( i=0; i< m; i++){
            scanf("%s", str);
            capacity[i][m+strToOffset(str)] = 1;
            scanf("%s", str);
            capacity[i][m+strToOffset(str)] = 1;
        }
        
        
        int foo = maxFlow( QUELLE, SENKE);
        printf("%s\n", foo >= m ? "YES" : "NO");
        
    }

    return 0;
}

int strToOffset( char *str){
    /*snip*/
}

void enqueue( int x){
    *tail++ = x;
    state[x] = WAITING;
}

int dequeue(){
    int x = *head++;
    state[x] = PROCESSED;
    return x;
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

int maxFlow( int quelle, int senke){
    int max_flow = 0;
    
    int u;
    
    while( bfs( quelle, senke)){
        int increment = INF, temp;
        
        for( u= senke; pred[u] != NONE; u = pred[u]){
            temp = capacity[pred[u]][u] - flow[pred[u]][u];
            if( temp < increment){
                increment = temp;
            }
        }
        
        for( u= senke; pred[u] != NONE; u = pred[u]){
            flow[pred[u]][u] += increment;
            flow[u][pred[u]] -= increment;
        }
        
        max_flow += increment;
    }
    
    return max_flow;
}
