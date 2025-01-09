/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:29:24 by rlane             #+#    #+#             */
/*   Updated: 2025/01/07 14:04:51 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	// Integer to store the fixed-point value
	int _value;

	// Number of fractional bits (fixed at 8 for this exercise)
	static const int _fractionalBits = 8;

public:
	// Default constructor
	// Initializes the fixed-point value to 0
	Fixed();

	// Copy constructor
	// Initializes the object by copying another Fixed instance
	Fixed(const Fixed &other);

	// Copy assignment operator
	// Assigns the value from another Fixed instance
	Fixed &operator=(const Fixed &other);

	// Destructor
	// Releases any allocated resources (none in this case)
	~Fixed();

	// Member function to get the raw fixed-point value
	int getRawBits() const;

	// Member function to set the raw fixed-point value
	void setRawBits(int const raw);

	// A constructor that takes a constant integer as a parameter.
	Fixed(const int value);

	// A constructor that takes a constant float as a parameter.
	Fixed(const float value);

	// A member function that converts the fixed point value to an integer.
	int toInt(void) const;

	// A member function that converts the fixed point value to a float.
	float toFloat(void) const;
};

// An overload of the insertion << operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter without friend
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP
