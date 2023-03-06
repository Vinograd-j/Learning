#pragma once

#include <iostream>

class Fraction
{

private:

	long long numerator;
	size_t denominator;

public:

	Fraction(long long numerator_, size_t denominator_ = 1);
	
	friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);

	Fraction operator*(const Fraction& fraction) const;
	Fraction operator/(const Fraction& fraction) const;
	Fraction operator+(const Fraction& fraction) const;
	Fraction operator-(const Fraction& fraction) const;

	Fraction operator-() const;

	operator double() const;


private:

	size_t gcd(size_t a, size_t b);

};