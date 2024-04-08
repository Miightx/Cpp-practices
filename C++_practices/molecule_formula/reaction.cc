#include <iostream>
#include "reaction.hh"
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;
long flag = 0;
reaction::reaction(string a)
{
	_val = a;
	istringstream  iss(_val);
	string element;
	vector <string>* current = &_left;
	while (getline(iss, element, '-')) {
		istringstream iss2(element);
		string element2;
		while (getline(iss2, element2, '=')) {
			if (element2.find('>') != std::string::npos) {
				current->push_back(element2.substr(0, element2.find('>')));
				current = &_right;
				current->push_back(element2.substr(element2.find('>')));
			}
			else {
				//element2.erase(remove(element2.begin(), element2.end(), ' '), element2.end());
				current->push_back(element2);
			}
		}
	}
}

string  reaction::normalise() const {
	map <string, int> m1;
	vector <string> v1 = _left;

	for (const std::string& element : v1) {
		auto it = m1.find(element);
		if (it == m1.end()) {
			m1[element] = 1;
		}
		else {
			m1[element]++;
		}
	}

	string s1;
	for (const auto& pair : m1) {
		s1.append(pair.first);
		if (pair.second != 1) {
			s1.append(std::to_string(pair.second));
		}

	}
	vector <string> v2 = _right;
	map <string, int> m2;
	for (const std::string& element : v2) {
		auto it = m2.find(element);
		if (it == m2.end()) {
			m2[element] = 1;
		}
		else {
			m2[element]++;
		}
	}
	string s2;
	for (const auto& pair : m2) {
		s2.append(pair.first);
		if (pair.second != 1) {
			s2.append(std::to_string(pair.second));
		}
	}
	return s1 + s2;
}
void reaction::print_left() const {
	for (const auto& element : _left) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}
void reaction::print_right() const {
	for (const auto& element : _right) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}
string reaction::to_string() {
	stringstream ss;

	string norm = normalise();
	ss << norm;
	return ss.str();
};