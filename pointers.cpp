#include<string>
#include<iostream>

using namespace std;
int main() {
	string array[3] = {"Lan Mandragoran", "Moirainne Damodred", "Rand Al'Thor"};
	string *pointer = array;
	for (int i=0; i<3; i++) {
		cout << *pointer << "\n";
		pointer++;
	}
	return 0;
}
