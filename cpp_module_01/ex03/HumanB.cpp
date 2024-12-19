/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:30:00 by rlane             #+#    #+#             */
/*   Updated: 2024/12/19 18:31:16 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) 
{
}

HumanB::~HumanB() {}

void HumanB::attack()
{
	if (this->_weapon == NULL) // if his weapon pointer is NULL then he has no weapon
	{
		std::cout << this->_name << " has no weapon to attack with." << std::endl;
		return;
	}
	else
	std::cout << this->_name << " attacks with his " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}