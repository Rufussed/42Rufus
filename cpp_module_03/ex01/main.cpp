/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:29:19 by rlane             #+#    #+#             */
/*   Updated: 2025/03/04 16:37:02 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << YELLOW "\nCreate 2 ScavTraps:\n" RESET << std::endl;
    ScavTrap scavvy("Scavvy");
    ScavTrap trappy("Trappy");

    std::cout << YELLOW "\nTest guardGate method:\n" RESET << std::endl;
    scavvy.guardGate();

    std::cout << GREEN "\n** playtime! **\n" RESET << std::endl;

    trappy.attack("Scavvy");
    scavvy.takeDamage(trappy.getAttackDamage());
    scavvy.beRepaired(10);

    std::cout << RED "\n** Now it's getting rough! **\n" RESET << std::endl;

    trappy.attack("Scavvy");
    scavvy.takeDamage(trappy.getAttackDamage());
    trappy.attack("Scavvy");
    scavvy.takeDamage(trappy.getAttackDamage());
    trappy.attack("Scavvy");
    scavvy.takeDamage(trappy.getAttackDamage());
    trappy.attack("Scavvy");
    scavvy.takeDamage(trappy.getAttackDamage());
    trappy.attack("Scavvy");
    scavvy.takeDamage(trappy.getAttackDamage());
    trappy.attack("Scavvy");
    scavvy.takeDamage(trappy.getAttackDamage()); // fatal damage
    
    scavvy.beRepaired(10); // should not be repairable

    std::cout << YELLOW "\nTest the assignment operator:\n" RESET << std::endl;
    trappy = scavvy;
    trappy.attack("Scavvy"); // cannot attack, as already dead

    std::cout << RED "\nExit and destroy: (reverse order to create!)\n" RESET << std::endl;

    return 0;
}
