#include<vector>
#include<string>
#include<iostream>

using namespace std;

class User {
	protected:
	string generate_password() {
    	std::string tmp_pw;
        char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        for (int i=0; i<12; i++) {
            tmp_pw += letters[rand() % 62];
        }                                                                                                                                                                
        return tmp_pw;
	}
	public:
	string name;
	string system_role;
	string password;
	User() {
		system_role = "None";
		password = generate_password();
	}
};

class Application {
	public:
	int main() {
		vector<string> names = {"Jesse Chavez", "Katie Solis", "Joseph Wallace", "John Barhorst"};
		vector<User> users;

		for (string name: names) {
			User user;
			user.name = name;
			users.push_back(user);
		}

		for (User user: users) {
			cout << user.name << "\n";
		}
		return 0;
	}
};

int main() {
	Application app;
	app.main();
}

