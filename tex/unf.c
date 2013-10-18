// Only the tree root is stored. The edges must be stored separately.
// Path compression and union by rank

int *par = (int *) malloc(n * sizeof(int));
int *rank = (int *) malloc(n * sizeof(int));

// Create new forest of n vertices
void init(int n, int *par, int *rank) {
  int i;
  for (i = 1; i <= n; i++) {
    par[i] = i; // every vertex is its on root
    rank[i] = 0;
  }
}

// Union two trees which contain x and y respectively, returns new root
int union(int n, int *par, int *rank, int x, int y) {
  y = find(n, par, y);
  x = find(n, par, x);
  if (rank[x] > rank[y]) return par[y] = x;
  if (rank[x] < rank[y]) return par[x] = y;
  rank[x]++; // rank[x] == rank[y]
  return par[y] = x;
}

// Find the tree root of x
int find(int n, int *par, int x) {
  // if parent is not a tree root
  if (par[x] != par[par[x]]) par[x] = find(n, par, par[x]);
  return par[x];
}

