#ifndef INTERN_HPP
#define INTERN_HPP

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define MAGENTA "\033[0;35m"
# define BLUE "\033[34m"
# define CYAN "\033[0;36m"
# define RST "\033[0m"

# include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

class Intern {
	public:
			Intern();
			Intern(const Intern &copy);
			Intern &operator=(const Intern &copy);
			~Intern();

		class FormException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	AForm	*makeForm(const std::string &formName, const std::string &target);
};

# endif