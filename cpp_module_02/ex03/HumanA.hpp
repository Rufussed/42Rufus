/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:55:42 by rlane             #+#    #+#             */
/*   Updated: 2024/12/16 15:31:55 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"

class HumanA {
private:
	std::string _name;
	Weapon& _weapon; // humanA always has a weapon so a reference is used
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
	void setWeapon(Weapon& weapon);
	void attack();
};


#endif