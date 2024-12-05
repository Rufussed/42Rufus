/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:10:12 by rlane             #+#    #+#             */
/*   Updated: 2024/12/05 15:22:08 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "PhoneBook.hpp"
#include <string>

class Contact {
private:
	// Private member variables
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	// Public member functions
	void setDetails(const std::string &firstName, const std::string &lastName,
	                const std::string &nickname, const std::string &phoneNumber,
	                const std::string &darkestSecret);

	std::string getSummary(int fieldWidth = 10) const;

	void displayFullDetails() const;
};

#endif // CONTACT_HPP
