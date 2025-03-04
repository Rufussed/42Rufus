/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:29:24 by rlane             #+#    #+#             */
/*   Updated: 2025/03/03 14:55:58 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
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

virtual void attack(const std::string& target);

void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);
int getAttackDamage();
};

#endif // CLAPTRAP_HPP
