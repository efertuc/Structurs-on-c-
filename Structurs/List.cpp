template <typename T>
struct List
{
	int size = 0;
	T* data = new T[size];

	void add(T item)
	{
		data = (T*)realloc(data, (++size) * sizeof(T));
		data[size - 1] = item;
	}

	T remove(int index) {
		if (is_empty()) {
			cerr << "Queue is empty!!!";
			exit(1);
			return NULL;
		}
		if (index <= size - 1) {
			for (int i = ++index; i < size; i++)
			{
				swap(data[i - 1], data[i]);
			}
			data = (T*)realloc(data, (--size) * sizeof(T));
			return data[++index];
		}
	}

	T get(int index) {
		return data[index];
	}

	void insert(int position, T item) {
		add(item);
		for (int i = size - 1; i > position; i--)
		{
			swap(data[i], data[i - 1]);
		}
	}

	void set(int position, T item) {
		data[position] = item;
	}

	int find(T item) {
		for (int i = 0; i < size; i++)
		{
			if (data[i] == item)
				return i;
		}
		return -1;
	}

	bool is_empty() {
		return size == 0;
	}

	void print() {
		for (size_t i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}

};