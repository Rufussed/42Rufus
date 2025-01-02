/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:29:24 by rlane             #+#    #+#             */
/*   Updated: 2025/01/02 18:47:32 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
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
};

#endif // FIXED_HPP
