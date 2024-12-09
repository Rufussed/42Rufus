/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:10:37 by rlane             #+#    #+#             */
/*   Updated: 2024/12/09 14:11:36 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define ORANGE "\033[38;2;255;165;0m"
#define RESET "\033[0m"

// Class representing the phonebook
class PhoneBook {
private:
    Contact contacts[8]; // Fixed array of contacts (max 8 contacts)
    int count;           // Number of contacts currently in the phonebook

public:
    PhoneBook(); // Default constructor
    ~PhoneBook(); // Destructor
    PhoneBook(const PhoneBook &other); // Copy constructor
    PhoneBook &operator=(const PhoneBook &other); // Assignment operator

    // Method to add a new contact to the phonebook
    void addContact();

    // Method to display and search contacts in the phonebook
    void searchContacts() const;
};

#endif


