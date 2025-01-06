/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:29:34 by rlane             #+#    #+#             */
/*   Updated: 2025/01/06 13:41:20 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Default constructor, set _value to 0
Fixed::Fixed() : _value(0)
{
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	*this = other; // Use the copy assignment operator
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->_value = other._value; // Copy the raw value
	}
	return *this;
}

// Destructor
Fixed::~Fixed()
{
}

int Fixed::getRawBits() const
{

	return this->_value;
}

void Fixed::setRawBits(int const raw)
{

	this->_value = raw;
}

Fixed::Fixed(const int value)
{

	this->_value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{

	this->_value = roundf(value * (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return this->_value >> _fractionalBits;
}

float Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << _fractionalBits);
}

// An overload of the insertion << operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed &other) const
{
	return this->_value > other._value;
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->_value != other._value;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

// pre-increment operators
Fixed &Fixed::operator++()
{
	this->_value++;
	return *this;
}

Fixed &Fixed::operator--()
{
	this->_value--;
	return *this;
}

// post-increment operators
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

// min and max functions with constant references
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}

// min and max functions
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}