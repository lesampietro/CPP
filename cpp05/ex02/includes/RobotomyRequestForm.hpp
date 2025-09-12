
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;

	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		// void	beSigned(const Bureaucrat &bureau);
		void	execute(const Bureaucrat& bureau) const;
};

#endif