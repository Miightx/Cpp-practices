#pragma once

#include<string>
#include<iostream>
namespace ThreeVal
{
	typedef enum { F, T, U } ThreeVal_t;
	std::string to_string(ThreeVal_t val);
}


class ExpLog {
public:

	virtual std::string toString() const = 0;
	virtual ThreeVal::ThreeVal_t evaluate()const = 0;
};


