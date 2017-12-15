#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <iostream>
#include <string>

namespace CS1124{
    class Rational{
        friend std::istream& operator>> (std::istream& is, Rational& number);
        friend std::ostream& operator<< (std::ostream& os, const Rational& number);
        friend bool operator== (const Rational& lhs, const Rational& rhs);

    public:
        Rational();
        Rational(int num);
        int GCD(int x, int y);
        void normalize();
        Rational& operator +=(const Rational& rhs);
        Rational& operator++();
        Rational operator++(int);
        explicit operator bool();

    private:
        int numerator;
        int denominator;
    };

    Rational operator+ (Rational left, const Rational& right);
    bool operator!= (const Rational& lhs, const Rational& rhs);
    Rational& operator--(Rational& r);
    Rational operator--(Rational& r, int);
}


#endif // RATIONAL_H_INCLUDED
