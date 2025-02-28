/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:30:56 by rlane             #+#    #+#             */
/*   Updated: 2025/02/28 14:57:14 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:

public:
    //standard constructor
    FragTrap(const std::string& name);
    // copy constructor
    FragTrap(const FragTrap& other);
    // destructor
    ~FragTrap();
    // assignation operator
    FragTrap& operator=(const FragTrap& other);

void highFivesGuys(void);

};


#endif // FRAGTRAP_HPP