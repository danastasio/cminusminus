#include<string>
#include<iostream>

using namespace std;
int main() {
	cout << "Using a pointer to iterate through an array\n" << endl;
	string array[3] = {"Lan Mandragoran", "Moirainne Damodred", "Rand Al'Thor"};
	string *pointer = array;
	for (int i=0; i<3; i++) {
		cout << *pointer << endl;
		pointer++;
	}

	cout << "\nPointer Manipulation" << endl;
	string mystr = "asdf";
	string *new_pointer = &mystr;
	string new_value = "this is a new string";
	cout << "\nOriginal String:         " << mystr << endl;
	cout << "address of pointer:      " << new_pointer << endl;
	cout << "contents of pointer:     " << *new_pointer << endl;
	cout << "assign value to pointer: " << new_value << endl;
	*new_pointer = new_value;
	cout << "pointer value:           " << *new_pointer << endl;
	cout << "original variable value: " << mystr << endl;
	return 0;
}
