#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
  private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

  public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &rhs);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	
	float toFloat(void) const;
	int toInt(void) const;
	
	bool operator>(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;

	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;
	
	Fixed &operator++();    // Pre-increment
	Fixed operator++(int);  // Post-increment
	Fixed &operator--();    // Pre-decrement
	Fixed operator--(int);  // Post-decrement
	
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif