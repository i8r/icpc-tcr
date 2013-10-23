// returns true iff negative-weight cycle reachable
private static boolean bellmannford(Node start, int n, List<Edge> edges) {
	start.dist = 0; // others: dist = Integer.MAX_VALUE
	while (n-- > 0) { // number of nodes --> for all vertices
		for (Edge edge : edges) { // --> for all edges
			if (edge.from.dist < Integer.MAX_VALUE
					&& edge.from.dist + edge.w < edge.to.dist)
				edge.to.dist = edge.from.dist + edge.w; // update predecessor
 	}	}
  for (Edge edge : edges) {
		if (edge.from.dist < Integer.MAX_VALUE
				&& edge.from.dist + edge.w < edge.to.dist)
			return true;
	}
	return false;
}
class Node {}
class Edge {
	Node from, to;
	int w;
	public Edge(Node from, Node to, int w) {
		this.from = from; this.to = to; this.w = w;
	}
}
