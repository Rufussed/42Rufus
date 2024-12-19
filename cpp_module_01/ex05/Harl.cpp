/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:49:44 by rlane             #+#    #+#             */
/*   Updated: 2024/12/19 18:58:35 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::complain(std::string level) {

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	// Array of pointers to member function
	void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; ++i) {
		if (levels[i] == level) {
			(this->*functions[i])(); // Call member function (the content of the pointer)
			return;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::debug( void )
{
	std::string DEBUG = "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
	std::cout << DEBUG << std::endl;
}
void Harl::info( void )
{
	std::string INFO = "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
	std::cout << INFO << std::endl;
}
void Harl::warning( void )
{
	std::string WARNING = "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
	std::cout << WARNING << std::endl;
}
void Harl::error( void )
{
	std::string ERROR = "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n";
	std::cout << ERROR << std::endl;
}
