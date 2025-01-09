/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:29:24 by rlane             #+#    #+#             */
/*   Updated: 2025/01/07 14:05:43 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _value;

	static const int _fractionalBits = 8;

public:
	// Default constructor
	Fixed();

	// Copy constructor
	Fixed(const Fixed &other);

	// Copy assignment operator
	Fixed &operator=(const Fixed &other);

	// Destructor
	~Fixed();

	int getRawBits() const;

	void setRawBits(int const raw);

	Fixed(const int value);

	Fixed(const float value);

	int toInt(void) const;

	float toFloat(void) const;

	// comparison operators
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	// mathematical operators
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	// pre-increment operators
	Fixed &operator++();
	Fixed &operator--();

	// post-increment operators
	Fixed operator++(int);
	Fixed operator--(int);

	// min and max functions with constant references
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	/// min and max functions
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
};

// An overload of the insertion << operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP
