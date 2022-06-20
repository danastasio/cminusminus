#include<iostream>
#include<string>

using namespace std;

class Application
{
	public:
	int main() {
		string str_to_reverse = "this is a string";
		string new_string;
		for (int i = str_to_reverse.length(); i >= 0; i -= 1) {
			new_string = new_string + str_to_reverse[i];
		}
		cout << new_string << "\n";
		return 0;
	}
};

int main()
{
	Application app;
	app.main();
}
