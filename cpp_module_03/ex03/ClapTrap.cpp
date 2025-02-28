/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:29:34 by rlane             #+#    #+#             */
/*   Updated: 2025/02/28 13:32:05 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) 
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap constructor called: ClapTrap " << _name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called: ClapTrap " << _name << " destroyed"<< std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	std::cout << "ClapTrap " << other._name << " will now be assigned to " << _name << std::endl;
	if (this == &other)
		return *this;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string& target) 
{
    if (_hitPoints > 0 && _energyPoints > 0) 
	{
        std::cout << "ClapTrap " << _name << " attacks " << target << " for " << _attackDamage << " hit points of damage!" << std::endl;
        _energyPoints--;
    } 
	else if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot attack, it is dead!" << std::endl;
	} 
	else
	{
        std::cout << "ClapTrap " << _name << " is too low on energy to attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		std::cout << _name << " takes " << amount << " points of damage!" << std::endl;
		_hitPoints -= amount;
	}
	else
		std::cout << _name << " is already dead!" << std::endl;
	if (_hitPoints < 0)
	std::cout << _name << " died" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0 && _energyPoints > 0) 
	{
		std::cout << _name << " is repaired for " << amount << " hit points!" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
	else if (_hitPoints <= 0)
		std::cout << "It is too late for repairs! " << _name << " is already dead" << std::endl;
	else
		std::cout << _name << " is too low on energy to make repairs!" << std::endl;
}