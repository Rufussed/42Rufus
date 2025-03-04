/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:36:23 by rlane             #+#    #+#             */
/*   Updated: 2025/03/04 16:19:55 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap :  public ScavTrap, public FragTrap
{
private:
    std::string _name;
    
public:
    // standard constructor
    DiamondTrap(const std::string& name);
    // copy constructor
    DiamondTrap(const DiamondTrap& other);
    // destructor
    ~DiamondTrap();
    // assignation operator
    DiamondTrap& operator=(const DiamondTrap& other);

    using ScavTrap::attack;

    void whoAmI();
};

#endif // DIAMONDTRAP_HPP