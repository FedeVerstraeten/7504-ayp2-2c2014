#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <stdio.h>
#include <iostream>

using namespace std;
class complejo
{
private:

double x,y;

public:

complejo();

complejo(double , double );

complejo(const complejo &);

const complejo& operator+ () const;

const complejo operator-();

const complejo& operator++();

const complejo operator++ (int);

complejo& operator = (const complejo &);


friend const complejo operator+ (const complejo & , const complejo &);

friend const complejo operator+ (const complejo & , float);

friend const complejo operator+ (float , const complejo &);


void emitir(){cout<<"("<<x<<","<<y<<")"<<endl;}
};


#endif // COMPLEX_H_INCLUDED
