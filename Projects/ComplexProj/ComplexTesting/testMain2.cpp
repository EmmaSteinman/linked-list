//===========================================================
// Emma Steinman
// March 8, 2017
// testMain1.cpp
// This program has terminal units for Complex class.
//===========================================================

#include <iostream>
#include <sstream>
#include <string>
#include <assert.h>
#include "Complex.h"
using namespace std;

//===========================================================
// test / operator with divide by zero error
//===========================================================

void test100(void)
{
    cout << "test100\n";
    Complex c1(3,6);
    Complex c2 = c1/0;
}


int main(void)
{
    test100();
    return 0;
}
