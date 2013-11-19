// intersection of p0-p1 and p2-p3.
static P intersect(P p0, P p1, P p2, P p3) {
	double a_x, a_y, b_x, b_y, r, s, t;
    a_x = p1.x - p0.x;
    a_y = p1.y - p0.y;
    b_x = p3.x - p2.x;
    b_y = p3.y - p2.y;
    
    r = (-b_x * a_y + a_x * b_y); // lines are parallel if r == 0 
    s = (-a_y * (p0.x - p2.x) + a_x * (p0.y - p2.y)) / r;
    t = ( b_x * (p0.y - p2.y) - b_y * (p0.x - p2.x)) / r;

    // remove this condition when looking at lines and not only segments 
    if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
        return new P(p0.x + (t * a_x), p0.y + (t * a_y));

    return null;
}