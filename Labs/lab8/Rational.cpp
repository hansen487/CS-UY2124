#include "Rational.h"
#include <iostream>
#include <string>

using namespace std;

namespace CS1124{
    Rational::Rational() {}
    Rational::Rational(int num) {
        numerator = num;
        denominator = 1;
    }

    int Rational::GCD(int x, int y) {
        while (y != 0) {
            int temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }

    void Rational::normalize(){
        int gcd = GCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
//        cout << "loop" << endl;
//        cout << numerator << '/' << denominator << endl;
//        cout << "den" << (denominator < 0) << endl;
//        if (numerator > 0 && denominator < 0){
//            numerator *= -1;
//            cout << "num" << endl;
//            denominator *= -1;
//            cout << "den" << endl;
//        }
    }

    bool operator== (const Rational& lhs, const Rational& rhs){
        return (lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator);
    }

    bool operator!= (const Rational& lhs, const Rational& rhs){
        return !(lhs == rhs);
    }

    ostream& operator<< (ostream& os, const Rational& number){
        os << number.numerator << '/' << number.denominator;
        return os;
    }

    Rational& Rational::operator += (const Rational& rhs){
        numerator *=  rhs.denominator;
        numerator += rhs.numerator * denominator;
        denominator *= rhs.denominator;
        normalize();
    }

    Rational& Rational::operator++(){
        numerator += denominator;
        return *this;
    }

    Rational Rational::operator++(int){
        Rational temp(*this);
        numerator += denominator;
        return temp;
    }

    Rational& operator--(Rational& x){
        x += -1;
        return x;
    }

    Rational operator-- (Rational& x, int){
        Rational temp(x);
        x += -1;
        return temp;
    }

    istream& operator>> (istream& is, Rational& number){
        char slash;
        is >> number.numerator >> slash >> number.denominator;
        number.normalize();
        return is;
    }

    Rational operator+ (Rational left, const Rational& right){
        return left += right;

    }

  Rational::operator bool(){
        return (numerator != 0);
    }
}

