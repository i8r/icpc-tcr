HashMap<Integer, List<Edge>> graph = new HashMap<Integer, List<Edge>>();
for (int i = 0; i < n; i++) graph.put(i, new ArrayList<Edge>());
int dist[] = new int[n];
Arrays.fill(dist, Integer.MAX_VALUE);
int shortest = dijkstra(source, dest, graph, dist);

static int dijkstra(int s, int d, HashMap<Integer, List<Edge>> graph, final int[] dist) {
	dist[s] = 0;
	TreeSet<Integer> queue = new TreeSet<Integer>(
			new Comparator<Integer>() {
				public int compare(Integer o1, Integer o2) {
					if (dist[o1] == dist[o2]) return o1.compareTo(o2);
					return ((Integer) o1).compareTo(o2);
			} });
	queue.add(s);
	while (queue.size() > 0) { // || queue.first() != d) {
		int c = queue.pollFirst();
		for (Edge e : graph.get(c)) {
			if (dist[e.to] > dist[c] + e.val) {
				queue.remove(e.to);
				dist[e.to] = dist[c] + e.val;
				queue.add(e.to);
	}	} }
  return dist[d];
}

class Edge {
	int from, to, val;
	public Edge(int from, int to, int val) {
		this.from = from;
		this.to = to;
		this.val = val;
} }
