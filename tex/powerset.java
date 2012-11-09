static <T> Iterator<List<T>> powerSet(final List<T> l) {
	return new Iterator<List<T>>() {
		int i; // careful: i becomes 2^l.size()
		public boolean hasNext() {
			return i < (1 << l.size());
		}
		public List<T> next() {
			Vector<T> temp = new Vector<T>();
			for (int j = 0; j < l.size(); j++)
				if (((i >>> j) & 1) == 1)
					temp.add(l.get(j));
			i++;
			return temp;
		}
		public void remove() {}
		};
	}