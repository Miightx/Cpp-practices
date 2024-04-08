#include<string>
#include<iostream>
#include<vector>
#include<map>
#include <fstream>  

using namespace std;
class molecule {
public:

	molecule(const string a);
	vector <string> separate() const;
	string to_string() const;
	string normalise() const;
private:
	string _val;
};