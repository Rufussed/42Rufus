/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:28:25 by rlane             #+#    #+#             */
/*   Updated: 2024/12/12 17:52:25 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// default constructor
Zombie::Zombie()
{}

// Constructor
Zombie::Zombie(std::string name) : _name(name) {}

// Destructor
Zombie::~Zombie()
{
    std::cout << _name << " is destroyed.\n";
}

void Zombie::announce() const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setZombieName(std::string name)
{
    _name = name;
}
