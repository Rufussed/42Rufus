/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:08:01 by rlane             #+#    #+#             */
/*   Updated: 2024/12/09 14:13:32 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
    PhoneBook phoneBook; // Create an instance of PhoneBook
    std::string command; // Command entered by the user

	
    while (true) {
		std::cout << "\nWelcome to " ORANGE  "Awesome Phonebook 95!\n\n" RESET;
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) { // Handle EOF (Ctrl+D)
            std::cout << "\nExiting program." << std::endl;
            break;
        }

        if (command == "ADD") {
            phoneBook.addContact(); // Add a new contact
        } else if (command == "SEARCH") {
            phoneBook.searchContacts(); // Search and display contacts
        } else if (command == "EXIT") {
            break; // Exit the program
        } else {
            std::cerr << "Invalid command!" << std::endl;
        }
    }

    return 0;
}