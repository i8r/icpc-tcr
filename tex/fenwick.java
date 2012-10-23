class FenwickTree {
	private int[] values;
	private int n;
	public FenwickTree(int n) {
		this.n = n;
		values = new int[n];
	}
	public int get(int i) { //get value of i
		int x = values[0];
		while (i > 0) {
			x += values[i];
			i -= i & -i; }
		return x;
	}
	public void add(int i, int x) { // add x to interval [i,n]
		if (i == 0) values[0] += x;
		else {
			while (i < n) {
				values[i] += x;
				i += i & -i; }
		}
	}
}