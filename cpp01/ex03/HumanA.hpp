/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:33:38 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/16 17:28:28 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class	HumanA{
	private:
		std::string	name;
		Weapon	&weapon; //reference - because it will always be the same
	public:
		// HumanA(); - can not have an empty constructor, because it's using a reference as a member.
		HumanA(std::string name, Weapon &weapon); // needs to receive the reference here as well
		~HumanA();
		
		void	attack();
};

// HumanA always has a weapon and uses the reference, which can never be NULL.
// The reference(Weapon &weapon) creates an alias for the original Weapon object.
// Any changes done to the original object is reflected upon access by reference, because it is the same object (same memory address).