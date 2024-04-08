#include <string>
#include "molecule.hh"
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
molecule::molecule(const string a) {
	_val = a;
}
vector <string> molecule::separate() const {
	vector <string> v;
	istringstream  iss(_val);
	string element;
	while (getline(iss, element, '-')) {
		istringstream iss2(element);
		string element2;
		while (getline(iss2, element2, '=')) {
			v.push_back(element2);
		}
	}
	return v;
}
string  molecule :: normalise() const {
	map <string, int> m;
	vector <string> v = separate();

	for (const std::string& element : v) {
		auto it = m.find(element);
		if (it == m.end()) {
			m[element] = 1;
		}
		else {
			m[element]++;
		}
	}

	string s;
	for (const auto& pair : m) {
		s.append(pair.first);
		if (pair.second != 1) {
			s.append(std::to_string(pair.second));
		}

	}
	return s;	
}

string molecule ::to_string() const {
	return _val;
}

