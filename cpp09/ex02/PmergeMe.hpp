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

		void mergeInsertSort(std::vector<int>& arr);
		void merge(std::vector<int>& arr, std::vector<int>& left, std::vector<int>& right);
		void mergeInsertSort(std::deque<int>& arr);
		void merge(std::deque<int>& arr, std::deque<int>& left, std::deque<int>& right);

	public:
		PmergeMe();
		~PmergeMe();

		void sort(int argc, char **argv);
};

#endif