/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:10:12 by rlane             #+#    #+#             */
/*   Updated: 2024/12/11 13:56:31 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

// Class representing a contact in the phonebook
class Contact
{
private:
    std::string firstName;     // Contact's first name
    std::string lastName;      // Contact's last name
    std::string nickname;      // Contact's nickname
    std::string phoneNumber;   // Contact's phone number
    std::string darkestSecret; // Contact's darkest secret

    // Helper function to truncate strings longer than 10 characters
    std::string truncate(const std::string &text) const;
    
public:
    Contact();  // Default constructor
    ~Contact(); // Destructor

    // Method to input contact details from user
    void setDetails();

    // Method to display a summary of the contact (truncated fields)
    void displaySummary(int index) const;

    // Method to display all contact details
    void displayDetails() const;
};

#endif
