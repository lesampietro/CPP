/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:57:08 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/22 17:01:41 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain {
	protected:
		std::string	_ideas[100];

	public:
		Brain(); //Default Constructor
		Brain(const Brain &other); //Copy Constructor
		Brain &operator=(const Brain &other); //Copy assignment operator
		virtual ~Brain(); //Default Destructor
};

#endif