/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:10:37 by rlane             #+#    #+#             */
/*   Updated: 2024/12/19 15:21:40 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <limits>

#define ORANGE "\033[38;2;255;165;0m"
#define RESET "\033[0m"
#define MAX_CONTACTS 8

class PhoneBook
{
private:
    Contact contacts[MAX_CONTACTS]; // Fixed array of contacts
    int count;                      // Number of entered contacts

public:
    PhoneBook();
    ~PhoneBook();

    void addContact();

    void searchContacts() const;
};

#endif
