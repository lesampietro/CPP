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

void PmergeMe::fordJohnsonAlgorithm(std::vector<int>& sequence) {
    if (sequence.size() <= 1) {
        return; // Base case: a sequence of 0 or 1 elements is already sorted
    }
    // Check if the number of elements is odd and if so, store the last element as stray,
    // then remove it from the array to make it even for pairing.
    int stray = -1;
    if (sequence.size() % 2) {
        stray = sequence.back();
        sequence.pop_back();
    }
    
    // std::vector<std::pair<int, int>> is a dynamic array of integer pairs.
    // Using std::pair because it is a simple aggregator of pair of values, along with tools to access them and compare them, which is useful for the next steps of the algorithm.
    // The first integer is the larger one and the second is the smaller one. This is done to ensure that the main chain will be built with the larger elements, which is a requirement of the Ford-Johnson algorithm.
    typedef std::vector<std::pair<int, int> > vectorOfPairs;
    // Could also be created as std::vector<intVector> vectorOfPairs.
    
    std::cout << "Sequence size: " << sequence.size() << std::endl; // Debugging line to show the size of the sequence being processed
    vectorOfPairs pairs;
    for (size_t i = 0; i < sequence.size(); i += 2) {
        std::pair<int,int> intPair(sequence[i], sequence[i+1]);
        if (intPair.first < intPair.second) {
            std::swap(intPair.first, intPair.second);
        }
        std::cout << "Pair: (" << intPair.first << ", " << intPair.second << ")" << std::endl; // Debugging line to show the pairs being created
        pairs.push_back(intPair);
    }
    std::cout << "Total pairs created: " << pairs.size() << std::endl;
    // Create the main chain and pending chain from the pairs. The main chain will contain the larger elements of each pair, while the pending chain will contain the smaller elements.
    typedef std::vector<int> intVector; // type alias for better readability
    intVector mainChain, pendingChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pendingChain.push_back(pairs[i].second);
    }
    static int recursion_depth = 1;
    std::cout << GRN << "----------RECURSION: 0" << recursion_depth++ << std::endl << RST <<std::endl;
    fordJohnsonAlgorithm(mainChain);
    
    std::cout << "Elements in initial mainChain:" << std::endl;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        std::cout << mainChain[i] << " "; // Debugging line to show the elements in the main chain after insertion
    }
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
    
    std::cout << YLW << "\n----------RECURSION (GOING BACK): 0" << --recursion_depth << RST;
    std::cout << "\n----------CHECKING PENDING CHAIN----------" << std::endl;
    std::cout << "Pending chain size: " << pendingChain.size() << std::endl; // Debugging line to show the size of the pending chain being processed
    std::cout << "Pending chain elements: " << std::endl;
    for (size_t i = 0; i < pendingChain.size(); ++i) {
        std::cout << pendingChain[i] << " "; // Debugging line to show the elements in the pending chain being inserted
    }
    std::cout << MGNT << "\nStray element: " << RST << stray << std::endl; 
    std::cout << "\n----------INSERTION USING JACOBSTHAL SEQUENCE" << std::endl;
    // Insertion using Jacobsthal sequence
    for (size_t i = 1; i < jacobsthal.size(); ++i) { // piruetas mentais
        int end = jacobsthal[i];
        int start = jacobsthal[i-1];
        for (int j = end - 1; j >= start; --j) {
            if (static_cast<size_t>(j) < pendingChain.size()) {
                intVector::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pendingChain[j]);
                mainChain.insert(it, pendingChain[j]);
                std::cout << "Inserting " << pendingChain[j] << " at position " << (it - mainChain.begin()) << std::endl;
            }
        }
    }
    if (stray != -1) {
        intVector::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), stray);
        mainChain.insert(it, stray);
        std::cout << "Inserting " << stray << " at position " << (it - mainChain.begin()) << std::endl;
    }

    sequence = mainChain;
    std::cout << "\n----------CHECKING MAIN CHAIN----------" << std::endl;
    std::cout << "Main chain size: " << mainChain.size() << std::endl; // Debugging line to show the size of the main chain being processed
    for (size_t i = 0; i < mainChain.size(); ++i) {
        std::cout << "Main chain element " << i << ": " << mainChain[i] << std::endl; // Debugging line to show the elements in the main chain after insertion
    }
}

