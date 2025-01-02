/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:30:56 by rlane             #+#    #+#             */
/*   Updated: 2024/12/19 18:27:59 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Address of string variable : " << &str << std::endl;
    std::cout << "Address stored in pointer  : " << stringPTR << std::endl;
    std::cout << "Address of reference       : " << &stringREF << std::endl;
    
    std::cout << "Value of string variable       : " << str << std::endl;
    std::cout << "Value pointed to by pointer    : " << *stringPTR << std::endl;
    std::cout << "Value referred to by reference : " << stringREF << std::endl;
    return 0;
}