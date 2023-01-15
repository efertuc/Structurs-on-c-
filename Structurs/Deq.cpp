template <typename T>
struct Deq
{
	int size = 0;
	T* data = new T[size];

	void push_back(T item)
	{
		data = (T*)realloc(data, (++size) * sizeof(T));
		data[size - 1] = item;
	}

	void push_front(T item) {
		push_back(item);
		for (int i = size - 1; i > 0; i--)
		{
			swap(data[i], data[i - 1]);
		}
	}

	T pop_back()
	{
		if (is_empty()) {
			cerr << "Deq is empty!!!";
			exit(1);
			return NULL;
		}
		T item = data[size - 1];
		data = (T*)realloc(data, (--size) * sizeof(T));
		return item;
	}

	T pop_front()
	{
		if (is_empty()) {
			cerr << "Deq is empty!!!";
			exit(1);
			return NULL;
		}
		T item = data[0];
		for (int i = 1; i < size; i++)
		{
			swap(data[i - 1], data[i]);
		}
		data = (T*)realloc(data, (--size) * sizeof(T));
		return item;
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