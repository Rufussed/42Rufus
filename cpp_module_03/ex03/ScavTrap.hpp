/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:30:04 by rlane             #+#    #+#             */
/*   Updated: 2025/02/28 14:57:22 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
    //standard constructor
    ScavTrap(const std::string& name);
    // copy constructor
    ScavTrap(const ScavTrap& other);
    // destructor
    ~ScavTrap();
    // assignation operator
    ScavTrap& operator=(const ScavTrap& other);

void guardGate();
virtual void attack(const std::string& target);
};

#endif // SCAVTRAP_HPP