/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:28:40 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/16 19:25:11 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <iomanip>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BOLD "\033[1;37m"
# define MAGENTA "\033[0;35m"
# define RST "\033[0m"

class	Weapon{
		private:
			std::string type;
		public:
			Weapon();
			Weapon(std::string weaponType);
			~Weapon();
		
			void				setType(std::string newWeaponType);
			const std::string	&getType();
};

#endif