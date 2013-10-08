class P {
	double x, y;

	P(double x, double y) {
		this.x = x;
		this.y = y;
	}
	// polar coordinates (not used in graham scan)
	double r() { return Math.sqrt(x * x + y * y); }
	double d() { return Math.atan2(y, x); }
}

// turn is counter-clockwise if > 0; collinear if = 0; clockwise else
static double ccw(P p1, P p2, P p3) {
	return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

static List<P> graham(List<P> l) {
	if (l.size() < 3)
		return l;
	P temp = l.get(0);
	for (P p : l)
		if (temp.y > p.y || temp.y == p.y && temp.x > p.x)
			temp = p;
	final P start = temp; // min y (then leftmost)

	Collections.sort(l, new Comparator<P>() {
		public int compare(P o1, P o2) {
			if (new Double(Math.atan2(o1.y - start.y, o1.x - start.x)) // same angle
					.compareTo(Math.atan2(o2.y - start.y, o2.x - start.x)) == 0)
				return new Double((o1.x - start.x) * (o1.x - start.x)
						+ (o1.y - start.y) * (o1.y - start.y))
						.compareTo((o2.x - start.x) * (o2.x - start.x)
						+ (o2.y - start.y) * (o2.y - start.y)); // use distance
			return new Double(Math.atan2(o1.y - start.y, o1.x - start.x)) 
					.compareTo(Math.atan2(o2.y - start.y, o2.x - start.x));
		}
	});
	Stack<P> s = new Stack<P>();
	s.add(start);
	s.add(l.get(1));
	for (int i = 2; i < l.size(); i++) {
		while (s.size() >= 2
				&& ccw(s.get(s.size() - 2), s.get(s.size() - 1), l.get(i)) <= 0)
			s.pop();
		s.push(l.get(i));
	}
	return s;
}