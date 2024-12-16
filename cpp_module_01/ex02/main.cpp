/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:30:56 by rlane             #+#    #+#             */
/*   Updated: 2024/12/16 13:50:54 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "String address    : " << &str << std::endl;
    std::cout << "Pointer content   : " << stringPTR << std::endl;
    std::cout << "Reference address : " << &stringREF << std::endl;
    
    std::cout << "Value of string              : " << str << std::endl;
    std::cout << "Value of pointer to string   : " << *stringPTR << std::endl;
    std::cout << "Value of reference to string : " << stringREF << std::endl;
    return 0;
}