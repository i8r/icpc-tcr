static double distLinePoint(P v, P w, P p) {
	double l = dist2(v, w);
	if(l == 0) return dist(p, v);
	double t = ((p.x - v.x) * (w.x - v.x) + (p.y - v.y) * (w.y - v.y)) / l;
	if(t < 0) return dist(p, v);
	if(t > 1) return dist(p, w);
	return dist(p, new P(v.x + t * (w.x - v.x), v.y + t * (w.y - v.y)));
}	
static double dist(P p1, P p2) {
	return Math.sqrt((p1.x - p2.x) * (p1.x - p2.x)
			+ (p1.y - p2.y) * (p1.y - p2.y));
}
static double dist2(P p1, P p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
