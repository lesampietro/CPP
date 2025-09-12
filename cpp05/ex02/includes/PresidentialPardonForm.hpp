
#ifndef PRESIDENTILPARDONFORM_HPP
# define PRESIDENTILPARDONFORM_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;

	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		// void	beSigned(const Bureaucrat &bureau);
		void	execute(const Bureaucrat& bureau) const;
};

#endif