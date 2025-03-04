/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:29:19 by rlane             #+#    #+#             */
/*   Updated: 2025/03/04 16:02:52 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    //create 2 ClapTraps
    std::cout << YELLOW "\nCreate 2 ClapTraps:\n" RESET << std::endl;
    ClapTrap clappy("Clappy");
    ClapTrap trappy("Trappy");

    //test copy constructor
    std::cout << YELLOW "\nTest copy constructor, copying trappy:\n" RESET << std::endl;
    ClapTrap trappy_copy(trappy);
    

    std::cout << GREEN "\n** playtime! **\n" RESET << std::endl;

    clappy.attack("Trappy");
    trappy.takeDamage(clappy.getAttackDamage());
    trappy.beRepaired(0);

    std::cout << RED "\n** Now it's getting rough! **\n" RESET << std::endl;

    clappy.attack("Trappy"); // damage capacicity is 0
    trappy.takeDamage(100); // but we do fatal damage to Trappy anyway
    trappy.beRepaired(10); // Trappy should not be repairable
    trappy.attack("Clappy"); // Trappy is dead, cannot attack

    std::cout << YELLOW "\nTest the beRepaired method\n" RESET << std::endl;

    for (int i = 0; i < 11; i++)
    {
        clappy.beRepaired(0);
    }
    
    std::cout << YELLOW "\nTest the assignment operator **\n" RESET << std::endl;
    trappy = clappy;

    std::cout << YELLOW "\nTest assignation op with 'new' for memory alloc & delete\n" RESET << std::endl;
    ClapTrap* new_clap = new ClapTrap("New Clap");
    delete new_clap;

    std::cout << RED "\nExit and destroy:\n" RESET << std::endl;

    return 0;
}
