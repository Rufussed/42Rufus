/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:01:26 by rlane             #+#    #+#             */
/*   Updated: 2024/12/16 15:18:58 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::~Weapon(){}

Weapon::Weapon(std::string type) : _type(type) {}

std::string Weapon::getType()
{
	return _type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}