void PmergeMe::fordJohnsonAlgorithm(std::deque<int>& sequence) {
    if (sequence.size() <= 1) {
        return; // Base case: a sequence of 0 or 1 elements is already sorted
    }

    int stray = -1;
    if (sequence.size() % 2 != 0) {
        stray = sequence.back();
        sequence.pop_back();
    }
        
    typedef std::deque<std::pair<int, int> > dequeOfPairs;
    dequeOfPairs pairs;
    for (size_t i = 0; i + 1 < sequence.size(); i += 2) {
        std::pair<int,int> intPair(sequence[i], sequence[i+1]);
        if (intPair.first < intPair.second) {
            std::swap(intPair.first, intPair.second);
        }
        pairs.push_back(intPair);
    }

    typedef std::deque<int> intDeque;
    intDeque mainChain, pendingChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pendingChain.push_back(pairs[i].second);
    }

    fordJohnsonAlgorithm(mainChain);

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
                intDeque::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pendingChain[j]);
                mainChain.insert(it, pendingChain[j]);
            }
        }
    }

    if (stray != -1) {
        intDeque::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), stray);
        mainChain.insert(it, stray);
    }

    sequence = mainChain;
}

void PmergeMe::mergeInsertSort(int argc, char **argv) {
    // Input validation and initialization
	for (int i = 1; i < argc; ++i) {
		std::string arg = argv[i];
        // Validates that the argument has only digits and therefore is positive
		for (size_t j = 0; j < arg.size(); ++j) {
			if (!std::isdigit(arg[j])) {
				std::cout << MGNT << "Error: Invalid input." << RST << std::endl;
                std::cout << "There are invalid characters or negative numbers." << std::endl;
				return;
			}
		}
		long num = std::atol(argv[i]);
        // Validates that the argument fits within the maximum value of an int
		if (num > std::numeric_limits<int>::max())
		{
			std::cout << MGNT << "Error: Invalid input." << RST << std::endl;
            std::cout << "Valid integers go up to " << std::numeric_limits<int>::max() << "." << std::endl;
			return;
		}
		_vec.push_back(static_cast<int>(num));
		_deq.push_back(static_cast<int>(num));
	}

    // Validates that there are no duplicated values in the input
	std::vector<int> sorted_vec = _vec;
	std::sort(sorted_vec.begin(), sorted_vec.end()); // Using std::sort to sort the vector for easier duplicate detection
	for (size_t i = 0; i < sorted_vec.size() - 1; ++i) {
		if (sorted_vec[i] == sorted_vec[i+1]) {
			std::cout << MGNT << "Error: Duplicated values." << RST << std::endl;
			return;
		}
	}

    // Prints the original sequence
	std::cout << YLW << "Before: " << RST;
	for (size_t i = 0; i < _vec.size(); ++i) {
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;

    // Marks the start time of the operation using vector and applies the Ford-Johnson algorithm to sort the vector, then marks the end time and calculates the elapsed time in microseconds
	clock_t start_vec = clock();
	fordJohnsonAlgorithm(_vec);
	clock_t end_vec = clock();
	double time_vec = convertTime(start_vec, end_vec);

    // Prints the sorted sequence and the time taken to sort it using vector
	std::cout << GRN << "After: " << RST;
	for (size_t i = 0; i < _vec.size(); ++i) {
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;

    // Same process as above but using deque instead of vector
	clock_t start_deq = clock();
	fordJohnsonAlgorithm(_deq);
	clock_t end_deq = clock();
	double time_deq = convertTime(start_deq, end_deq);

    std::cout << "------------------------------" << std::endl;
    std::cout << "Time to process a range of " << CYN << _vec.size() << RST << " elements with ";
    std::cout << CYN << "std::vector" << RST << ": " << std::fixed << std::setprecision(6) << time_vec << " s" << std::endl;
    std::cout << "Time to process a range of " << CYN << _deq.size() << RST << " elements with ";
    std::cout << CYN << "std::deque" << RST << ": " << std::fixed << std::setprecision(6) << time_deq << " s" << std::endl;
}

double PmergeMe::convertTime(clock_t start, clock_t end) {
    double elapsed_clocks = static_cast<double>(end - start);
    return elapsed_clocks / CLOCKS_PER_SEC;
}