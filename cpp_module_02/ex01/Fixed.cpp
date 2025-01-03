/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:29:34 by rlane             #+#    #+#             */
/*   Updated: 2025/01/03 14:02:40 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Default constructor
// Initializes the fixed-point value to 0
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
// Initializes the object by copying another Fixed instance
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // Use the copy assignment operator
}

// Copy assignment operator
// Assigns the value from another Fixed instance
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_value = other._value; // Copy the raw value
	}
	return *this;
}

// Destructor
// Releases any allocated resources (none in this case)
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Member function to get the raw fixed-point value
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

// Member function to set the raw fixed-point value
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

// A constructor that takes a constant integer as a parameter.
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << _fractionalBits; // move the value to the left by _fractionalBits
}

// A constructor that takes a constant float as a parameter.
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << _fractionalBits));
}

// A member function that converts the fixed point value to an integer.
int Fixed::toInt(void) const
{
	return this->_value >> _fractionalBits; // move the value to the right by _fractionalBits
}

// A member function that converts the fixed point value to a float.
float Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << _fractionalBits);
}

// An overload of the insertion << operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter without friend
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
