#include<iostream>

using namespace std;
class LinkedList
{
	private:
	struct node
	{
		string data;
		struct node *next;
	};

	node *head = NULL;
	node *tail = NULL;
	public:
	int length = 0;
	void append(string n)
	{
		node *tmp = new node;
		tmp->data = n;
		tmp->next = NULL;

		if(head == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tail->next;
		}
		length++;
	}
	void print()
	{
		node *pointer = head;
		while(pointer != NULL) {
			cout << pointer->data << " Location: " << pointer << endl;
			pointer = pointer->next;
		}
	}
	string get(int x)
	{
		node *pointer = head;
		for (int i=0; i!=x; i++) {
			if (i == x) {
				return pointer->data;
			} else {
				pointer = pointer->next;
			}
		}
		return "not found";
	}
	bool find(string fd)
	{
		node *pointer = head;
		for (int i=0; i!=length; i++) {
			if (pointer->data == fd) {
				return true;
			} else {
				pointer = pointer->next;
			}
		}
		return false;
	}
	void pop()
	{
		// I'm like... pretty sure there isn't a memory leak here.
		node *pointer = head;
		for (int i=0; i<length-2; i++) {
			pointer = pointer->next;
		}
		tail = NULL;
		delete tail;
		pointer->next = NULL;
		tail = pointer;
	}
};

int main() {
	LinkedList list;
	list.append("Moiraine Damodred");
	list.append("Siuan Sanche");
	list.append("Rand Al'Thor");
	list.append("Nynaeve Al'mera");
	list.append("Mat Cauthon");
	list.append("Perrin Aybara");

	cout << "\nPrint items in linked list" << endl;
	list.print();

	cout << "\nGet an element by 'index': " << list.get(4) << endl;
	cout << "\nMat Cauthon in list: " << list.find("Mat Cauthon") << endl;
	cout << "\nEgwene Al'vere in list: " << list.find("Egwene Al'vere") << endl;

	cout << "\nRemove last element (pop)" << endl;
	list.pop();


	cout << "\nPrint list again showing removed element gone" << endl;
	list.print();
}
