/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:42:04 by rlane             #+#    #+#             */
/*   Updated: 2024/12/16 15:26:45 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with his " << _weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon& weapon)
{
	_weapon = weapon;
}
