#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <sys/time.h>
# include <algorithm>
# include <iterator>
# include <sstream>
# include <stdexcept>

class PmergeMe {
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;

		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		void fordJohnsonSort(std::vector<int>& arr);
		void fordJohnsonSort(std::deque<int>& arr);

	public:
		PmergeMe();
		~PmergeMe();

		void sort(int argc, char **argv);
};

#endif