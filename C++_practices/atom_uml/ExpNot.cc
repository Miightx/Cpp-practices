#include "ExpNot.hh"

std::string ExpNot::toString() const {
	return "!" + _opd.toString();
}


ThreeVal::ThreeVal_t ExpNot::evaluate() const {
	ThreeVal::ThreeVal_t operandValue = _opd.evaluate();

    if (operandValue == ThreeVal::T) {
        return ThreeVal::F;
    }
    else if (operandValue == ThreeVal::F) {
        return ThreeVal::T;
    }
    else {
        return ThreeVal::U;  
    }
}