/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:39 by lsampiet          #+#    #+#             */
/*   Updated: 2025/08/14 18:44:51 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define MAGENTA "\033[0;35m"
#define BLUE "\033[34m"
# define CYAN "\033[0;36m"
# define RST "\033[0m"

class Bureaucrat {
	protected:
		std::string		_name;
		unsigned int	_grade;

	public:
		//Canonical form constructors, operator and destructor
		Bureaucrat(); //Default Constructor
		Bureaucrat(std::string name, unsigned int grade); //Param Constructor
		Bureaucrat(const Bureaucrat &other); //Copy Constructor
		Bureaucrat &operator=(const Bureaucrat &other); //Copy assignment operator
		~Bureaucrat(); //Default Destructor

		//Getters and setters
		std::string		getName() const;
		void			setName(const std::string &name);
		unsigned int	getGrade() const;
		void			setGrade(unsigned int grade);

		//Grade manipulation
		void			incrementGrade();
		void			decrementGrade();

		//Nested classes for exceptions
		class GradeTooHighException : public std::exception { //Nested Class
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception { //Nested Class
		public:
			virtual const char *what() const throw();
		};

		//Operators
		Bureaucrat &operator++();
		Bureaucrat operator++(int);
		Bureaucrat &operator--();
		Bureaucrat operator--(int);
		
};
		std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureau);

#endif