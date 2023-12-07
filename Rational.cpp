   #include "Rational.h"

    
/**
 * @brief Construct a new Rational:: Rational object
 * 
 */
Rational::Rational()
{
    mDenom = 1;
    mNum = 1;
}

/**
 * @brief Construct a new Rational:: Rational object
 * 
 * @param num numerator
 * @param denom denominator
 */
Rational::Rational(int num, int denom)
{
    mNum = num;
    mDenom = denom;
}

/**
 * @brief Construct a new Rational:: Rational object from a char string
 * 
 * @param fraction char string copied into mNum and mDenom
 */
Rational::Rational(const char *fraction)
{
    std::istringstream s(fraction);
    char d;
    s >> mNum >> d >> mDenom;
}

/**
 * @brief Construct a new Rational:: Rational object
 * 
 * @param str copies string into mnum/mdenom
 */
Rational::Rational(std::string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if (str.at(i) == '/')
        {
            std::string num = str.substr(0, i-1); //substring for the numerator of string
            mNum = std::stoi(num); //converts substring into int 
            std::string denom = str.substr(i+1, (str.length()-i+1));  //substring for the denominator of string
            mDenom = std::stoi(denom);//converts substring into int 
        }
    }
}

/**
 * @brief copies fraction string into Rational
 * 
 * @param str string to be copied
 * @return Rational& returns copied rational
 */
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

/**
 * @brief copies char array into rational
 * 
 * @param fraction char array to be copied
 * @return Rational& returns copied rational
 */
Rational& Rational::copy(const char fraction[])
{
    std::istringstream s(fraction);
    char d;
    s >> mNum >> d >> mDenom;
    return *this;
}

/**
 * @brief overloads static_cast operator and converts rational into decimal
 * 
 * @return double converted decimal
 */
Rational::operator double() const {
    return static_cast<double>(mNum) / mDenom;
}


/**
 * @brief overloads the = sign and copies from one rational into new rational
 * 
 * @param r rational to be copied
 * @return Rational& returns new rational
 */
Rational& Rational::operator=(const Rational &r)
{
    mNum = r.mNum;
    mDenom = r.mDenom;
    return *this;
}

/**
 * @brief overloads the = sign and copies from char array into new rational
 * 
 * @param fraction char array to be copied
 * @return Rational& returns new rational
 */
Rational& Rational::operator=(const char fraction[])
{
    return copy(fraction);
}

/**
 * @brief overloads the = sign and copies from string into new rational
 * 
 * @param str string to be copied
 * @return Rational& returns new copied rational
 */
Rational& Rational::operator=(const std::string str)
{
    return copy(str);
}

/**
 * @brief overloads + operator and adds rationals together
 * 
 * @param r second rational added
 * @return new Rational from added rationals
 */
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
    newRat.reduce();
    return newRat;
}

/**
 * @brief overloads * operator and multiplies rationals together
 * 
 * @param r second rational
 * @return new Rational from multiplied rationals
 */

Rational Rational::operator*(const Rational &r)
{
    Rational newRat;
    newRat.mDenom = mDenom*r.mDenom;
    newRat.mNum = mNum*r.mNum;
    newRat.reduce();
    return newRat;
}

/**
 * @brief overloads - operator and subtracts one rational from the other
 * 
 * @param r second rational subtracted
 * @return new Rational from subtracted rational
 */

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
    newRat.reduce();
    return newRat;
}

/**
 * @brief overloads / operator and divides one rational from another
 * 
 * @param r second rational to be divided
 * @return new Rational from divided rational
 */

Rational Rational::operator/(const Rational &r)
{
    Rational newRat;
    newRat.mDenom = mDenom*r.mNum;
    newRat.mNum = mNum*r.mDenom;
    newRat.reduce();
    return newRat;
}

/**
 * @brief reduces rational to its simplest form
 * 
 * @return Rational& reduced rational
 */
Rational& Rational::reduce()
{
    int comm = commonFactor(mDenom, mNum);
    mDenom/=comm;
    mNum/=comm;
    return *this;
}

/**
 * @brief overloats << operator so that a rational displays itself properly instead of giving an error.
 * 
 * @param os output stream that is being modified
 * @param r rational used to modify output
 * @return std::ostream& overloaded output
 */
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
