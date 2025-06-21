/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:17:15 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/21 15:16:56 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Replace.hpp"

int main(int argc, char **argv)
{	
	if (argc != 4){
		std::cerr << "Usage: " << argv[0];
		std::cerr << " <filename> <string_toBeReplaced> <string_toReplace>";
		std::cerr << std::endl;
		return 1;
	}

	std::string	filename = argv[1];
	std::string	toBeReplaced = argv[2];
	std::string	toReplace = argv[3];

	if (!replace(filename, toBeReplaced, toReplace))
		return 1;
	
	return 0;
}
