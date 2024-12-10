/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:08:41 by rlane             #+#    #+#             */
/*   Updated: 2024/12/10 13:38:49 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

// Default constructor
Contact::Contact() {}

// Destructor
Contact::~Contact() {}

// Copy constructor
Contact::Contact(const Contact &other)
	: firstName(other.firstName), lastName(other.lastName), nickname(other.nickname),
	  phoneNumber(other.phoneNumber), darkestSecret(other.darkestSecret) {}

// Assignment operator
Contact &Contact::operator=(const Contact &other)
{
	if (this != &other)
	{
		firstName = other.firstName;
		lastName = other.lastName;
		nickname = other.nickname;
		phoneNumber = other.phoneNumber;
		darkestSecret = other.darkestSecret;
	}
	return *this;
}

// Method to set contact details from user input
void Contact::setDetails()
{
	while (firstName.empty() || lastName.empty() || nickname.empty() ||
		   phoneNumber.empty() || darkestSecret.empty())
	{
		if (firstName.empty() || lastName.empty() || nickname.empty() ||
			phoneNumber.empty() || darkestSecret.empty())
			std::cerr << "All fields required, please provide missing details." << std::endl;
		if (firstName.empty())
		{
			std::cout << "Enter First Name: ";
			std::getline(std::cin, firstName);
			if (std::cin.eof())
				return;
		}
		if (lastName.empty())
		{
			std::cout << "Enter Last Name: ";
			std::getline(std::cin, lastName);
			if (std::cin.eof())
				return;
		}
		if (nickname.empty())
		{
			std::cout << "Enter Nickname: ";
			std::getline(std::cin, nickname);
			if (std::cin.eof())
				return;
		}
		if (phoneNumber.empty())
		{
			std::cout << "Enter Phone Number: ";
			std::getline(std::cin, phoneNumber);
			if (std::cin.eof())
				return;
		}
		if (darkestSecret.empty())
		{
			std::cout << "Enter Darkest Secret: ";
			std::getline(std::cin, darkestSecret);
			if (std::cin.eof())
				return;
		}
	}
}

// Display a summary of the contact (truncated fields)
void Contact::displaySummary(int index) const
{
	std::cout << ORANGE << std::setw(10) << index << RESET << "|"
			  << ORANGE << std::setw(10) << truncate(firstName) << RESET << "|"
			  << ORANGE << std::setw(10) << truncate(lastName) << RESET << "|"
			  << ORANGE << std::setw(10) << truncate(nickname) << RESET << "|" << std::endl;
}

// Display all contact details
void Contact::displayDetails() const
{
	std::cout << "First Name: " << ORANGE << firstName << "\n"
			  << RESET
			  << "Last Name:  " << ORANGE << lastName << "\n"
			  << RESET
			  << "Nickname:   " << ORANGE << nickname << "\n"
			  << RESET
			  << "Phone Number:   " << ORANGE << phoneNumber << "\n"
			  << RESET
			  << "Darkest Secret: " << ORANGE << darkestSecret << RESET << std::endl;
}

// Helper function to truncate strings longer than 10 characters
std::string Contact::truncate(const std::string &text) const
{
	return text.length() > 10 ? text.substr(0, 9) + "." : text;
}
