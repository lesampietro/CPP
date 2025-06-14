/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:12:29 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/14 18:49:46 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <cctype>
# include <iostream>

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