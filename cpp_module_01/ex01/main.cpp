/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:30:56 by rlane             #+#    #+#             */
/*   Updated: 2024/12/12 17:52:07 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N;
    std::cout << "Enter the number of zombies in the horde: ";
    std::cin >> N;
    // check for int
    if (std::cin.fail())
    {
        std::cerr << "Invalid input. Please enter an integer.\n";
        return 1;
    }
    std::cout << "Enter the name of the horde: ";
    std::string horde_name;
    std::cin >> horde_name;    
    Zombie* myhorde = zombieHorde(N, horde_name);
    delete[] myhorde; 
    return 0;
}