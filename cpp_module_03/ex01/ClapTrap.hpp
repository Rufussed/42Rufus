/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:29:24 by rlane             #+#    #+#             */
/*   Updated: 2025/03/04 16:06:08 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDYELLOW "\033[1;33m" /* Bold Yellow */

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
