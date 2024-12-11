/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:10:37 by rlane             #+#    #+#             */
/*   Updated: 2024/12/11 13:57:19 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <limits>

#define ORANGE "\033[38;2;255;165;0m"
#define RESET "\033[0m"
#define MAX_CONTACTS 8

// Class representing the phonebook
class PhoneBook
{
private:
    Contact contacts[MAX_CONTACTS]; // Fixed array of contacts (max 8 contacts)
    int count;                      // Number of contacts currently in the phonebook

public:
    PhoneBook();  // Default constructor
    ~PhoneBook(); // Destructor

    // Method to add a new contact to the phonebook
    void addContact();

    // Method to display and search contacts in the phonebook
    void searchContacts() const;
};

#endif
