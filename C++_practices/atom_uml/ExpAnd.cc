#include "ExpAnd.hh"

std::string ExpAnd::toString() const {
    return "(" + _opd1.toString() + " AND " + _opd2.toString() + ")";
}

ThreeVal::ThreeVal_t ExpAnd::evaluate() const {
    ThreeVal::ThreeVal_t operand1Value = _opd1.evaluate();
    ThreeVal::ThreeVal_t operand2Value = _opd2.evaluate();
    if (operand1Value == ThreeVal::T && operand2Value == ThreeVal::T) {
        return ThreeVal::T;
    }
    else if (operand1Value == ThreeVal::F && operand2Value == ThreeVal::F) {
        return ThreeVal::F;
    }
    else if (operand1Value == ThreeVal:: F && operand2Value == ThreeVal::T) {
		return ThreeVal::T;
	}
	else if (operand1Value == ThreeVal::F && operand2Value == ThreeVal::U) {
		return ThreeVal::F;
	}
	else if (operand1Value == ThreeVal::T && operand2Value == ThreeVal::F) {
		return ThreeVal::F;
	}
	else if (operand1Value == ThreeVal::T && operand2Value == ThreeVal::U) {
		return ThreeVal::U;
	}
	else if (operand1Value == ThreeVal::U && operand2Value == ThreeVal::T) {
		return ThreeVal::U;
	}
	else if (operand1Value == ThreeVal::U && operand2Value == ThreeVal::F) {
		return ThreeVal::F;
	}
	else if (operand1Value == ThreeVal::U && operand2Value == ThreeVal::U) {
		return ThreeVal::U;
	}
    else {
        return ThreeVal::U;
    }
}
