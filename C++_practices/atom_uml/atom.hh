#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include "ExpLog.hh"

//extern long unique_id;
//namespace ThreeVal {
//    typedef enum { T, F, U } ThreeVal_t;
//    std::string to_string(ThreeVal_t val)
//
//}
extern long unique_id;

class Atom : public ExpLog {

public:
	Atom() :_id(unique_id++), _val(ThreeVal::U) {};
	Atom(ThreeVal::ThreeVal_t val) :_id(unique_id++), _val(val) {};
	Atom(const Atom& a) :_id(unique_id++), _val(a._val) {};
	std::string toString() const;
	ThreeVal::ThreeVal_t evaluate() const { return _val; };

	Atom& operator=(const Atom& a);
	Atom& operator=(bool b);
	Atom& operator=(ThreeVal::ThreeVal_t val);
	long id() { return _id; };
	bool operator==(ThreeVal::ThreeVal_t value) const;
	bool operator==(const Atom& other) const;



private:
	long _id;
	ThreeVal::ThreeVal_t _val;
    //static std::size_t unique_id;

};


