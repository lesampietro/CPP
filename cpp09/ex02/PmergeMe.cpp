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

void PmergeMe::fordJohnsonSort(std::vector<int>& arr) {
    if (arr.size() < 2) return;

    typedef std::vector<int> IntVector;
    typedef std::vector<IntVector> VectorOfPairs;

    VectorOfPairs pairs;
    int stray = -1;
    if (arr.size() % 2 != 0) {
        stray = arr.back();
        arr.pop_back();
    }

    for (size_t i = 0; i < arr.size(); i += 2) {
        IntVector pair;
        pair.push_back(arr[i]);
        pair.push_back(arr[i+1]);
        if (pair[0] < pair[1]) {
            std::swap(pair[0], pair[1]);
        }
        pairs.push_back(pair);
    }

    IntVector mainChain, pendingChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i][0]);
        pendingChain.push_back(pairs[i][1]);
    }

    fordJohnsonSort(mainChain);

    // Jacobsthal sequence generation
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    int last = 1, before_last = 0;
    while (static_cast<size_t>(last) < pendingChain.size()) {
        int next = last + 2 * before_last;
        before_last = last;
        last = next;
        jacobsthal.push_back(last);
    }

    // Insertion using Jacobsthal sequence
    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        int end = jacobsthal[i];
        int start = jacobsthal[i-1];
        for (int j = end - 1; j >= start; --j) {
            if (static_cast<size_t>(j) < pendingChain.size()) {
                IntVector::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pendingChain[j]);
                mainChain.insert(it, pendingChain[j]);
            }
        }
    }

    if (stray != -1) {
        IntVector::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), stray);
        mainChain.insert(it, stray);
    }

    arr = mainChain;
}

void PmergeMe::fordJohnsonSort(std::deque<int>& arr) {
    if (arr.size() < 2) return;

    typedef std::deque<int> IntDeque;
    typedef std::deque<IntDeque> DequeOfPairs;

    DequeOfPairs pairs;
    int stray = -1;
    if (arr.size() % 2 != 0) {
        stray = arr.back();
        arr.pop_back();
    }

    for (size_t i = 0; i < arr.size(); i += 2) {
        IntDeque pair;
        pair.push_back(arr[i]);
        pair.push_back(arr[i+1]);
        if (pair[0] < pair[1]) {
            std::swap(pair[0], pair[1]);
        }
        pairs.push_back(pair);
    }

    IntDeque mainChain, pendingChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i][0]);
        pendingChain.push_back(pairs[i][1]);
    }

    fordJohnsonSort(mainChain);

    // Jacobsthal sequence generation
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    int last = 1, before_last = 0;
    while (static_cast<size_t>(last) < pendingChain.size()) {
        int next = last + 2 * before_last;
        before_last = last;
        last = next;
        jacobsthal.push_back(last);
    }

    // Insertion using Jacobsthal sequence
    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        int end = jacobsthal[i];
        int start = jacobsthal[i-1];
        for (int j = end - 1; j >= start; --j) {
            if (static_cast<size_t>(j) < pendingChain.size()) {
                IntDeque::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pendingChain[j]);
                mainChain.insert(it, pendingChain[j]);
            }
        }
    }

    if (stray != -1) {
        IntDeque::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), stray);
        mainChain.insert(it, stray);
    }

    arr = mainChain;
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
		if (num > 2147483647 )
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
	fordJohnsonSort(_vec);
	clock_t end_vec = clock();
	double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After: ";
	for (size_t i = 0; i < _vec.size(); ++i) {
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;

	clock_t start_deq = clock();
	fordJohnsonSort(_deq);
	clock_t end_deq = clock();
	double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << time_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << time_deq << " us" << std::endl;
}
