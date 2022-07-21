#include<iostream>
#define in :

using namespace std;
class Application {
	public:
	int main() {
		// runs good
		string good_arr[2] = {"asdf", "bcde"};

		// will not compile
		// string bad_arr[2] = {"asdf", "bcde", "jklm"};

		// will compile and run but is accessing random memory
		cout << good_arr[7] << endl;
		return 0;
	}
};

int main() {
	Application app;
	app.main();
}
