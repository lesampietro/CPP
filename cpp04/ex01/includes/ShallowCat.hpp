/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShallowCat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:19:20 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/25 16:58:16 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHALLOWCAT_HPP
# define SHALLOWCAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class ShallowCat {
	private:
		Brain* _brain;

	public:
		ShallowCat(); //Default Constructor
		ShallowCat(const ShallowCat &other); //Copy Constructor
		ShallowCat &operator=(const ShallowCat &other); //Copy assignment operator
		~ShallowCat(); //Default Destructor

		void	makeSound() const;
		Brain* getBrain() const;
};

#endif