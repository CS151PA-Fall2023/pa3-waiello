/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 
 * 
 */
#include <iostream>
#include "Rational.h"

using std::cout;
using std::endl;

int main()
{
    Rational num0;
    cout <<"num0 = "<<num0<<endl;

    Rational num1(12,16);
    cout <<"num1 = "<<num1<<endl;

    Rational num2;
    num2=num1;//assignment
    cout <<"num2 = "<<num2<<endl;
    cout<<"num2 as a decimal = "<<static_cast<double>(num2)<<endl;//type conversion operator

    Rational num3 = num2;//initialization
    cout <<"num3 = "<<num3<<endl;

    num3.reduce();
    cout <<"Reduced num3 = "<<num3<<endl;

    Rational num4("3/-4");//Convert Constructor
    cout <<"num4 = "<<num4<<endl;
    num4.reduce();
    cout <<"Reduced num4 = "<<num4<<endl;

    double num5 = num4;//type conversion operator
    cout <<"num5 = "<<num5<<endl;

    Rational num6 = "3/4";
    cout <<"num6 = "<<num6<<endl;

    num1 = "3/7";
    cout <<"num1 = "<<num1<<endl;

    cout <<"\nLet's do some math...\n"<<endl;
    
    Rational num7 = num1 + num2;
    cout << num1 << " + " << num2 << " = " << num7 << endl;
    Rational num8 = num1 - num2;
    cout << num1 << " - " << num2 << " = " << num8 << endl;
    Rational num9 = num1 * num2;
    cout << num1 << " * " << num2 << " = " << num9 << endl;
    Rational num10 = num1/num2;
    cout << "(" << num1 << ") / (" << num2 << ") = " << num10 << endl;
    Rational num11 = num3 + num1 * num2;
    cout << num3 << " + " << num1 << "*" << num2 << " = " << num11 << "\n\n";

    return 0;
}
