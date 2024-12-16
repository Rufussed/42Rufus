/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:35:00 by rlane             #+#    #+#             */
/*   Updated: 2024/12/16 15:32:11 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

class HumanB {
private:
	std::string _name;
	Weapon* _weapon; // humanB may not have a weapon so a pointer is used
public:
	HumanB(std::string name);
	~HumanB();
	void setWeapon(Weapon& weapon);
	void attack();
};


#endif