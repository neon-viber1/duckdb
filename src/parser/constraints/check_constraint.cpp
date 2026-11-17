#include "duckdb/parser/constraints/check_constraint.hpp"
#include "duckdb/parser/keyword_helper.hpp"

namespace duckdb {

CheckConstraint::CheckConstraint(unique_ptr<ParsedExpression> expression)
    : Constraint(ConstraintType::CHECK), expression(std::move(expression)) {
}

string CheckConstraint::ToString() const {
	return (name.empty() ? "" : "CONSTRAINT " + SQLIdentifier(name) + " ") + "CHECK(" + expression->ToString() + ")";
}

unique_ptr<Constraint> CheckConstraint::Copy() const {
	auto result = make_uniq<CheckConstraint>(expression->Copy());
	result->name = name;
	return std::move(result);
}

} // namespace duckdb
