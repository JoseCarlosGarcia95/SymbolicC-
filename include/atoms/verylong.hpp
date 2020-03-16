/*
    SymbolicC++ : An object oriented computer algebra system written in C++

    Copyright (C) 2008 Yorick Hardy and Willi-Hans Steeb

    This library is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

// verylong.h
// Very Long Integer Class

#ifndef VERYLONG_H
#define VERYLONG_H

#include "misc/identity.hpp"
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <gmpxx.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

class Verylong {
private:
    // Private member functions
    Verylong multdigit(int) const;
    Verylong mult10(int) const;

public:
    mpz_class num;

    // Constructors and destructor
    Verylong(const string& = "0");
    Verylong(int);
    Verylong(const Verylong&);
    Verylong(mpz_class);
    ~Verylong();

    // Conversion operators
    operator int() const;
    operator double() const;
    operator string() const;

    // Arithmetic operators and Relational operators
    const Verylong& operator=(const Verylong&); // assignment operator
    Verylong operator-() const; // negate  operator
    Verylong operator++(); // prefix  increment operator
    Verylong operator++(int); // postfix increment operator
    Verylong operator--(); // prefix  decrement operator
    Verylong operator--(int); // postfix decrement operator

    Verylong operator+=(const Verylong&);
    Verylong operator-=(const Verylong&);
    Verylong operator*=(const Verylong&);
    Verylong operator/=(const Verylong&);
    Verylong operator%=(const Verylong&);

    friend Verylong operator+(const Verylong&, const Verylong&);
    friend Verylong operator-(const Verylong&, const Verylong&);
    friend Verylong operator*(const Verylong&, const Verylong&);
    friend Verylong operator/(const Verylong&, const Verylong&);
    friend Verylong operator%(const Verylong&, const Verylong&);

    friend int operator==(const Verylong&, const Verylong&);
    friend int operator!=(const Verylong&, const Verylong&);
    friend int operator<(const Verylong&, const Verylong&);
    friend int operator<=(const Verylong&, const Verylong&);
    friend int operator>(const Verylong&, const Verylong&);
    friend int operator>=(const Verylong&, const Verylong&);

    // Other functions
    friend Verylong abs(const Verylong&);
    friend Verylong sqrt(const Verylong&);
    friend Verylong pow(const Verylong&, const Verylong&);
    friend double div(const Verylong&, const Verylong&);
    friend list<Verylong*> factorize(const Verylong&);

    // Class Data
    static const Verylong zero;
    static const Verylong one;
    static const Verylong two;

    // I/O stream functions
    friend ostream& operator<<(ostream&, const Verylong&);
    friend istream& operator>>(istream&, Verylong&);
};

#define LIBSYMBOLICCPLUSPLUS

// Class Data

const Verylong Verylong::zero = Verylong("0");

const Verylong Verylong::one = Verylong("1");

const Verylong Verylong::two = Verylong("2");

// Constructors, Destructors and Conversion operators.

Verylong::Verylong(const string& value)
{
    this->num = value;
}

Verylong::Verylong(int n)
{
    this->num = n;
}

Verylong::Verylong(const Verylong& x)
{
    this->num = x.num;
}

Verylong::Verylong(mpz_class n)
{
    this->num = n;
}

Verylong::~Verylong() {}

Verylong::operator int() const
{
    return this->num.get_si();
}

Verylong::operator double() const
{
    return this->num.get_d();
}

Verylong::operator string() const
{
    return this->num.get_str();
}

// Various member operators

const Verylong& Verylong::operator=(const Verylong& rhs)
{
    if (this == &rhs)
        return *this;

    this->num = rhs.num;
    return *this;
}

// Unary - operator
Verylong Verylong::operator-() const
{
    Verylong temp(*this);

    temp *= -1;

    return temp;
}

// Prefix increment operator
Verylong Verylong::operator++()
{
    return *this = *this + one;
}

// Postfix increment operator
Verylong Verylong::operator++(int)
{
    Verylong result(*this);
    *this = *this + one;
    return result;
}

// Prefix decrement operator
Verylong Verylong::operator--()
{
    return *this = *this - one;
}

// Postfix decrement operator
Verylong Verylong::operator--(int)
{
    Verylong result(*this);
    *this = *this - one;
    return result;
}

Verylong Verylong::operator+=(const Verylong& v)
{
    return *this = *this + v;
}

Verylong Verylong::operator-=(const Verylong& v)
{
    return *this = *this - v;
}

Verylong Verylong::operator*=(const Verylong& v)
{
    return *this = *this * v;
}

Verylong Verylong::operator/=(const Verylong& v)
{
    return *this = *this / v;
}

Verylong Verylong::operator%=(const Verylong& v)
{
    return *this = *this % v;
}

// Various friendship operators and functions.

Verylong operator+(const Verylong& u, const Verylong& v)
{
    return Verylong(u.num + v.num);
}

Verylong operator-(const Verylong& u, const Verylong& v)
{
    return Verylong(u.num - v.num);
}

Verylong operator*(const Verylong& u, const Verylong& v)
{
    return Verylong(u.num * v.num);
}

//  This algorithm is the long division algorithm.
Verylong operator/(const Verylong& u, const Verylong& v)
{
    return Verylong(u.num / v.num);
}

Verylong operator%(const Verylong& u, const Verylong& v)
{
    return Verylong(u.num % v.num);
}

int operator==(const Verylong& u, const Verylong& v)
{
    return u.num == v.num;
}

int operator!=(const Verylong& u, const Verylong& v)
{
    return !(u == v);
}

int operator<(const Verylong& u, const Verylong& v)
{
    return u.num < v.num;
}

int operator<=(const Verylong& u, const Verylong& v)
{
    return (u < v || u == v);
}

int operator>(const Verylong& u, const Verylong& v)
{
    return (!(u < v) && u != v);
}

int operator>=(const Verylong& u, const Verylong& v)
{
    return (u > v || u == v);
}

// Calculate the absolute value of a number
Verylong abs(const Verylong& v)
{
    return Verylong(abs(v.num));
}

Verylong gcd(const Verylong& u, const Verylong& v)
{
    return Verylong(gcd(u.num, v.num));
}

// Calculate the integer square root of a number
// based on the formula (a+b)^2 = a^2 + 2ab + b^2
Verylong sqrt(const Verylong& v)
{
    return Verylong(sqrt(v.num));
}

// Raise a number X to a power of degree
Verylong pow(const Verylong& X, const Verylong& degree)
{
    return Verylong(pow(X.num, degree.num));
}

// Calculate factors for given verylong
list<Verylong*> factorize(const Verylong& u)
{
    list<Verylong*> result;
    list<mpz_class> factors;

    result = list<Verylong*> {};
    factors = factorize_int(u.num);

    for (auto factor : factors) {
        result.push_back(new Verylong(factor));
    }

    return result;
}

// Double division function
double div(const Verylong& u, const Verylong& v)
{
    return Verylong(u.num / v.num);
}

ostream& operator<<(ostream& s, const Verylong& v)
{
    s << v.num.get_str();
    return s;
}

istream& operator>>(istream& s, Verylong& v)
{
    string temp(10000, ' ');
    s >> temp;
    v = Verylong(temp);
    return s;
}

template <>
Verylong zero(Verylong) { return Verylong::zero; }
template <>
Verylong one(Verylong) { return Verylong::one; }

#undef LIBSYMBOLICCPLUSPLUS

template <>
Verylong zero(Verylong);
template <>
Verylong one(Verylong);

#endif
