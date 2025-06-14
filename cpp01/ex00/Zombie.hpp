/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:12:29 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/14 18:23:40 by lsampiet         ###   ########.fr       */
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

		void		announce(void);
		// Zombie		*newZombie(std::string name);
		void		randomChump(std::string name);

		std::string	getZombieName() const;
};

#endif