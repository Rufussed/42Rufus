/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:29:19 by rlane             #+#    #+#             */
/*   Updated: 2025/02/26 09:32:43 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clappy("Clappy");
    ClapTrap trappy("Trappy");

    std::cout << "\n** playtime! **\n" << std::endl;

    clappy.attack("Trappy");
    trappy.takeDamage(0);
    trappy.beRepaired(0);

    std::cout << "\n** Now it's getting rough! **\n" << std::endl;

    clappy.attack("Trappy"); // damage capacicity is 0
    trappy.takeDamage(100); // but we do fatal damage to Trappy anyway
    trappy.beRepaired(10); // Trappy should not be repairable
    trappy.attack("Clappy"); // Trappy is dead, cannot attack

    for (int i = 0; i < 11; i++)
    {
        clappy.beRepaired(0);
    }
    

    trappy = clappy;

    ClapTrap* final_clap = new ClapTrap("Final Clap");
    delete final_clap;

    return 0;
}
