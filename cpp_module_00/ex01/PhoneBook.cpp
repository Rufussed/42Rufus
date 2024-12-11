/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:09:15 by rlane             #+#    #+#             */
/*   Updated: 2024/12/11 12:13:20 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Default constructor
PhoneBook::PhoneBook() : count(0) {}

// Destructor
PhoneBook::~PhoneBook() {}

// Add a new contact to the phonebook
void PhoneBook::addContact()
{
    static int oldestIndex = 0; // Tracks the oldest contact to be replaced

    contacts[oldestIndex].setDetails();

    // Update the oldest index in a circular manner
    oldestIndex = (oldestIndex + 1) % MAX_CONTACTS;

    // Only increment count until we reach MAX_CONTACTS
    if (count < MAX_CONTACTS)
        count++;
}

// Display all contacts in the phonebook and allow the user to view details
void PhoneBook::searchContacts() const
{
    if (!count)
    {
        std::cout << "\nNo contacts available." << std::endl;
        return;
    }
    std::cout << std::endl;
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
    for (int i = 0; i < count; i++)
        contacts[i].displaySummary(i);

    std::cout << "\nEnter the index to view details: ";

    int index;
    while (true)
    {
        std::cin >> index;
        // Check for EOF (Ctrl+D)
        if (std::cin.eof())
        {
            std::cout << "\nExiting program." << std::endl;
            return;
        }
        // Check if the input is a digit and within the valid range
        if (std::cin.fail() || index < 0 || index >= count)
        {
            std::cin.clear();                                                   // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cerr << "\nInvalid index! try between 0 and " << (count - 1) << ": ";
        }
        else
            break;
    }
    std::cin.ignore(); // Clear the input buffer
    contacts[index].displayDetails();
}
