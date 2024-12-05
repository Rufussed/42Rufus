/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:08:01 by rlane             #+#    #+#             */
/*   Updated: 2024/12/05 15:19:20 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;

	while (true)
	{
		std::string command;
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "ADD")
		{
			Contact newContact;
			std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

			std::cout << "Enter First Name: ";
			std::getline(std::cin, firstName);
			std::cout << "Enter Last Name: ";
			std::getline(std::cin, lastName);
			std::cout << "Enter Nickname: ";
			std::getline(std::cin, nickname);
			std::cout << "Enter Phone Number: ";
			std::getline(std::cin, phoneNumber);
			std::cout << "Enter Darkest Secret: ";
			std::getline(std::cin, darkestSecret);

			if (firstName.empty() || lastName.empty() || nickname.empty() ||
				phoneNumber.empty() || darkestSecret.empty())
			{
				std::cout << "Error: All fields must be filled!\n";
				continue;
			}

			newContact.setDetails(firstName, lastName, nickname, phoneNumber, darkestSecret);
			phoneBook.addContact(newContact);
			std::cout << "Contact added successfully!\n";
		}
		else if (command == "SEARCH")
		{
			phoneBook.displayContacts();

			std::cout << "Enter the index of the contact to display: ";
			int index;
			std::cin >> index;

			// Handle invalid input
			if (std::cin.fail())
			{
				std::cin.clear();													// Clear error flags
				std::cin.ignore(1000, '\n'); // Discard excess input
				std::cout << "Invalid input. Please enter a valid number.\n";
				continue;
			}

			phoneBook.displayContactDetails(index);
			std::cin.ignore(1000, '\n'); // Discard excess input 
		}
		else if (command == "EXIT")
		{
			std::cout << "Exiting the program. Goodbye!\n";
			break;
		}
		else
		{
			std::cout << "Unknown command. Please try again.\n";
		}
	}

	return 0;
}
