List<P> hull = graham(list);
maxDist(hull);

static double maxDist(List<P> hull) {
	double max = 0, tmp = 0, tmpnew = 0;
	int j = 2, n = hull.size();
	if (n == 2) return dist(hull.get(0), hull.get(1)); // n > 2
	for (int i = 0; i < n; i++) {
		while (true) {
			tmp = distLinePoint(hull.get(i), hull.get((i + 1) % n), hull.get(j));
			tmpnew = distLinePoint(hull.get(i), hull.get((i + 1) % n), hull.get((j + 1) % n));
			if (tmpnew >= tmp) {
				j++; j %= n;
			} else break;
		} max = Math.max(max, dist(hull.get((i + 1) % n), hull.get(j)));
	} return max;
}