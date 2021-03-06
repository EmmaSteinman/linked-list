//============================================================
// Emma Steinman
// March 7, 2017
// Complex.h
// Class definition for the Complex class dealing with Complex
// numbers.
//============================================================

#include <iostream>
#include <string>
using namespace std;


#ifndef COMPLEX_H
#define COMPLEX_H

//============================================================
// Complex Class
//============================================================


class Complex
{
private:
    float     real;
    float     imaginary;




public:
            Complex     (void);             //default
            Complex     (const Complex &);  //copy
            Complex     (float a, float b); //complex 
			Complex 	(float a);
           ~Complex     (void);

    Complex operator+   (Complex c1);
    Complex operator+   (float n);
    Complex operator-   (Complex c1);
    Complex operator-   (float n);
    Complex operator*   (Complex c1);
    Complex operator*   (float n);
    Complex operator/   (Complex c1);
    Complex operator/   (float n);
    Complex operator~   (void);
    Complex operator-   (void);
    Complex operator^   (int n);
    void 	setReal     (float n);
    float  getReal     (void);
    void	setImag     (float n);
    float  getImag     (void);
    Complex operator=   (Complex c1);
    bool    operator==  (Complex c1);
    bool    operator!=  (Complex c1);
    friend ostream & operator<< ( ostream &os, Complex c );
    
};




#endif 
