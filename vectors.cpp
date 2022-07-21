#include<iostream>
#include<vector>
#define in :

using namespace std;

int main() {
	vector<string> characters = {
		"Moiraine Damodred",
		"Siuan Sanche",
		"Rand Al'Thor",
		"Nynaeve Al'Mera",
		"Mat Cauthon",
		"Perrin Aybara",
	};
	for (auto character in characters) {
		cout << character << endl;
	}
	return 0;
}
