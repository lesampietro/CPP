/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:12:29 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/19 19:29:10 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <cctype>
# include <iostream>
# include <stdlib.h>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define RST "\033[0m"

class	Zombie{
	private:
		std::string	name;
	
	public:
		Zombie(void);
		~Zombie(void);

		void	announce(int N);
		void	setName(std::string name);
};
	
Zombie	*zombieHorde(int N, std::string name);

#endif