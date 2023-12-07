   #include "Rational.h"

    

Rational::Rational()
{
    mDenom = 1;
    mNum = 1;
}

Rational::Rational(int num, int denom)
{
    mNum = num;
    mDenom = denom;
}

Rational::Rational(const char *fraction)
{
    std::istringstream s(fraction);
    char d;
    s >> mNum >> d >> mDenom;
}

Rational::Rational(std::string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if (str.at(i) == '/')
        {
            std::string num = str.substr(0, i-1);
            mNum = std::stoi(num);
            std::string denom = str.substr(i+1, (str.length()-i+1));
            mDenom = std::stoi(denom);
        }
    }
}

Rational& Rational::copy(const std::string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(str.at(i) == '/')
        {
            std::string num = str.substr(0, i+1);
            std::string denom = str.substr(i+1, str.length()-i+1);
            mDenom = std::stoi(denom);
            mNum = std::stoi(num);
            return *this;
        }
    }
    return *this;
}
Rational& Rational::copy(const char fraction[])
{
    std::istringstream s(fraction);
    char d;
    s >> mNum >> d >> mDenom;
    return *this;
}

Rational::operator double() const {
    return static_cast<double>(mNum) / mDenom;
}



Rational& Rational::operator=(const Rational &r)
{
    mNum = r.mNum;
    mDenom = r.mDenom;
    return *this;
}

Rational& Rational::operator=(const char fraction[])
{
    return copy(fraction);
}

Rational& Rational::operator=(const std::string str)
{
    return copy(str);
}

Rational Rational::operator+(const Rational &r)
{
    Rational newRat, newRat2;
    newRat.mDenom = mDenom;
    newRat.mNum = mNum;
    newRat2.mDenom = r.mDenom;
    newRat2.mNum = r.mNum;
    if(mDenom!=r.mDenom)
    {
        newRat.mDenom = mDenom * r.mDenom;
        newRat.mNum = mNum * r.mDenom;
        newRat2.mDenom = r.mDenom * mDenom;
        newRat2.mNum = r.mNum * mDenom;

    }
    newRat.mNum+= newRat2.mNum;
    reduceR(newRat);
    return newRat;
}

Rational Rational::operator*(const Rational &r)
{
    Rational newRat;
    newRat.mDenom = mDenom*r.mDenom;
    newRat.mNum = mNum*r.mNum;
    reduceR(newRat);
    return newRat;
}

Rational Rational::operator-(const Rational &r)
{
    Rational newRat, newRat2;
    newRat.mDenom = mDenom;
    newRat.mNum = mNum;
    newRat2.mDenom = r.mDenom;
    newRat2.mNum = r.mNum;

    if (mDenom != r.mDenom)
    {
        newRat.mDenom = mDenom * r.mDenom;
        newRat.mNum = mNum * r.mDenom;
        newRat2.mDenom = r.mDenom * mDenom;
        newRat2.mNum = r.mNum * mDenom;
    }

    newRat.mNum -= newRat2.mNum;
    reduceR(newRat);
    return newRat;
}
Rational Rational::operator/(const Rational &r)
{
    Rational newRat;
    newRat.mDenom = mDenom*r.mNum;
    newRat.mNum = mNum*r.mDenom;
    reduceR(newRat);
    return newRat;
}

Rational& Rational::reduce()
{
    int comm = commonFactor(mDenom, mNum);
    mDenom/=comm;
    mNum/=comm;
    return *this;
}
void Rational::reduceR(Rational &r)
{
    int comm = commonFactor(r.mDenom, r.mNum);
    r.mDenom/=comm;
    r.mNum/=comm;
}

std::ostream& operator<<(std::ostream& os, const Rational r)
{
    os << r.mNum << "/" << r.mDenom;
    return os;
}
int Rational::commonFactor(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return commonFactor(b, a % b);
    }
}
