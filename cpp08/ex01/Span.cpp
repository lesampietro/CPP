#include "Span.hpp"

// by default, containers are created empty and do not need to be initialized. 
// it is a good practice to explicitly declare them on the initialization list.
Span::Span() : _n(0), _container() { 
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int n) : _n(n), _container() {
	std::cout << "Span parametrized constructor called" << std::endl;
}

Span::Span(const Span &copy) :  _n(copy._n), _container(copy._container) {
	std::cout << "Span copy constructor called" << std::endl;
}

Span	&Span::operator=(const Span &other) {
	std::cout << "Span assignment operator called" << std::endl;
	if (this != &other) {
		this->_n = other._n;
		this->_container = other._container;
	}
	return (*this);
}

Span::~Span() {
	std::cout << "Span default destructor called" << std::endl;
}

void	Span::addNumber(unsigned int number) {
    if (this->_container.size() >= this->_n) 
        std::cerr << "Container is full" << std::endl;
	else {
		_container.push_back(number);
		std::cout << "Adding " << number << " to the container" << std::endl;
	}
}		

int		Span::shortestSpan() {
	if(this->_container.size() <= 1) {
    	std::vector<int> sorted = this->_container;
    	std::sort(sorted.begin(), sorted.end());
    	int minSpan = sorted[1] - sorted[0];

		return(minSpan);
	}
	else
		return (0);
}

int		Span::longestSpan() {
	if(this->_container.size() <= 1) {

		std::vector<int>::iterator minIt = std::min_element(this->_container.begin(), this->_container.end());
		std::vector<int>::iterator maxIt = std::max_element(this->_container.begin(), this->_container.end());
		
		return (*maxIt - *minIt);
	}
	else
		return (0);
}