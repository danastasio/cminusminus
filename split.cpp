#include<iostream>
#include<vector>
#define in :

using namespace std;

vector<string> split(string conv, vector<string> corrected = {})
{
	if (conv.find(",") == string::npos) {
		// there are no commas left - base case
		corrected.push_back(conv);
		return corrected;
	}
	string element = conv.substr(0, conv.find(","));
	corrected.push_back(element);
	// Recursion is the best way to pull all of the elements out. Recursion is the best way to pull all of the elements out.
	return split(conv.substr(conv.find(",")+1), corrected);
}

int main()
{
	string mystr = "this,is,a,comma,delimited,string";
	vector<string> myvec = split(mystr);
	for (auto element in myvec) {
		cout << element << endl;
	}
	return 0;
}
