#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0)
{
}

Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits)
{
}

Fixed::Fixed(const float n) : _fixedPointValue(roundf(n * (1 << _fractionalBits)))
{
}

Fixed::Fixed(const Fixed &other) : _fixedPointValue(other.getRawBits())
{
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->_fixedPointValue >> _fractionalBits;
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return this->_fixedPointValue > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return this->_fixedPointValue < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return this->_fixedPointValue >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return this->_fixedPointValue <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return this->_fixedPointValue == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return this->_fixedPointValue != rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointValue + rhs.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointValue - rhs.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	if (rhs.getRawBits() == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++()
{
	this->_fixedPointValue += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed &Fixed::operator--()
{
	this->_fixedPointValue -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}