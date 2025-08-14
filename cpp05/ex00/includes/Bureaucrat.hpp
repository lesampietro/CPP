/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:39 by lsampiet          #+#    #+#             */
/*   Updated: 2025/08/14 15:24:00 by lsampiet         ###   ########.fr       */
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
		Bureaucrat(); //Default Constructor
		Bureaucrat(std::string name, unsigned int grade); //Param Constructor
		Bureaucrat(const Bureaucrat &other); //Copy Constructor
		Bureaucrat &operator=(const Bureaucrat &other); //Copy assignment operator
		virtual ~Bureaucrat(); //Default Destructor

		std::string		getName() const;
		void			setName(const std::string &name);
		unsigned int	getGrade() const;
		void			setGrade(unsigned int grade);

		void			GradeTooHighException();
		void			GradeTooLowException();

		Bureaucrat &operator++();
		Bureaucrat operator++(int);
		Bureaucrat &operator--();
		Bureaucrat operator--(int);
		
};
		std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureau);

#endif

// Remember, since grade 1 is the highest and 150 the lowest,incrementing a grade 3 should result in a grade 2 for the bureaucrat.