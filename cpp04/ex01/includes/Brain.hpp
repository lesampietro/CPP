/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:57:08 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/22 18:49:28 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain {
	private:
		std::string	_ideas[100];

	public:
		Brain(); //Default Constructor
		Brain(const Brain &other); //Copy Constructor
		Brain &operator=(const Brain &other); //Copy assignment operator
		virtual ~Brain(); //Default Destructor

		void setIdea(int index, const std::string &idea);
		std::string getIdea(int index) const;
};

#endif