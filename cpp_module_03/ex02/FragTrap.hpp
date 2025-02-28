/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:30:56 by rlane             #+#    #+#             */
/*   Updated: 2025/02/28 13:40:12 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    //standard constructor
    FragTrap(const std::string& name);
    // copy constructor
    FragTrap(const FragTrap& other);
    // destructor
    ~FragTrap();
    // assignation operator
    FragTrap& operator=(const FragTrap& other);

void highFivesGuys(void);
virtual void attack(const std::string& target);
};


#endif // FRAGTRAP_HPP