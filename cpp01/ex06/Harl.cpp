/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:19:56 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/19 18:08:39 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug(void){
	std::cout << CYAN << "\nDEBUG" << RST << std::endl;
	std::cout << "Harl says: \"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!\"\n";
	std::cout << std::endl;
}

void Harl::info(void){
	std::cout << GREEN << "\nINFO" << RST << std::endl;
	std::cout << "Harl says: \"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\"\n";
	std::cout << std::endl;
}

void	Harl::warning(void){
	std::cout << YELLOW << "\nWARNING" << RST << std::endl;
	std::cout << "Harl says: \"I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\"\n";
	std::cout
		<< std::endl;
}

void	Harl::error(void){
	std::cout << MAGENTA << "\nERROR" << RST << std::endl;
	std::cout << "Harl says: \"This is unacceptable! I want to speak to the manager now.\"\n";
	std::cout << std::endl;
}

void	Harl::complain(std::string level)
{
	void (Harl::*functions[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};

	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	
	int	i = 0;

	while (levels[i] != level){
		i++;
	}
	
	(this->*functions[i])();
}