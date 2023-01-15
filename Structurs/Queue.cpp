template <typename T>
struct Queue
{
	int size = 0;
	T* data = new T[size];
	void push(T item)
	{
		data = (T*)realloc(data, (++size) * sizeof(T));
		data[size - 1] = item;
	}

	T pop()
	{
		if (is_empty()) {
			cerr << "Queue is empty!!!";
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