/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:28:31 by rlane             #+#    #+#             */
/*   Updated: 2024/12/12 16:18:01 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name) 
{
    Zombie tempZombie(name); // Create Zombie on stack
    tempZombie.announce(); 
	// tempZombie is destroyed when it goes out of scope
}