/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:57:08 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/26 23:44:19 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "AAnimal.hpp"

class Brain {
	private:
		std::string	_ideas[100];

	public:
		Brain(); //Default Constructor
		Brain(const Brain &other); //Copy Constructor
		Brain &operator=(const Brain &other); //Copy assignment operator
		virtual ~Brain(); //Default Destructor

		std::string getIdea(int index) const; //Getter
		void setIdea(int index, const std::string &idea); //Setter
};

#endif