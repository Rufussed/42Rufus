/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:29:19 by rlane             #+#    #+#             */
/*   Updated: 2025/02/26 09:29:35 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap scavvy("Scavvy");
    ScavTrap trappy("Trappy");

    scavvy.guardGate();

    trappy.attack("Scavvy");
    scavvy.takeDamage(20);
    scavvy.beRepaired(10);

    trappy.attack("Scavvy");
    scavvy.takeDamage(200); // fatal damage
    scavvy.beRepaired(10); // should not be repairable
    
    
    
    trappy = scavvy;
    trappy.attack("Scavvy"); // cannot attack, as already dead

    return 0;
}
