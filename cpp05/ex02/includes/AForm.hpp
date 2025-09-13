
#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>

class Bureaucrat; //Forward declaration to avoid circular dependency

class AForm {
	private:
		static const int	MIN_GRADE = 150;
		static const int	MAX_GRADE = 1;
		const std::string	_name;
		bool				_isSigned;
		const int			_toSignGrade;
		const int			_toExecuteGrade;
	
	public:
		AForm();
		AForm(const std::string name, const int toSignGrade, const int toExecuteGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();
		
		// Getters
		std::string		getName() const;
		bool			getIsSigned() const;
		int				getSignGrade() const;
		int				getExecuteGrade() const;

		// Setters
		bool			setIsSigned(const bool signState);

		virtual void	beSigned(const Bureaucrat &bureau) = 0;
		virtual void	execute(const Bureaucrat &bureau) const = 0;

		// Nested classes for exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class FormAlreadySignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

		std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif