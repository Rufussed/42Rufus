/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:28:25 by rlane             #+#    #+#             */
/*   Updated: 2024/12/12 17:52:48 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        std::string newName = name + std::to_string(i);
        horde[i].setZombieName(newName);
        horde[i].announce();
    }
    return horde;
}

void destroyHorde(Zombie* horde)
{
    delete[] horde;
}