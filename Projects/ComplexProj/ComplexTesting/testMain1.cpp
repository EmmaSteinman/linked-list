//===========================================================
// Emma Steinman
// March 8, 2017
// testMain1.cpp
// This program has non-terminal units for Complex class.
//===========================================================

#include <iostream>
#include <sstream>
#include <string>
#include <assert.h>
#include "Complex.h"
using namespace std;

//===========================================================
// test default constructor
//===========================================================

void test1(void)
{
    cout << "test1\n";
    Complex c1;
    assert(c1.getReal() == 0 and c1.getImag() == 0);
}

//===========================================================
// test constructor with two int
//===========================================================

void test2(void)
{
    cout << "test2\n";
    Complex c2(3,4);
    assert(c2.getReal() == 3 and c2.getImag() == 4);
}

//===========================================================
// test constructor with two float
//===========================================================

void test3(void)
{
    cout << "test3\n";
    Complex c3(3.14, 2.2);
    assert(c3.getReal() == 3.14f and c3.getImag() == 2.2f);
}

//===========================================================
// test constructor with one float and one int
//===========================================================

void test4(void)
{
    cout << "test4\n";
    Complex c4(6, 3.8);
    assert(c4.getReal() == 6 and c4.getImag() == 3.8f);
}

//===========================================================
// test copy constructor
//===========================================================

void test5(void)
{
    cout << "test5\n";
    Complex c5(7,4);
    Complex c6(c5);
    assert(c6.getReal() == 7 and c6.getImag() == 4);
}

//===========================================================
// test operator+ with two complex 
//===========================================================

void test6(void)
{
    cout << "test6\n";
    Complex c7(3.7, 5);
    Complex c8(35, 8.9);
    Complex c9 = c7 + c8;
    assert(c9.getReal() == 38.7f and c9.getImag() == 13.9f);
}

//===========================================================
// test operator + with a complex and float
//===========================================================

void test7(void)
{
    cout << "test7\n";
    Complex c1(9,3);
    Complex c2 = c1 + 8.3;
    assert(c2.getReal() == 17.3f and c2.getImag() == 3);
}

//===========================================================
// test operator - with two complex
//===========================================================

void test8(void)
{
    cout << "test8\n";
    Complex c1(5.8, 7.2);
    Complex c2(2.2, 5.1);
    Complex c3 = c1 - c2;
    assert(c3.getReal() <= 3.6*1.01 && c3.getReal() >= 3.6 * 0.99 
        && c3.getImag() <= 2.1 * 1.01 && c3.getImag() >= 2.1 * 0.99);
}

//===========================================================
// test operator * with two complex
//===========================================================

void test9(void)
{
    cout << "test9\n";
    Complex c1(6.6, 7);
    Complex c2(3, 7);
    Complex c3 = c1 * c2;
    assert(c3.getReal() >= (-29.2) * 1.01 && c3.getReal() <= (-29.2) * 0.99
        && c3.getImag() <= 67.2 * 1.01 && c3.getImag() >= 67.2 * 0.99);
}

//===========================================================
// test operator * with a complex and float
//===========================================================

void test10(void)
{
    cout << "test10\n";
    Complex c1(7.5, 9);
    Complex c2 = c1 * 5;
    assert(c2.getReal() == 37.5f and c2.getImag() == 45);
}

//===========================================================
// test operator / with two complex
//===========================================================

void test11(void)
{
    cout << "test11\n";
    Complex c1(14.4, 9.3);
    Complex c2(3.9, 2.3);
    Complex c3 = c1 / c2;
    assert(c3.getReal() <= 3.8 * 1.01 && c3.getReal() >= 3.8 * 0.99
        && c3.getImag() <= 0.2 * 1.01 && c3.getReal() >= 0.2 * 0.99);
}

//===========================================================
// test operator / with a complex and float
//===========================================================

void test12(void)
{
    cout << "test12\n";
    Complex c1(12.5, 9);
    Complex c2 = c1 / 3;
    assert(c2.getReal() <= 4.2* 1.01 && c2.getReal() >= 4.2* 0.99
        && c2.getImag() <= 3*1.01 && c2.getImag() >= 3*0.99);
}

//===========================================================
// test operator ~
//===========================================================

void test13(void)
{
    cout << "test13\n";
    Complex c1(2.5, 5);
    Complex c2 = ~c1;
    assert(c2.getReal() == 2.5f && c2.getImag() == -5);
}

//===========================================================
// test operator -
//===========================================================

void test14(void)
{
    cout << "test14\n";
    Complex c1(3, 4.6);
    Complex c2 = -c1;
    assert(c2.getReal() == -3 && c2.getImag() == -4.6f);
}

//===========================================================
// test operator -
//===========================================================

void test15(void)
{
    cout << "test15\n";
    Complex c1(-3.4, -3);
    Complex c2 = -c1;
    assert(c2.getReal() == 3.4f && c2.getImag() == 3);
}

//===========================================================
// test operator ^
//===========================================================

void test16(void)
{
    cout << "test16\n";
    Complex c1(4, 6);
    Complex c2 = c1^3;
    assert(c2.getReal() == -368 && c2.getImag() == 72);
}

//===========================================================
// test operator ^
//===========================================================

void test17(void)
{
    cout << "test17\n";
    Complex c1(4.3, -8.4);
    Complex c2 = c1 ^ 2;
    assert(c2.getReal() >= -52.1 * 1.01 && c2.getReal() <= -52.1 * 0.99
        && c2.getImag() >= -72.2 * 1.01 && c2.getImag() <= -72.2 * 0.99);
}

