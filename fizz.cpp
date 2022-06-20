#include<iostream>
using namespace std;

namespace App {
	class Application {
		public:
		Application() {
			cout << "Running pre-flight checks, if any...\n";
		}
		int main() {
			for (int i = 0; i<=100; i+=1) {
				float eval_three = i%3;
				float eval_five = i%5;
				if (eval_three == 0 && eval_five == 0) {
					print(to_string (i) + ": FizzBuzz\n");
				}
				if (eval_three == 0 && eval_five != 0) {
					print(to_string (i) + ": Fizz\n");
				}
				if (eval_five == 0 && eval_three != 0) {
					print(to_string (i) + ": Buzz\n");
				}
			}
			return 0;
		}
		void print(string to_print) {
			cout << to_print;
		}	
	};
};

int main() {
	App::Application app;
	app.main();
}
