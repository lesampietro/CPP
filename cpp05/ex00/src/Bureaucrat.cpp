/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:29 by lsampiet          #+#    #+#             */
/*   Updated: 2025/08/24 17:14:59 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(1) {
	std::cout << BLUE << this->_name;
	std::cout << RST << " created." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else {
		this->_grade = grade;
		std::cout << BLUE << this->_name << RST;
		std::cout << " created with grade: ";
		std::cout << CYAN << this->_grade << RST << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {
	std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat copy assignment operator called." << std::endl;
	std::cout << std::endl;
	if (this != &other) { // Check for self-assignment
		this->_name = other._name;
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << BLUE << this->_name;
	std::cout << RST << " has been ~destroyed." << std::endl;
}

std::string	Bureaucrat::getName() const {
	return this->_name;
}

void	Bureaucrat::setName(const std::string &name) {
	this->_name = name;
}

unsigned int	Bureaucrat::getGrade() const {
	return this->_grade;
}

void	Bureaucrat::setGrade(unsigned int grade) {
	if (grade > 0 && grade <= 150)
	this->_grade = grade;
}

void	Bureaucrat::incrementGrade() {
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high (maximum grade is 1)";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low (minimum grade is 150)";
}

Bureaucrat&	Bureaucrat::operator++() {
	this->_grade++;
	return (*this);
}

Bureaucrat	Bureaucrat::operator++(int) {
	Bureaucrat temp(*this);
	this->_grade++;
	return (temp);
}

Bureaucrat&	Bureaucrat::operator--() {
	this->_grade--;
	return (*this);
}

Bureaucrat	Bureaucrat::operator--(int) {
	Bureaucrat temp(*this);
	this->_grade--;
	return (temp);
}

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &bureau){
	out << bureau.getName();
	return out;
}