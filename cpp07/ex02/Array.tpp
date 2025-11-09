#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	this->_size = 0;
	this->_array = NULL;
}

template <typename T>
Array<T>::Array(const unsigned int &n) {
	this->_size = n;
	this->_array = new T[n];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = T();
}

template <typename T>
Array<T>::Array(const Array &copy)
{
	this->_size = copy._size;
	this->_array = new T[_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = copy._array[i];
}

template <typename T>
Array<T>::~Array() {
	std::cout << BLU << "~Destructor called" << RST << std::endl;
	delete[] this->_array;
}

// Assignment operator: copies the contents of another Array into this one, performing deep copy
template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (this != &other) {
		delete[] this->_array;
		this->_size = other._size;
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= this->_size)
		throw std::out_of_range("Forbidden memory access");
	return this->_array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return this->_size;
}

#endif