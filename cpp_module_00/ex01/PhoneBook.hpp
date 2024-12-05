/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:10:37 by rlane             #+#    #+#             */
/*   Updated: 2024/12/05 15:20:24 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp" // Include the Contact class
#include <iostream>    // Required for input/output
#include <iomanip>
#include <string>


class PhoneBook {
private:
	// Private member variables
	Contact contacts[8]; // Fixed-size array of Contact objects
	int currentIndex;    // Tracks the next insertion index
	int totalContacts;   // Tracks the total number of contacts

public:
	// Constructor
	PhoneBook();

	// Public member functions
	void addContact(const Contact &contact);

	void displayContacts() const;

	void displayContactDetails(int index) const;
};

#endif // PHONEBOOK_HPP
