/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:07:34 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/08 15:07:56 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	int i = 1;
	while (--argc)
	{
		char *str = argv[i];
		while (*str)
		{
			if (*str >= 'a' && *str <= 'z')
				*str = *str - 32;
			std::cout << *str;
			str++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
