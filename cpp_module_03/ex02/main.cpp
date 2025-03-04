/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:29:19 by rlane             #+#    #+#             */
/*   Updated: 2025/03/04 16:36:51 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"      
#define GREEN   "\033[32m"      
#define YELLOW  "\033[33m"      

int main()
{
    std::cout << YELLOW "\nCreate 2 FragTraps:\n" RESET << std::endl;
    FragTrap fraggy("Fraggy");
    FragTrap trappy("Trappy");

    std::cout << GREEN "\n** playtime! **\n" RESET << std::endl;

    trappy.attack("Fraggy");
    fraggy.takeDamage(30);
    fraggy.beRepaired(10);

    std::cout << RED "\n** High Five Time! **\n" RESET << std::endl;

    fraggy.highFivesGuys();

    std::cout << RED "\nExit and destroy: (reverse order to create!)\n" RESET << std::endl;

    return 0;
}
