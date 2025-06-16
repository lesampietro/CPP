/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:28:40 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/16 16:35:23 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

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