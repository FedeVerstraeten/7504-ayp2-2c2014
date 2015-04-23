#ifndef _complex_H_INCLUDED_
#define _complex_H_INCLUDED_

#include <iostream>

class complex 
{
  public:
    complex();
    complex(double);
    complex(double, double);
    complex(const complex &);
    complex const &operator=(complex const &);
    complex const &operator*=(complex const &);
    complex const &operator+=(complex const &);
    complex const &operator-=(complex const &);
    ~complex();

    double real() const;
    double imag() const;
    double abs() const;
    double abs2() const;
    double phase() const;
    complex const &conjugate();
    complex const conjugated() const;
    bool iszero() const;

    friend complex const operator+(complex const &, complex const &);
    friend complex const operator-(complex const &, complex const &);
    friend complex const operator*(complex const &, complex const &);
    friend complex const operator/(complex const &, complex const &);
    friend complex const operator/(complex const &, double);

    friend bool operator==(complex const &, double);
    friend bool operator==(complex const &, complex const &);

    friend std::ostream &operator<<(std::ostream &, const complex &);
    friend std::istream &operator>>(std::istream &, complex &);
  
  private:
    double real_, imag_;
};

#endif // _complex_H_INCLUDED_
