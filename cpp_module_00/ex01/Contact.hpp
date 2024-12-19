/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:10:12 by rlane             #+#    #+#             */
/*   Updated: 2024/12/19 13:05:51 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    // Helper function to truncate strings longer than 10 characters
    std::string truncate(const std::string &text) const;
    
public:
    Contact();  // Default constructor
    ~Contact(); // Destructor

    void setDetails();

    void displaySummary(int index) const;

    void displayDetails() const;
};

#endif
