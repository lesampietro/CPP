#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define MAGENTA "\033[0;35m"
#define BLUE "\033[34m"
# define CYAN "\033[0;36m"
# define RST "\033[0m"

class Bureaucrat {
	protected:
		static const int	MAX_GRADE = 1;
		static const int	MIN_GRADE = 150; // Static means it does not belong to an object but to the whole class
		const std::string	_name;
		int					_grade;

	public:
		//Canonical form constructors, operator and destructor
		Bureaucrat(); //Default Constructor
		Bureaucrat(std::string name, unsigned int grade); //Param Constructor
		Bureaucrat(const Bureaucrat &other); //Copy Constructor
		Bureaucrat &operator=(const Bureaucrat &other); //Copy assignment operator
		~Bureaucrat(); //Default Destructor

		//Getters
		std::string		getName() const;
		int				getGrade() const;

		//Grade manipulation
		void			incrementGrade();
		void			decrementGrade();

		//Nested classes for exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class InsufficientGradeException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		void	signForm(AForm &form);
		void	executeForm(AForm &form);
};
		std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureau);

#endif