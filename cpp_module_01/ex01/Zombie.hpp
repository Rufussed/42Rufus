/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:33:07 by rlane             #+#    #+#             */
/*   Updated: 2024/12/19 18:16:03 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>
#include <sstream>

class Zombie {
	
private:
    std::string _name;
	
public:
    Zombie(); // Constructor
    Zombie(std::string name); // Constructor
    ~Zombie(); // Destructor
    void setZombieName(std::string name); // Setter
    void announce() const; 	
};

Zombie* zombieHorde(int N, std::string name);

void destroyHorde(Zombie* horde);

#endif 
