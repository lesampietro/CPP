#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

void PmergeMe::merge(std::vector<int>& arr, std::vector<int>& left, std::vector<int>& right) {
	arr.clear();
	std::vector<int>::iterator left_it = left.begin();
	std::vector<int>::iterator right_it = right.begin();

	while (left_it != left.end() && right_it != right.end()) {
		if (*left_it < *right_it) {
			arr.push_back(*left_it);
			left_it++;
		} else {
			arr.push_back(*right_it);
			right_it++;
		}
	}
	arr.insert(arr.end(), left_it, left.end());
	arr.insert(arr.end(), right_it, right.end());
}

void PmergeMe::mergeInsertSort(std::vector<int>& arr) {
	if (arr.size() <= 1)
		return;

	int mid = arr.size() / 2;
	std::vector<int> left(arr.begin(), arr.begin() + mid);
	std::vector<int> right(arr.begin() + mid, arr.end());

	mergeInsertSort(left);
	mergeInsertSort(right);
	merge(arr, left, right);
}

void PmergeMe::merge(std::deque<int>& arr, std::deque<int>& left, std::deque<int>& right) {
	arr.clear();
	std::deque<int>::iterator left_it = left.begin();
	std::deque<int>::iterator right_it = right.begin();

	while (left_it != left.end() && right_it != right.end()) {
		if (*left_it < *right_it) {
			arr.push_back(*left_it);
			left_it++;
		} else {
			arr.push_back(*right_it);
			right_it++;
		}
	}
	arr.insert(arr.end(), left_it, left.end());
	arr.insert(arr.end(), right_it, right.end());
}

void PmergeMe::mergeInsertSort(std::deque<int>& arr) {
	if (arr.size() <= 1)
		return;

	int mid = arr.size() / 2;
	std::deque<int> left;
	std::deque<int> right;
    std::copy(arr.begin(), arr.begin() + mid, std::back_inserter(left));
    std::copy(arr.begin() + mid, arr.end(), std::back_inserter(right));


	mergeInsertSort(left);
	mergeInsertSort(right);
	merge(arr, left, right);
}

void PmergeMe::sort(int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		std::string arg = argv[i];
		for (size_t j = 0; j < arg.length(); ++j) {
			if (!std::isdigit(arg[j])) {
				std::cout << "Error: Invalid input" << std::endl;
				return;
			}
		}
		long num = std::atol(argv[i]);
		if (num > 2147483647)
		{
			std::cout << "Error: Invalid input" << std::endl;
			return;
		}
		_vec.push_back(static_cast<int>(num));
		_deq.push_back(static_cast<int>(num));
	}

	std::vector<int> sorted_vec = _vec;
	std::sort(sorted_vec.begin(), sorted_vec.end());
	for (size_t i = 0; i < sorted_vec.size() - 1; ++i) {
		if (sorted_vec[i] == sorted_vec[i+1]) {
			std::cout << "Error: Duplicate numbers" << std::endl;
			return;
		}
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); ++i) {
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;

	clock_t start_vec = clock();
	mergeInsertSort(_vec);
	clock_t end_vec = clock();
	double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After: ";
	for (size_t i = 0; i < _vec.size(); ++i) {
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;

	clock_t start_deq = clock();
	mergeInsertSort(_deq);
	clock_t end_deq = clock();
	double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << time_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << time_deq << " us" << std::endl;
}
