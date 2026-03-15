#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <limits>
# include <ctime>
# include <string>
# include <vector>
# include <deque>
# include <algorithm>
# include <iterator>

# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define MGNT "\033[0;35m"
# define BLU "\033[34m"
# define CYN "\033[0;36m"
# define RST "\033[0m"

class PmergeMe {
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;

		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		void	fordJohnsonAlgorithm(std::vector<int>& sequence);
		void	fordJohnsonAlgorithm(std::deque<int>& sequence);
		double	convertTime(clock_t start, clock_t end);
		void	validateInput(int argc, char **argv);
		
		public:
		PmergeMe();
		~PmergeMe();
		
		void	mergeInsertSort(int argc, char **argv);
};

#endif