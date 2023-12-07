#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>


class Rational
{
public:
    Rational();
    Rational(int num, int denom);
    Rational(const char *fraction);
    Rational(std::string str);
    operator double() const;
    
/*     std::string print();
 */    
    Rational& operator=(const Rational &r);
    Rational& operator=(const char fraction[]);
    
    Rational& operator=(const std::string str);

    Rational& copy(const char fraction[]);
    
    Rational& copy(std::string str);
    Rational operator+(const Rational &r);
    Rational operator*(const Rational &r);
    Rational operator-(const Rational &r);
    Rational operator/(const Rational &r);

    Rational& reduce();
    void reduceR(Rational &r);


    friend std::ostream& operator<<(std::ostream& os, const Rational r);
    int commonFactor(int a, int b);

private:

    int mNum;
    int mDenom;
};



#endif