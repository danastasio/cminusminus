#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
// Enum Class: Not in global namespace
enum class Role {
	None,
	System,
	User
};
// Enum: In global namespace
enum SystemRole {
	None,
	User,
	Admin,
	Last,
};
// Hash Map: Not an enum :)
unordered_map<int, string> Roles = {
	{0, "None"},
	{1, "User"},
	{2, "Admin"},
};
// Array we will use a pointer on. Also not an enum.
string system_roles[3] = {"none", "user", "admin"};

int main() {
	// Loop through classic enum
	for (int i = None; i != Last; i++) {
		cout << *i << endl;
	}

	// Find enum class of 1 and print value
	auto val = Role(1);
	if (val == Role::System) {
		cout << "true" << endl;
	}

	// Loop through Hash Map
	for (int i = 0; i < Roles.size(); i++) {
		cout << i << ") " << Roles[i] << endl;
	}

	// Loop through array with pointer
	string *pointer = system_roles;	
	for (int i = 0; i <= (sizeof(system_roles)/sizeof(system_roles) + 1); i++) {
		cout << i << ") " << *pointer << endl;
		pointer++;
	}
	return 0;
}
