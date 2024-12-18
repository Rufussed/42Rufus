/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:49:44 by rlane             #+#    #+#             */
/*   Updated: 2024/12/18 14:00:24 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::complain(std::string level)
{

	int log_level = -1; // if anything other than levels below

	if (level == "DEBUG")
		log_level = 0;
	else if (level == "INFO")
		log_level = 1;
	else if (level == "WARNING")
		log_level = 2;
	else if (level == "ERROR")
		log_level = 3;
	switch (log_level)
	{
	case 0:
		debug();
		// fallthrough
	case 1:
		info();
		// fallthrough
	case 2:
		warning();
		// fallthrough
	case 3:
		error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

void Harl::debug(void)
{
	std::string DEBUG = "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
	std::cout << DEBUG << std::endl;
}
void Harl::info(void)
{
	std::string INFO = "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
	std::cout << INFO << std::endl;
}
void Harl::warning(void)
{
	std::string WARNING = "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
	std::cout << WARNING << std::endl;
}
void Harl::error(void)
{
	std::string ERROR = "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n";
	std::cout << ERROR << std::endl;
}
