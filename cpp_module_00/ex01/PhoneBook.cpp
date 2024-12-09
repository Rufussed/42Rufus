/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:09:15 by rlane             #+#    #+#             */
/*   Updated: 2024/12/09 14:17:09 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

// Default constructor
PhoneBook::PhoneBook() : count(0) {}

// Destructor
PhoneBook::~PhoneBook() {}

// Copy constructor
PhoneBook::PhoneBook(const PhoneBook &other) : count(other.count) {
    for (int i = 0; i < 8; ++i) {
        contacts[i] = other.contacts[i];
    }
}

// Assignment operator
PhoneBook &PhoneBook::operator=(const PhoneBook &other) {
    if (this != &other) {
        count = other.count;
        for (int i = 0; i < 8; ++i) {
            contacts[i] = other.contacts[i];
        }
    }
    return *this;
}

// Add a new contact to the phonebook
void PhoneBook::addContact() {
    if (count >= 8) {
        std::cout << "Replacing the oldest contact." << std::endl;
        count = 0; // Overwrite the oldest contact
    }
    contacts[count].setDetails();
    count++;
}

// Display all contacts in the phonebook and allow the user to view details
void PhoneBook::searchContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
    for (int i = 0; i < count; i++) {
        contacts[i].displaySummary(i);
    }
    std::cout << "Enter the index to view details: ";
    int index;
    std::cin >> index;
    std::cin.ignore(); // Clear the input buffer
    if (index >= 0 && index < count) {
        contacts[index].displayDetails();
    } else {
        std::cerr << "Invalid index!" << std::endl;
    }
}

