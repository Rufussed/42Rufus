/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:29:19 by rlane             #+#    #+#             */
/*   Updated: 2025/03/04 16:36:33 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"      
#define GREEN   "\033[32m"      
#define YELLOW  "\033[33m"      

int main()
{
    std::cout << YELLOW "\nCreate 2 DiamondTraps:\n" RESET << std::endl;
    DiamondTrap sparkly("Sparkly");
    DiamondTrap forever("Forever");

    std::cout << GREEN "\n** Test basic inherited actions **\n" RESET << std::endl;
    sparkly.attack("Forever");
    forever.takeDamage(sparkly.getAttackDamage());
    forever.beRepaired(1);
    sparkly.guardGate();
    sparkly.highFivesGuys();
    sparkly.whoAmI();

    std::cout << YELLOW "\nTest copy constructor:\n" RESET << std::endl;
    DiamondTrap copy_Sparkly(sparkly);
    copy_Sparkly.whoAmI();

    std::cout << YELLOW "\nTest assignment operator: create \'Placeholder\', then assign \'Forever\'\n" RESET << std::endl;
    DiamondTrap assigned_Forever("Placeholder");
    assigned_Forever = forever;
    assigned_Forever.whoAmI();

    std::cout << RED "\nExit and destroy (reverse order to create!):\n" RESET << std::endl;

    return 0;
}

