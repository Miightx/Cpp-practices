#include "ExpOr.hh"

std::string ExpOr::toString() const {
    return "(" + _opd1.toString() + " OR " + _opd2.toString() + ")";
}

ThreeVal::ThreeVal_t ExpOr::evaluate() const {
	ThreeVal::ThreeVal_t operand1Value = _opd1.evaluate();
	ThreeVal::ThreeVal_t operand2Value = _opd2.evaluate();
	if (operand1Value == ThreeVal::T && operand2Value == ThreeVal::T) {
		return ThreeVal::T;
	}
	else if (operand1Value == ThreeVal::F && operand2Value == ThreeVal::F) {
		return ThreeVal::F;
	}
	else if (operand1Value == ThreeVal::F && operand2Value == ThreeVal::T) {
		return ThreeVal::T;
	}
	else if (operand1Value == ThreeVal::F && operand2Value == ThreeVal::U) {
		return ThreeVal::U;
	}
	else if (operand1Value == ThreeVal::T && operand2Value == ThreeVal::F) {
		return ThreeVal::T;
	}
	else if (operand1Value == ThreeVal::T && operand2Value == ThreeVal::U) {
		return ThreeVal::T;
	}
	else if (operand1Value == ThreeVal::U && operand2Value == ThreeVal::T) {
		return ThreeVal::T;
	}
	else if (operand1Value == ThreeVal::U && operand2Value == ThreeVal::F) {
		return ThreeVal::U;
	}
	else if (operand1Value == ThreeVal::U && operand2Value == ThreeVal::U) {
		return ThreeVal::U;
	}
	else {
		return ThreeVal::U;
	}
}

bool ExpOr::operator==(ThreeVal::ThreeVal_t value) const {
	ThreeVal::ThreeVal_t result = evaluate();
	return result == value;
}

bool ExpOr::operator==(const ExpOr& other) const {
	ThreeVal::ThreeVal_t result1 = evaluate();
	ThreeVal::ThreeVal_t result2 = other.evaluate();
	return result1 == result2;
}