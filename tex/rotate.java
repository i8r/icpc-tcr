static P rotate(P origin, P p, double ccw) {
  double x = (p.x - origin.x) * Math.cos(ccw) - (p.y - origin.y) Math.sin(ccw);
  double y = (p.x - origin.x) * Math.sin(ccw) + (p.y - origin.y) Math.cos(ccw);
  return new P(x, y);
}
  
