/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:29:54 by rlane             #+#    #+#             */
/*   Updated: 2025/02/26 08:48:31 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

// default constructor
ScavTrap::ScavTrap(const std::string& name) 
	: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor called: ScavTrap " << _name << " created" << std::endl;
}

//copy constructor
ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

//destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called: ScavTrap " << _name << " destroyed" << std::endl;
}

//assignation operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	std::cout << "ScavTrap " << other._name << " will now be assigned to " << _name << std::endl;
	if (this == &other)
		return *this;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is guarding the gate" << std::endl;
}
