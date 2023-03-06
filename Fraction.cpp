#include "fraction.h"


Fraction::Fraction(long long numerator_, size_t denominator_) : numerator(numerator_), denominator(denominator_)
{
	if (denominator == 0)
		throw "Division by zero";

	size_t divider = gcd(abs(numerator), denominator);
	
	numerator /= divider;
	denominator /= divider;
}

Fraction Fraction::operator*(const Fraction& fraction) const
{
	return { numerator * fraction.numerator, denominator * fraction.denominator };
}

Fraction Fraction::operator/(const Fraction& fraction) const
{
	return *this * Fraction{(long long) fraction.denominator, (size_t) fraction.numerator};
}

Fraction Fraction::operator+(const Fraction& fraction) const
{
	return {((long long) fraction.denominator) * numerator + ((long long) denominator) * fraction.numerator, fraction.denominator * denominator };
}

Fraction Fraction::operator-(const Fraction& fraction) const
{
	return *this + (-fraction);
}

Fraction Fraction::operator-() const
{
	return { -numerator, denominator };
}

Fraction::operator double() const
{
	return ((double)numerator) / denominator;
}

size_t Fraction::gcd(size_t a, size_t b)
{
	while (b != 0) {
		size_t tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}


std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
	out << fraction.numerator;

	if (fraction.denominator != 1)
		out << " / " << fraction.denominator;

	return out;
}
