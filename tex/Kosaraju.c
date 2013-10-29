#define POS(X,Y) ((X)+size*(Y))
#define M(X,Y) (M[POS((X),(Y))])

int *top;
int *color;

void Kosaraju( int *M, int size);
void DFS( int *M, int u, int size);
void RDFS( int *M, int u, int size, int colorN);

void Kosaraju( int *M, int size){
	int i;
	int *stack = malloc( size * sizeof(int));
	top = stack;

	for(i=0;i<size;i++)
		color[i] = 0;

	for(i=0;i<size;i++){
		if(color[i] != 0) continue;
		
		DFS(M,i,size);
	}

	for(i=0;i<size;i++)
		color[i] = 0;
		
	int colorN = 1;

	while( top > stack ){
		int v = *(--top);
		if( color[v] != 0 ) continue;
		RDFS( M, v, size, colorN++);
	}
	
	free( stack);
}

void DFS( int *M, int u, int size){
	int v;
	color[u] = 1;
	for(v=0;v<size;v++){
		if( M(u,v) && color[v] == 0){
			DFS( M, v, size);
		}
	}

	*top++ = u;
}

void RDFS( int *M, int u, int size, int colorN){
	int v;
	color[u] = colorN;
	for(v=0;v<size;v++){
		if( M(v,u) && color[v] == 0){
			RDFS( M, v, size, colorN);
		}
	}
}

