#include<iostream>
#include<vector>
#include<stdexcept>
#define in :

using namespace std;

template<typename T>
class List {
	private:
	vector<T> list;

	public:
	void append(T to_append) {
		list.push_back(to_append);
	}
	T index(int indx) {
		if (indx > list.size()) {
			throw invalid_argument("index does not exist");
		}
		return list[indx];
	}
	int size() {
		return list.size();
	}
	vector<T> iter() {
		return list;
	}
	void pop() {
		list.pop_back();
	}
};

int main() {
	vector<string> characters = {"Moiraine Damodred", "Siuan Sanche", "Rand Al'Thor", "Nynaeve Al'Mera", "Matrim Cauthon", "Perrin Aybara"};
	List<string> mylist;
	for (auto character in characters) {
		mylist.append(character);
	}

	cout << "Print all members of mylist:\n--------------------------" << endl;
	for (auto character in mylist.iter()) {
		cout << character << endl;
	}

	cout << "\nPop the last element" << endl;
	mylist.pop();

	cout << "\nPrint all members of mylist:\n--------------------------" << endl;
	for (auto character in mylist.iter()) {
		cout << character << endl;
	}
}
