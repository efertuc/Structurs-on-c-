template <typename T>
struct LinkedListElement {
	T data;
	LinkedListElement* next;

	LinkedListElement() {
	}

	LinkedListElement(T _data, LinkedListElement* _next) : data(_data), next(_next) {
	}
};

template <typename T>
struct LinkedList
{
	int size = 0;
	LinkedListElement<T>* head = NULL;

	bool isIndexOutOfRange(int index) {
		return index > size - 1;
	}

	bool isEmpty() {
		return size == 0;
	}

	void add(T data) {
		++size;

		LinkedListElement<T>* newElement = new LinkedListElement<T>;
		newElement->data = data;
		newElement->next = NULL;

		if (head == NULL) {
			head = newElement;
			return;
		}

		LinkedListElement<T>* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newElement;
	}

	LinkedListElement<T>* get(int index) {
		if (isIndexOutOfRange(index)) return NULL;

		LinkedListElement<T>* temp = head;
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}

		return temp;
	}

	T remove(int index) {
		--size;
		LinkedListElement<T>* temp = head;
		if (index == 0)
		{
			head = head->next;
			return temp->data;
		}

		LinkedListElement<T>* previous = get(index - 1);
		LinkedListElement<T>* deleted = previous->next;
		LinkedListElement<T>* next = deleted->next;
		previous->next = next;


		return deleted->data;
	}

	void set(int position, T item) {
		LinkedListElement<T>* previous = get(position - 1);
		LinkedListElement<T>* old = previous->next;
		LinkedListElement<T>* newItem = new LinkedListElement<T>(item, old->next);
		old = newItem;
		previous->next = newItem;
	}

	void insert(int position, T item) {
		++size;
		LinkedListElement<T>* newItem = new LinkedListElement<T>(item, get(position));
		if (position == 0) {
			head = newItem;
			return;
		}
		LinkedListElement<T>* previous = get(position - 1);
		previous->next = newItem;
	}

	void print()
	{
		cout << "-----" << endl;
		LinkedListElement<T>* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
		cout << "-----" << endl;

	}
};