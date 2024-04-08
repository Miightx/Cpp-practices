#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <fstream>
#include "atom.hh"

using namespace ThreeVal;

//std::size_t Atom::unique_id = 0;
long unique_id = 0;


std::string Atom::toString() const { //(a_0 = U)
	std::string s;
	std::string to_string(ThreeVal_t _val);
	switch (_val) {
	case T:
		s = "T";
		break;
	case F:
		s = "F";
		break;
	case U:
		s = "U";
		break;
	}
	std::string line = "(a_" + std::to_string(_id) + " " + "=" + " " + s + ")";
	return line;
}
Atom& Atom::operator=(bool b) {
	_val = (b ? T : F);
	return *this;
}
Atom& Atom::operator=(const Atom& a) {
	if (this != &a) {
		_val = a._val;
	}
	return *this;
}
Atom& Atom::operator=(ThreeVal_t val) {
	_val = val;
	return *this;
}

bool Atom::operator==(ThreeVal::ThreeVal_t value) const {
	return _val == value;
}

bool Atom::operator==(const Atom& other) const {
	return _val == other._val;
}