//===========================================================
// test setReal
//===========================================================

void test18(void)
{
    cout << "test18\n";
    Complex c1(4, 4);
    c1.setReal(3);
    assert(c1.getReal() == 3 && c1.getImag() == 4);
}

//===========================================================
// test setReal
//===========================================================

void test19(void)
{
    cout << "test19\n";
    Complex c1(3, 7);
    c1.setReal(2.4);
    assert(c1.getReal() == 2.4f && c1.getImag() == 7);
}

//===========================================================
// test setImag
//===========================================================

void test20(void)
{
    cout << "test20\n";
    Complex c1(4, 7);
    c1.setImag(6);
    assert(c1.getReal() == 4 && c1.getImag() == 6);
}

//===========================================================
// test setImag
//===========================================================

void test21(void)
{
    cout << "test21\n";
    Complex c1(3, 62);
    c1.setImag(40.3);
    assert(c1.getReal() == 3 && c1.getImag() == 40.3f);
}

//===========================================================
// test =
//===========================================================

void test22(void)
{
    cout << "test22\n";
    Complex c1(4, 63);
    Complex c2 = c1;
    assert(c2.getReal() == 4 && c2.getImag() == 63);
}

//===========================================================
// test ==
//===========================================================

void test23(void)
{
    cout << "test23\n";
    Complex c1(3, 5);
    Complex c2(3, 5);
    assert((c1 == c2) == 1);
}

//===========================================================
// test == 
//===========================================================

void test24(void)
{
    cout << "test24\n";
    Complex c1(4, 67);
    Complex c2(3, 77);
    assert((c1 == c2) == 0);
}

//===========================================================
// test !=
//===========================================================

void test25(void)
{
    cout << "test25\n";
    Complex c1(5, 5);
    Complex c2(5, 5);
    assert((c1 != c2) == 0);
}

//===========================================================
// test !=
//===========================================================

void test26(void)
{
    cout << "test26\n";
    Complex c1(7, 5);
    Complex c2(85, 5);
    assert((c1 != c2) == 1);
}

//===========================================================
// test operator+ 
//===========================================================

void test27(void)
{
    cout << "test27\n";
    Complex c1(-3, 4);
    Complex c2(6, -45);
    Complex c3 = c1 + c2;
    assert(c3.getReal() == 3 && c3.getImag() == -41);
}

//===========================================================
// test operator+
//===========================================================

void test28(void)
{
    cout << "test28\n";
    Complex c1(-3.7, 44.6);
    Complex c2(44.3, -5.3);
    Complex c3 = c1 + c2;
    assert(c3.getReal() == 40.6f && c3.getImag() == 39.3f);
}

//===========================================================
// test operator-
//===========================================================

void test29(void)
{
    cout << "test29\n";
    Complex c1(-40, 22);
    Complex c2(33, -42);
    Complex c3 = c1 - c2;
    assert(c3.getReal() == -73 && c3.getImag() == 64);
}

//===========================================================
// test cout
//===========================================================

void test30(void)
{
    cout << "test30\n";
    Complex c1;
    ostringstream stream;
    stream << c1;
    string str = stream.str();
    assert(str == "0 + 0i");
}

//===========================================================
// test cout
//===========================================================

void test31(void)
{
    cout << "test31\n";
    Complex c1(3, -5);
    ostringstream stream;
    stream << c1;
    string str = stream.str();
    assert(str == "3 - 5i");
}

//===========================================================
// test cout
//===========================================================

void test32(void)
{
    cout << "test32\n";
    Complex c1(0, -1);
    ostringstream stream;
    stream << c1;
    string str = stream.str();
    assert(str == "-i");
}

//===========================================================
// test cout
//===========================================================

void test33(void)
{
    cout << "test33\n";
    Complex c1(0, 1);
    ostringstream stream;
    stream << c1;
    string str = stream.str();
    assert(str == "i");
}

//===========================================================
// test cout 
//===========================================================

void test34(void)
{
    cout << "test34\n";
    Complex c1(4, -1);
    ostringstream stream;
    stream << c1;
    string str = stream.str();
    assert(str == "4 - i");
}

//===========================================================
// test cout 
//===========================================================

void test35(void)
{
    cout << "test35\n";
    Complex c1(30, -68);
    ostringstream stream;
    stream << c1;
    string str = stream.str();
    assert(str == "30 - 68i");
}

//===========================================================
// test cout
//===========================================================

void test36(void)
{
    cout << "test36\n";
    Complex c1(39, 0);
    ostringstream stream;
    stream << c1;
    string str = stream.str();
    assert(str == "39");
}

//===========================================================
// test cout
//===========================================================

void test37(void)
{
    cout << "test37\n";
    Complex c1(0, 49);
    ostringstream stream;
    stream << c1;
    string str = stream.str();
    assert(str == "49i");
}

//===========================================================
// test cout
//===========================================================

void test38(void)
{
    cout << "test38\n";
    Complex c1(39, 599);
    ostringstream stream;
    stream << c1;
    string str = stream.str();
    assert(str == "39 + 599i");
}


int main(void)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    test12();
    test13();
    test14();
    test15();
    test16();
    test17();
    test18();
    test19();
    test20();
    test21();
    test22();
    test23();
    test24();
    test25();
    test26();
    test27();
    test28();
    test29();
    test30();
    test31();
    test32();
    test33();
    test34();
    test35();
    test36();
    test37();
    test38();
    return 0;
}
    
