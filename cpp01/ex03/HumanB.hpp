/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:33:38 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/16 17:27:03 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class	HumanB{
		private:
			std::string	name;
			Weapon	*weapon; //pointer - because it can be deferenced
		public:
			HumanB();
			HumanB(std::string name);
			~HumanB();
			
		void	attack();
		void	setWeapon(Weapon &newWeapon); //receives a reference to avoid creating an unnecessary copy of the weapon object
};

// HumanB may not have a weapon, therefore uses a pointer which can be NULL.
// The pointer(Weapon *weapon) stores the address to the original Weapon object.
// By using -> to acess this object, it's possible to access the original object by its address.