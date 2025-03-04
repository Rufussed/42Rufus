/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:30:35 by rlane             #+#    #+#             */
/*   Updated: 2025/03/04 16:18:31 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

// default constructor
FragTrap::FragTrap(const std::string& name) 
	: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor called: FragTrap " << _name << " created" << std::endl;
}

//copy constructor
FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
}

//destructor
FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called: FragTrap " << _name << " destroyed" << std::endl;
}

//assignation operator
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap assignation operator called" << std::endl;
    std::cout << "FragTrap " << other._name << " will now be assigned to " << _name << std::endl;
    if (this == &other)
        return *this;
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " raises its robotic hand to recieve a high five. Don't leave it hanging!" << std::endl;
}

void FragTrap::attack(const std::string& target) 
{
    if (_hitPoints > 0 && _energyPoints > 0) 
	{
        std::cout << "FragTrap " << _name << " attacks " << target << " for " << _attackDamage << " hit points of damage!" << std::endl;
        _energyPoints--;
    } 
	else if (_hitPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " cannot attack, it is dead!" << std::endl;
	} 
	else
	{
        std::cout << "FragTrap " << _name << " is too low on energy to attack!" << std::endl;
    }
}
