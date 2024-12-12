/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:30:56 by rlane             #+#    #+#             */
/*   Updated: 2024/12/12 16:19:42 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() 
{
    // Create a Zombie on the heap using newZombie
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie; // Manually delete heap memory

    // Create a Zombie on the stack using randomChump
    randomChump("StackZombie");
    // StackZombie is destroyed when it goes out of scope

    return 0;
}