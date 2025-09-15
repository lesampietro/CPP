
#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <exception>
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	public:
		// ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		void	beSigned(const Bureaucrat &bureau);
		void	execute(const Bureaucrat& bureau);
};

#endif