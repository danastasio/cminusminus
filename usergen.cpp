#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<time.h>

using namespace std;

// Globals
unordered_map<int, string> institution_roles = {
	{0, "student"},
	{1, "facutly"},
	{2, "staff"},
	{3, "employee"},
};
unordered_map<int, string> system_roles = {
	{0, "None"},
	{1, "Guest_ID"},
};

class User {
    protected:
    void generate_password() {
        string tmp_pw;
        char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		srand(time(0));
        for (int i=0; i<12; i++) {
            tmp_pw += letters[rand() % 62];
        }
		password = tmp_pw;
    }

	public:
	string first;
	string last;
	string email;
	string password;
	string user_id;
	string institution_role = "student";
	string system_role = "None";
	User(string datastream) {
		string remaining;
		first = datastream.substr(0, datastream.find(','));
		remaining = datastream.substr(datastream.find(',') + 1, 100);
		last = remaining.substr(0, remaining.find(','));
		email = remaining.substr(remaining.find(',') + 1, 100);
		user_id = first[0] + last;
		generate_password();
	}
	void print() {
		cout << "First name: " << first << endl;
		cout << "Last name: " << last << endl;
		cout << "Email: " << email << endl;
		cout << "Password: " << password << endl;
		cout << "Institution Role: " << institution_role << endl;
		cout << "System Role: " << system_role << endl;
	}
};

class Database {
	private:
	string cursor;

	public:
	string query;
	vector<User> users;

	Database() {
		query = "SELECT user_id, email, concat(firstname, ' ', lastname) as fullname FROM users WHERE user_id in (";
	}

	void build() {
		for (int i=0; i<users.size(); i++) {
			User user = users[i];
			if (users.size() != 1 and i!=0) {
				query.append(", ");
			}
			query.append("'" + user.user_id + "'");
		}
		query.append(")");
		query.append(" OR fullname IN ("); 
		for (int i=0; i<users.size(); i++) {
			User user = users[i];
			if (users.size() != 1 and i!=0) {
				query.append(", ");
			}
			query.append("'" + user.first + " " + user.last + "'");
		}
		query.append(")");
		query.append(" OR email IN ("); 
		for (int i=0; i<users.size(); i++) {
			User user = users[i];
			if (users.size() != 1 and i!=0) {
				query.append(", ");
			}
			query.append("'" + user.email + "'");
		}
		query.append(");");
	}

	void execute() {
		cout << query << endl;
	}
};

class Application {
	private:
		vector<User> users;

	public:
	Application() {
		// Constructor
	}
	int main() {
		char ds[100];
		cout << "Welcome to the C++ User Generator. Please enter the first name, last name, and email separated by commas for the users you want to generate.\n"
<< endl
<< "Example below"
<< endl
<< "Siuan,Sanche,siuan.sanche@gmail.com"
<< endl;
		while (true) {
			string datastream;
			cout << "> ";
			cin >> datastream;
			if (datastream == "DONE") {
				break;
			} else if (count(datastream.begin(), datastream.end(), ',') != 2) {
				cout << "Looks like you may have missed a comma. Remember that DONE is case sensitive" << endl;
			} else {
				User user(datastream);
				users.push_back(user);
			}
		}

		cout << "Users will be created with a random password each. Should the users instead share a preset password? (y/n) default = n" << endl;
		cout << "(y/n): ";
		string datastream;
		cin >> datastream;
		if (datastream == "y") {
			cout << "Enter the password all users will share: ";
			cin >> ds;
			string datastream(ds);
			for (int i = 0; i < users.size(); i++) {
				users[i].password = datastream;
			}
		}

		cout << "\nUsers will be created with the institution role of Student. Should the users have a different institution role? (y/n) default = n" << endl;
		cout << "(y/n): ";
		cin >> datastream;
		if (datastream == "y") {
			cout << "Enter the number of the role that you want the users to have:" << endl;
			for (auto &[key, value] : institution_roles) {
				cout << key << ") " << value << endl;
			}
			cout << "> ";
			cin >> datastream;
			for (int i = 0; i < users.size(); i++) {
				users[i].institution_role = institution_roles[stoi(datastream)];
			}
		}

		cout << "\nUsers will be created with the system role of GuestID. Should the users have a different system role? (y/n) default = n" << endl;
		cout << "(y/n): ";
		cin >> datastream;
		if (datastream == "y") {
			cout << "Enter the number of the role that you want the users to have:" << endl;
			for (auto &[key, value] : system_roles) {
				cout << key << ") " << value << endl;
			}
			cout << "> ";
			cin >> datastream;
			for (int i = 0; i < users.size(); i++) {
				users[i].system_role = system_roles[stoi(datastream)];
			}
		}

		for (int i = 0; i<users.size(); i++) {
			users[i].print();
		}

		Database db;
		db.users = users;
		db.build();
		db.execute();
		return 0;
	}
};

int main() {
	Application app;
	app.main();
}
