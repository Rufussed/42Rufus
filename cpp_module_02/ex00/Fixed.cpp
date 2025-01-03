/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:29:34 by rlane             #+#    #+#             */
/*   Updated: 2025/01/03 13:38:21 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
// Initializes the fixed-point value to 0
Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
// Initializes the object by copying another Fixed instance
Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // Use the copy assignment operator
}

// Copy assignment operator
// Assigns the value from another Fixed instance
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_value = other._value; // Copy the raw value
	}
	return *this;	// return derferenced content of the pointer "this" 
					//(the object itself)
}

// Destructor
// Releases any allocated resources (none in this case)
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Member function to get the raw fixed-point value
int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

// Member function to set the raw fixed-point value
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}
