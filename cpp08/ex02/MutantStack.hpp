#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define MGNT "\033[0;35m"
# define BLU "\033[34m"
# define CYN "\033[0;36m"
# define RST "\033[0m"

template<typename T>
class	MutantStack : public std::stack<T> {
	public:
		MutantStack() {}
		MutantStack(const MutantStack &other) {*this = other;}
		~MutantStack() {}

		MutantStack &operator=(const MutantStack &other) {
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this; }

		// iterator - por que aqui construimos a variavel com container_type::iterator?
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin() {
			return this->c.begin();}
		iterator end() {
			return this->c.end();}
		
		const_iterator begin() const {
			return this->c.begin();}
		const_iterator end() const {
			return this->c.end();}
};

//insertion operator
template <typename T> //porque essa sintaxe?
std::ostream &operator<<(std::ostream &os, const MutantStack<T> &other) {
	//pq aqui eh sem typedef?
	typename MutantStack<T>::const_iterator itinit = other.begin();
	typename MutantStack<T>::const_iterator itend = other.end();

	os << "Mutant Stack: {";
	while (itinit != itend) {
		os << *itinit;
		itinit++;
		if (itinit != itend)
			os << ", ";
	}
	os << " }";
	return os;
}

#endif
