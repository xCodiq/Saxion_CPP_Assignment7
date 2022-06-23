#ifndef CPPASSIGNMENT3_RATIONAL_H
#define CPPASSIGNMENT3_RATIONAL_H

#include <iostream>

using std::cout, std::cin, std::endl, std::getline, std::ifstream, std::string;

class rational {
private:
    int m_numerator;
    int m_denominator;

    float value() const;

public:
    rational(int numerator, int denominator);

    explicit rational(int numerator);

    explicit rational(const string &rationalStr);

    rational();

    [[nodiscard]] int get_num() const;

    [[nodiscard]] int get_den() const;

    void set_num(int newNumerator);

    void set_den(int newDenominator);

    [[nodiscard]] string to_string() const;

    [[nodiscard]] double to_double() const;

    [[nodiscard]] bool is_positive() const;

    [[nodiscard]] bool is_negative() const;

    [[nodiscard]] bool is_infinite() const;

    [[nodiscard]] bool is_nan() const;

    int gcd(int num, int den) const;

    int gcd() const;

    void simplify();

    rational simplified_copy() const;

    bool is_valid() const;

    rational &operator+=(const rational &other);

    rational &operator-=(const rational &other);

    rational &operator*=(const rational &other);

    rational &operator/=(const rational &other);

    bool operator==(const rational &other);

    bool operator!=(const rational &other);

    bool operator>(const rational &other);

    bool operator<(const rational &other);

    bool operator>=(const rational &other);

    bool operator<=(const rational &other);

    friend rational operator+(const rational &first, const rational &second);

    friend rational operator-(const rational &first, const rational &second);

    friend rational operator*(const rational &first, const rational &second);

    friend rational operator/(const rational &first, const rational &second);

    friend std::ostream &operator<<(std::ostream &out, const rational &rat);
};

rational operator+(const rational &first, const rational &second);

rational operator-(const rational &first, const rational &second);

rational operator*(const rational &first, const rational &second);

rational operator/(const rational &first, const rational &second);

std::ostream &operator<<(std::ostream &out, const rational &rat);

#endif //CPPASSIGNMENT3_RATIONAL_H
