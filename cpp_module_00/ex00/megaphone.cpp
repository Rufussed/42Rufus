/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:03:05 by rlane             #+#    #+#             */
/*   Updated: 2024/12/05 15:26:37 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
	using namespace std; 
	if (argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
	else
	{
		for (int i = 1; i < argc; ++i)
			for (int j = 0; argv[i][j] != '\0'; ++j)
				cout << static_cast<char>(toupper(argv[i][j]));
		cout << endl;
	}

	return 0;
}