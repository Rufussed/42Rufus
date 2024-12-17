/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufus <rufus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:50:50 by rufus             #+#    #+#             */
/*   Updated: 2024/12/17 13:52:22 by rufus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <fstream> // For file handling
# include <string>  // For std::string

class Harl
{
public:
    Harl();
    ~Harl();
    void complain( std::string level );
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
};