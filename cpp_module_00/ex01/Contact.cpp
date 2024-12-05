/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:08:41 by rlane             #+#    #+#             */
/*   Updated: 2024/12/05 15:19:12 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

class Contact {
private:
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

public:
	void setDetails(const std::string& firstName, const std::string& lastName,
	                const std::string& nickname, const std::string& phoneNumber,
	                const std::string& darkestSecret) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->nickname = nickname;
		this->phoneNumber = phoneNumber;
		this->darkestSecret = darkestSecret;
	}

	std::string getSummary(int fieldWidth = 10) const {
		auto truncate = [](const std::string& str, int width) {
			return str.size() > width ? str.substr(0, width - 1) + "." : str;
		};
		return truncate(firstName, fieldWidth) + "|" + truncate(lastName, fieldWidth) + "|" +
		       truncate(nickname, fieldWidth);
	}

	void displayFullDetails() const {
		std::cout << "First Name: " << firstName << "\n"
		          << "Last Name: " << lastName << "\n"
		          << "Nickname: " << nickname << "\n"
		          << "Phone Number: " << phoneNumber << "\n"
		          << "Darkest Secret: " << darkestSecret << "\n";
	}
};


