// area of a convex polygon, i.e. area(graham(list))
static double area(List<P> l) {
	double sum = 0;
	for (int i = 0; i < l.size(); i++) { // points must be in ccw order
		sum += l.get(i).x * l.get((i + 1) % l.size()).y;
		sum -= l.get(i).y * l.get((i + 1) % l.size()).x;
	}
	return sum / 2;
}
