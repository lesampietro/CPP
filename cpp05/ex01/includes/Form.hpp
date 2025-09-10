
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

class Bureaucrat; //Forward declaration to avoid circular dependency

class Form {
	private:
		static const int	MIN_GRADE = 150;
		static const int	MAX_GRADE = 1;
		const std::string	_name;
		bool				_isSigned;
		const int			_toSignGrade;
		const int			_toExecuteGrade;
	
	public:
		Form();
		Form(const std::string name, const int toSignGrade, const int toExecuteGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
		
		// Getters
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;

		void		beSigned(const Bureaucrat &bureau);

		// Nested classes for exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class FormAlreadySignedException : public std::exception	{
			public:
				virtual const char *what() const throw();
		};
};

		std::ostream &operator<<(std::ostream &out, const Form &form);

#endif