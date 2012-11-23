static int n;
static int[][] path = new int[n][n];
static int[][] next = new int[n][n];
static void floyd(int[][] ad) {
	for (int i = 0; i < n; i++)
		path[i] = Arrays.copyOf(ad[i], n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (path[i][k] + path[k][j] < path[i][j]) {
					path[i][j] = path[i][k] + path[k][j];
					next[i][j] = k;
				}
	// there is a negative circle iff. there is a i such that path[i][i] < 0
}