/* die folgende Zeile anpassen! */

#define N_MAX 30*30+30

/* hier drunter nichts anfassen! */
/* ----------------------------- */
#define SIZE_MAX (N_MAX+2)
#define SIZE (N+2)
#define QUELLE (N)
#define SENKE (N+1)
extern int capacity[SIZE_MAX][SIZE_MAX];
extern int N;

int maxFlow();
void reset();