#include <iostream>
#include <cmath>

#include "complex.h"

using namespace std;



Complex::Complex() : real_(0), imag_(0)
{
}

Complex::Complex(double r) : real_(r), imag_(0)
{
}

Complex::Complex(double r, double i) : real_(r), imag_(i)
{
}

Complex::Complex(Complex const &c) : real_(c.real_), imag_(c.imag_)
{
}

Complex const &
Complex::operator=(Complex const &c)
{
  real_ = c.real_;
  imag_ = c.imag_;
  return *this;
}

Complex const &
Complex::operator*=(Complex const &c)
{
  double re = real_ * c.real_
           - imag_ * c.imag_;
  double im = real_ * c.imag_
           + imag_ * c.real_;
  real_ = re, imag_ = im;
  return *this;
}

Complex const &
Complex::operator+=(Complex const &c)
{
  double re = real_ + c.real_;
  double im = imag_ + c.imag_;
  real_ = re, imag_ = im;
  return *this;
}

Complex const &
Complex::operator-=(Complex const &c)
{
  double re = real_ - c.real_;
  double im = imag_ - c.imag_;
  real_ = re, imag_ = im;
  return *this;
}

Complex::~Complex()
{
}

double
Complex::real() const
{
  return real_;
}

double Complex::imag() const
{
  return imag_;
}

double
Complex::abs() const
{
  return std::sqrt(real_ * real_ + imag_ * imag_);
}

double
Complex::abs2() const
{
  return real_ * real_ + imag_ * imag_;
}

double
Complex::phase() const
{
  return atan2(imag_, real_);
}

Complex const &
Complex::conjugate()
{
  imag_*= -1;
  return *this;
}

Complex const
Complex::conjugated() const
{
  return Complex(real_, -imag_);
}

bool
Complex::iszero() const
{
#define ZERO(x) ((x) == +0.0 && (x) == -0.0)
  return ZERO(real_) && ZERO(imag_) ? true : false;
}

Complex const
operator+(Complex const &x, Complex const &y)
{
  Complex z(x.real_ + y.real_, x.imag_ + y.imag_);
  return z;
}

Complex const
operator-(Complex const &x, Complex const &y)
{
  Complex r(x.real_ - y.real_, x.imag_ - y.imag_);
  return r;
}

Complex const
operator*(Complex const &x, Complex const &y)
{
  Complex r(x.real_ * y.real_ - x.imag_ * y.imag_,
            x.real_ * y.imag_ + x.imag_ * y.real_);
  return r;
}

Complex const
operator/(Complex const &x, Complex const &y)
{
  return x * y.conjugated() / y.abs2();
}

Complex const
operator/(Complex const &c, double f)
{
  return Complex(c.real_ / f, c.imag_ / f);
}

bool
operator==(Complex const &c, double f)
{
  bool b = (c.imag_ != 0 || c.real_ != f) ? false : true;
  return b;
}

bool
operator==(Complex const &x, Complex const &y)
{
  bool b = (x.real_ != y.real_ || x.imag_ != y.imag_) ? false : true;
  return b;
}

ostream &
operator<<(ostream &os, const Complex &c)
{
  return os << "(" 
            << c.real_
            << ", " 
            << c.imag_
            << ")";
}

istream &
operator>>(istream &is, Complex &c)
{
  int good = false;
  int bad  = false;
  double re = 0;
  double im = 0;
  char ch = 0;

  if (is >> ch
      && ch == '(') {
    if (is >> re
        && is >> ch
        && ch == ','
        && is >> im
        && is >> ch
        && ch == ')')
      good = true;
    else
      bad = true;
  } else if (is.good()) {
    is.putback(ch);
    if (is >> re)
      good = true;
    else
      bad = true;
  }

  if (good)
    c.real_ = re, c.imag_ = im;
  if (bad)
    is.clear(ios::badbit);

  return is;
}
