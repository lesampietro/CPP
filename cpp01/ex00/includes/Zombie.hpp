/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:12:29 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/21 12:17:19 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <cctype>
# include <iostream>

# define YELLOW "\033[0;33m"
# define RST "\033[0m"

class	Zombie{
	private:
		std::string	name;
	
	public:
		Zombie(void);
		~Zombie(void);

		void	announce(void);
		void	setName(std::string name);
};
	
Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif