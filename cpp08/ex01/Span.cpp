#include "Span.hpp"

// by default, containers are created empty and do not need to be initialized. 
// it is a good practice to explicitly declare them on the initialization list.
Span::Span() : _size(0), _container() { 
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int n) : _size(n), _container() {
	// std::cout << "Span parametrized constructor called" << std::endl;
}

Span::Span(const Span &copy) : _size(copy._size), _container(copy._container) {
	// std::cout << "Span copy constructor called" << std::endl;
}

Span	&Span::operator=(const Span &other) {
	// std::cout << "Span assignment operator called" << std::endl;
	if (this != &other) {
		this->_size = other._size;
		this->_container = other._container;
	}
	return (*this);
}

Span::~Span() {
	// std::cout << "Span default destructor called" << std::endl;
}

void	Span::addNumber(const int number) {
    if (this->_container.size() >= this->_size) 
        throw ContainerFullException();
	else {
		_container.push_back(number);
		std::cout << "Adding " << number << " to the container" << std::endl;
	}
}		

int		Span::shortestSpan() {
	if (this->_container.size() < 2) {
		throw InsufficientValuesException();
	}
	std::vector<int> sorted = this->_container;
	std::sort(sorted.begin(), sorted.end()); // Function sorts stored number in crescent order
	int minSpan = sorted[1] - sorted[0];

	for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end() - 1; ++it) {
		int newMinSpan = *(it + 1) - *it;
		if (newMinSpan < minSpan)
			minSpan = newMinSpan;
	}
	return (minSpan);
}

int		Span::longestSpan() {
	if (this->_container.size() < 2) {
		throw InsufficientValuesException();
	}

	std::vector<int>::iterator minIt = std::min_element(this->_container.begin(), this->_container.end());
	std::vector<int>::iterator maxIt = std::max_element(this->_container.begin(), this->_container.end());
	return (*maxIt - *minIt);
}

const char*	Span::ContainerFullException::what() const throw() {
	return "Cannot store value. Container is full";
}

const char*	Span::InsufficientValuesException::what() const throw() {
	return "To find a span, the container should have at least 2 stored values.";
}

const char*	Span::InvalidValueException::what() const throw() {
	return "Invalid value. Please enter a positive value within integer bounds.";
}