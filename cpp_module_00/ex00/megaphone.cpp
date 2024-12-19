/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:03:05 by rlane             #+#    #+#             */
/*   Updated: 2024/12/19 12:28:40 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char *argv[])
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < argc; ++i)
        {
            std::string announce_string = argv[i];
            for (size_t j = 0; j < announce_string.length(); ++j)
                std::cout << static_cast<char>(toupper(announce_string[j]));
        }
        std::cout << std::endl;
    }

    return 0;
}