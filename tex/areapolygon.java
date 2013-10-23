// area of a polygon, e.g. area(graham(list))
static double area(List<P> l) {
	double sum = 0;
	// points must be in ccw order, otherwise negative area returned
	for (int i = 0; i < l.size(); i++) {
		sum += l.get(i).x * l.get((i + 1) % l.size()).y;
		sum -= l.get(i).y * l.get((i + 1) % l.size()).x;
	}
	return sum / 2;
}
