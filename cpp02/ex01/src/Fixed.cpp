
#include "../includes/Fixed.hpp"

Fixed::Fixed(): _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value * (1 << _fractionalBits); //Move 8 bits to the left (multiply by 2^8)
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << _fractionalBits)); //Move 8 bits to the left and round it to the nearest integer with roundf()
}

Fixed::Fixed(const Fixed &copy) : _fixedPointValue(copy._fixedPointValue) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) { // Check for self-assignment
		this->_fixedPointValue = other._fixedPointValue;
	}
	return *this;
}


Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const {
	return _fixedPointValue >> _fractionalBits;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}