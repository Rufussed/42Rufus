/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:09:15 by rlane             #+#    #+#             */
/*   Updated: 2024/12/05 15:19:27 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int currentIndex = 0;
	int totalContacts = 0;

public:
	void addContact(const Contact& contact) {
		contacts[currentIndex] = contact;
		currentIndex = (currentIndex + 1) % 8;
		if (totalContacts < 8) totalContacts++;
	}

	void displayContacts() const {
		std::cout << std::setw(10) << "Index" << "|"
		          << std::setw(10) << "First Name" << "|"
		          << std::setw(10) << "Last Name" << "|"
		          << std::setw(10) << "Nickname" << "\n";
		for (int i = 0; i < totalContacts; i++) {
			std::cout << std::setw(10) << i << "|" << contacts[i].getSummary() << "\n";
		}
	}

	void displayContactDetails(int index) const {
		if (index < 0 || index >= totalContacts) {
			std::cout << "Invalid index!\n";
			return;
		}
		contacts[index].displayFullDetails();
	}
};