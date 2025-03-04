/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:29:54 by rlane             #+#    #+#             */
/*   Updated: 2025/03/04 16:08:46 by rlane            ###   ########.fr       */
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
	_hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
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
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target) 
{
    if (_hitPoints > 0 && _energyPoints > 0) 
	{
        std::cout << "ScavTrap " << _name << " attacks " << target << " for " << _attackDamage << " hit points of damage!" << std::endl;
        _energyPoints--;
    } 
	else if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " cannot attack, it is dead!" << std::endl;
	} 
	else
	{
        std::cout << "ScavTrap " << _name << " is too low on energy to attack!" << std::endl;
    }
}
