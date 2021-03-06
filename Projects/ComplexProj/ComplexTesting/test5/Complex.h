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
    double     real;
    double     imaginary;




public:
            Complex     (void);             //default
            Complex     (const Complex &);  //copy
            Complex     (double a, double b); //complex 
			Complex 	(double a);
           ~Complex     (void);

    Complex operator+   (Complex c1);
    Complex operator+   (double n);
    Complex operator-   (Complex c1);
    Complex operator-   (double n);
    Complex operator*   (Complex c1);
    Complex operator*   (double n);
    Complex operator/   (Complex c1);
    Complex operator/   (double n);
    Complex operator~   (void);
    Complex operator-   (void);
    Complex operator^   (int n);
    void 	setReal     (double n);
    double  getReal     (void);
    void	setImag     (double n);
    double  getImag     (void);
    Complex operator=   (Complex c1);
    bool    operator==  (Complex c1);
    bool    operator!=  (Complex c1);
    friend ostream & operator<< ( ostream &os, Complex c );
    
};




#endif 
