/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:39 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/18 14:41:17 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(); //Default Constructor
		ScavTrap(std::string name); //Custom Constructor
		ScavTrap(const ScavTrap &copy); //Def. Copy Constructor
		ScavTrap &operator=(const ScavTrap &other); //Def. Assignment Operator
		~ScavTrap(); //Default Destructor

		void	attack(const std::string &target);//Overwrite ClapTrap::attack()
		void	guardGate(); //New method
};

#endif