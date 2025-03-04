/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:44:41 by rlane             #+#    #+#             */
/*   Updated: 2025/03/04 15:28:14 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

// default constructor
DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    _name = name;
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << _name << " is here!" << std::endl;
}

// copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other._name + "_clap_name"), ScavTrap(other), FragTrap(other),
      _name(other._name)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

// destructor
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " is destroyed" << std::endl;
}

// Assignation operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap assignation operator called" << std::endl;
    std::cout << "DiamondTrap " << other._name << " will now be assigned to " << ClapTrap::_name << std::endl;
    if (this == &other)
        return *this;
    ClapTrap::operator=(other);
    ScavTrap::operator=(other);
    FragTrap::operator=(other);
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}