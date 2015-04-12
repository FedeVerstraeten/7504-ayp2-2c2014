#include <iostream>
#include <stdio.h>
#include "complex.h"

complejo ::complejo () : x(0.0) , y(0.0) {}

complejo ::complejo (const complejo & c) : x(c.x) , y (c.y) {}

complejo ::complejo (double a, double b): x(a) , y(b) {}

const complejo & complejo :: operator + () const
{ return *this;}

const complejo complejo:: operator -()
{
complejo s;
s.x= -x ; s.y =-y ;
return s;
}

const complejo &complejo :: operator ++ ()
{ x++ ; y++; return *this;}

const complejo complejo::operator ++ (int)
{complejo anterior (x,y);
x++ ; y++ ;
return anterior;
}

complejo &complejo ::operator= (const complejo & b)
{x = b.x;
y= b.y;
return *this;
}


const complejo operator + (const complejo &l, const complejo &r)
{return complejo (l.x+r.x , l.y+r.y);}

const complejo operator+ (const complejo &l , float f)
{ return complejo (l.x+f,l.y);}

const complejo operator+ (float f , const complejo &l)
{return complejo (f+l.x , l.y);}

int main(void)
{

cout << "La clase complex compiló bien mirá:" << endl;
complejo z1(1,1);
z1.emitir();

return 1;
}
