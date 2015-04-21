#ifndef _COMPLEX_H_INCLUDED_
#define _COMPLEX_H_INCLUDED_

#include <iostream>

typedef enum{
				
				FORMAT_OPTION_TEXT=0,
				FORMAT_OPTION_U8=1
				
} format_opt_t;

class Complex 
{
  public:
    Complex();
    Complex(double);
	Complex(format_opt_t);
    Complex(double, double);
	Complex(double r, double i, format_opt_t f_o);
    Complex(const Complex &);
    Complex const &operator=(Complex const &);
    Complex const &operator*=(Complex const &);
    Complex const &operator+=(Complex const &);
    Complex const &operator-=(Complex const &);
    ~Complex();

    double real() const;
    double imag() const;
	format_opt_t format() const;
    double abs() const;
    double abs2() const;
    double phase() const;
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
	format_opt_t format_opt_;
	
	friend std::istream &read_format_text(std::istream &, Complex &);
	friend std::istream &read_format_U8(std::istream &, Complex &);
	friend std::ostream &print_format_text(std::ostream &, const Complex &);
	friend std::ostream &print_format_U8(std::ostream &, const Complex &);
	
};

#endif // _COMPLEX_H_INCLUDED_