
#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include <iostream>
# include <exception>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;

	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		void	beSigned(const Bureaucrat &bureau);
		void	execute(const Bureaucrat& bureau) const;
};

#endif