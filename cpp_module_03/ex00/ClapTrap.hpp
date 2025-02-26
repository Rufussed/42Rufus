/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:29:24 by rlane             #+#    #+#             */
/*   Updated: 2025/02/25 15:27:45 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:

std::string	_name;
int 	_hitPoints;
int 	_energyPoints;
int 	_attackDamage;

public:

//standard constructor
ClapTrap(const std::string& name);
// copy constructor
ClapTrap(const ClapTrap& other);
// destructor
~ClapTrap();
// assignation operator
ClapTrap& operator=(const ClapTrap& other);

void attack(const std::string& target);
void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP
