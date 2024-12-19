/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:08:01 by rlane             #+#    #+#             */
/*   Updated: 2024/12/19 13:05:15 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook; // Create an instance of PhoneBook
    std::string command; // Command entered by the user

    while (true)
    {
        std::cout << ORANGE "\nAwesome Phonebook 95!\n\n" RESET;
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) // Handle EOF (Ctrl+D)
        {
            std::cout << "\nExiting program." << std::endl;
            break;
        }

        if (command == "ADD")
        {
            phoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContacts();
        }
        else if (command == "EXIT")
        {
            std::cout << "\nExiting program." << std::endl;
            break;
        }
        else
        {
            std::cerr << "\nInvalid command!" << std::endl;
        }
    }

    return 0;
}