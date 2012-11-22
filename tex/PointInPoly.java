/**
 * -1: A liegt links von BC (ausser unterer Endpunkt)
 * 0: A auf BC
 * +1: sonst
 */
public static int KreuzProdTest(double ax, double ay, double bx, double by,
		double cx, double cy) {
	if (ay == by && by == cy) {
		if ((bx <= ax && ax <= cx) || (cx <= ax && ax <= bx)) return 0;
		else return +1;
	}
	if (by > cy) {
		double tmpx = bx, tmpy = by;
		bx = cx;
		by = cy;
		cx = tmpx;
		cy = tmpy;
	}
	if (ay == by && ax == bx) return 0;
	if (ay <= by || ay > cy) return +1;
	double delta = (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
	if (delta > 0) return -1;
	else if (delta < 0) return +1;
	else return 0;
}

/**
 * Input: P[i] (x[i],y[i]); P[0]:=P[n]
 * -1: Q ausserhalb Polygon
 * 0: Q auf Polygon 
 * +1: Q innerhalb des Polygons
 */
public static int PunktInPoly(double[] x, double[] y, double qx, double qy) {
	int t = -1;
	for (int i = 0; i < x.length - 1; i++) 
		t = t * KreuzProdTest(qx, qy, x[i], y[i], x[i + 1], y[i + 1]);
	return t;
}