#include "rational.h"

rational::rational(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator) {
    this->simplify();
}

rational::rational(int numerator) : rational(numerator, 1) {
}

rational::rational(const string &rationalStr) {
    std::basic_string<char>::size_type position = rationalStr.find('/');

    this->m_numerator = std::stoi(rationalStr.substr(0, position));
    this->m_denominator = std::stoi(rationalStr.substr(position + 1));

    this->simplify();
}

// Default constructor
rational::rational() : rational(1, 1) {
}

float rational::value() const {
    return (float) this->m_numerator / (float) this->m_denominator;
}

int rational::get_num() const {
    return this->m_numerator;
}

int rational::get_den() const {
    return this->m_denominator;
}

void rational::set_num(int newNumerator) {
    this->m_numerator = newNumerator;
    this->simplify();
}

void rational::set_den(int newDenominator) {
    this->m_denominator = newDenominator;
    this->simplify();
}

string rational::to_string() const {
    return std::to_string(this->m_numerator) + "/" + std::to_string(this->m_denominator);
}

double rational::to_double() const {
    return (double) this->m_numerator / (double) this->m_denominator;
}

bool rational::is_positive() const {
    return this->to_double() >= 0.0;
}

bool rational::is_negative() const {
    return this->to_double() < 0.0;
}

bool rational::is_infinite() const {
    return this->m_numerator != 0 && this->m_denominator == 0;
}

bool rational::is_nan() const {
    return this->m_numerator == 0 && this->m_denominator == 0;
}

int rational::gcd(int num, int den) const {
    return den == 0 ? num : gcd(den, num % den);
}

int rational::gcd() const {
    return this->gcd(this->m_numerator, this->m_denominator);
}

void rational::simplify() {
    if (!this->is_valid()) return;
    int simplification = this->gcd();
    int absolute = this->m_denominator < 0 ? -1 : 1;

    this->m_numerator = this->m_numerator / simplification * absolute;
    this->m_denominator = this->m_denominator / simplification * absolute;
}

rational rational::simplified_copy() const {
    rational copy{this->get_num(), this->get_den()};
    copy.simplify();
    return copy;
}

bool rational::is_valid() const {
    return (!this->is_nan() && !this->is_infinite());
}

rational &rational::operator+=(const rational &other) {
    if (!other.is_valid()) return const_cast<rational &>(other);

    this->set_num((this->get_num() * other.get_den()) + (other.get_num() * this->get_den()));
    this->set_den(this->get_den() * other.get_den());

    return *this;
}

rational &rational::operator-=(const rational &other) {
    if (!other.is_valid()) return const_cast<rational &>(other);

    this->set_num((this->get_num() * other.get_den()) - (other.get_num() * this->get_den()));
    this->set_den(this->get_den() * other.get_den());

    return *this;
}

rational &rational::operator*=(const rational &other) {
    if (!other.is_valid()) return const_cast<rational &>(other);

    this->set_num(this->get_num() * other.get_num());
    this->set_den(this->get_den() * other.get_den());

    return *this;
}

rational &rational::operator/=(const rational &other) {
    if (!other.is_valid()) return const_cast<rational &>(other);

    return operator*=({other.get_den(), other.get_num()});
}

bool rational::operator==(const rational &other) {
    auto first = this->simplified_copy(), second = other.simplified_copy();
    return (first.get_num() == second.get_num()) && (first.get_den() == second.get_den());
}

bool rational::operator!=(const rational &other) {
    auto first = this->simplified_copy(), second = other.simplified_copy();
    return (first.get_num() != second.get_num()) && (first.get_den() != second.get_den());
}

bool rational::operator>(const rational &other) {
    return this->value() > other.value();
}

bool rational::operator<(const rational &other) {
    return this->value() < other.value();
}

bool rational::operator>=(const rational &other) {
    return this->value() >= other.value();
}

bool rational::operator<=(const rational &other) {
    return this->value() <= other.value();
}

rational operator+(const rational &first, const rational &second) {
    return first.simplified_copy() += second;
}

rational operator-(const rational &first, const rational &second) {
    return first.simplified_copy() -= second;
}

rational operator*(const rational &first, const rational &second) {
    return first.simplified_copy() *= second;
}

rational operator/(const rational &first, const rational &second) {
    return first.simplified_copy() /= second;
}

std::ostream &operator<<(std::ostream &out, const rational &rat) {
    out << rat.to_string();
    return out;
}
