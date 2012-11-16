static List<Integer> topoSort(Map<Integer, List<Integer>> edges,
		Map<Integer, List<Integer>> revedges) {
	Queue<Integer> q = new LinkedList<Integer>();
	List<Integer> ret = new LinkedList<Integer>();
	Map<Integer, Integer> indeg = new HashMap<Integer, Integer>();
	for (int v : revedges.keySet()) {
		indeg.put(v, revedges.get(v).size());
		if (revedges.get(v).size() == 0)
			q.add(v);
	}
	while (!q.isEmpty()) {
		int tmp = q.poll();
		ret.add(tmp);
		for (int dest : edges.get(tmp)) {
			indeg.put(dest, indeg.get(dest) - 1);
			if (indeg.get(dest) == 0)
				q.add(dest);
		}
	}
	return ret;
}