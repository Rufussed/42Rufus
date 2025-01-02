/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:56:29 by rlane             #+#    #+#             */
/*   Updated: 2024/12/19 18:35:01 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <string>
#include <iostream>

class Weapon {
private:
	std::string _type;
public:
	Weapon(); // Default Constructor
	Weapon(std::string type); // Constructor with parameter
	~Weapon(); // Destructor
	const std::string& getType();
	void setType(std::string type);
};

#endif