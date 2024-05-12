#include "Fraction.h"
#include <cstdlib>
#include <ctime>

Fraction::Fraction(int n) {
    srand(time(NULL));
    numerator = rand() % n + 1; 
    denominator = rand() % n + 1;
}

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {}

Fraction Fraction::operator+(const Fraction& other) const {
    int commonDenom = denominator * other.denominator;
    int commonNum = numerator * other.denominator + other.numerator * denominator;
    return Fraction(commonNum, commonDenom);
}

Fraction Fraction::operator-(const Fraction& other) const {
    int commonDenom = denominator * other.denominator;
    int commonNum = numerator * other.denominator - other.numerator * denominator;
    return Fraction(commonNum, commonDenom);
}

Fraction Fraction::operator*(const Fraction& other) const {
    int commonNum = numerator * other.numerator;
    int commonDenom = denominator * other.denominator;
    return Fraction(commonNum, commonDenom);
}

Fraction Fraction::operator/(const Fraction& other) const {
    int commonNum = numerator * other.denominator;
    int commonDenom = denominator * other.numerator;
    return Fraction(commonNum, commonDenom);
}

bool Fraction::operator==(const Fraction& other) const {
    return numerator * other.denominator == other.numerator * denominator;
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator>=(const Fraction& other) const {
    return numerator * other.denominator >= other.numerator * denominator;
}

bool Fraction::operator<=(const Fraction& other) const {
    return numerator * other.denominator <= other.numerator * denominator;
}

std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    os << fraction.numerator << "/" << fraction.denominator;
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& fraction) {
    is >> fraction.numerator >> fraction.denominator;
    return is;
}

int Fraction::gcd(int a, int b) const {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
