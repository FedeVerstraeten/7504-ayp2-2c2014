#ifndef _COMPLEX_H_INCLUDED_
#define _COMPLEX_H_INCLUDED_

#include <iostream>

class Complex 
{
  public:
    Complex();
    Complex(double);
    Complex(double, double);
    Complex(const Complex &);
    Complex const &operator=(Complex const &);
    Complex const &operator*=(Complex const &);
    Complex const &operator+=(Complex const &);
    Complex const &operator-=(Complex const &);
    ~Complex();

    double real() const;
    double imag() const;
    double abs() const;
    double abs2() const;
    Complex const &conjugate();
    Complex const conjugated() const;
    bool iszero() const;

    friend Complex const operator+(Complex const &, Complex const &);
    friend Complex const operator-(Complex const &, Complex const &);
    friend Complex const operator*(Complex const &, Complex const &);
    friend Complex const operator/(Complex const &, Complex const &);
    friend Complex const operator/(Complex const &, double);

    friend bool operator==(Complex const &, double);
    friend bool operator==(Complex const &, Complex const &);

    friend std::ostream &operator<<(std::ostream &, const Complex &);
    friend std::istream &operator>>(std::istream &, Complex &);
  
  private:
    double real_, imag_;
};

#endif // _COMPLEX_H_INCLUDED_
