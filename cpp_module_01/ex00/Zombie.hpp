/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:33:07 by rlane             #+#    #+#             */
/*   Updated: 2024/12/12 16:18:54 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie {
	
private:
    std::string _name;
	
public:
    Zombie(std::string name); // Constructor
    ~Zombie(); // Destructor
    void announce() const; 	
};

Zombie* newZombie(std::string name);

void randomChump(std::string name);

#endif 
