#include "Span.hpp"

// SUBJECT MAIN
// int main( void ) {
	
// 	Span sp = Span(5);
	
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
	
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
	
// 	return 0;
// }

int main(void) {
    srand(time(0));
    
    std::cout << YLW << "\n======== Testing Container with customized numbers ========" << RST << std::endl;
    
    int val = 0;
    while (1) {
        std::cout << "Hello! Please insert a positive value to be the size of your container:" << RST << std::endl;
        try {
            std::string input;
            std::getline(std::cin, input);
             // Check for empty input
        if (input.empty()) {
            throw Span::InvalidValueException();
        }
        
        // Check for non-numeric characters
        for (size_t i = 0; i < input.length(); ++i) {
            if (!isdigit(input[i])) {
                throw Span::InvalidValueException();
            }
        }
        
        // Convert to long to check overflow before converting to int
        long temp = atol(input.c_str());
        
        if (temp <= 0 || temp > std::numeric_limits<int>::max()) {
            throw Span::InvalidValueException();
        }
        
        val = static_cast<int>(temp);
        break;
        
    } catch (const Span::InvalidValueException &e) {
        std::cout << MGNT << "ERROR: " << RST << e.what() << std::endl;
        continue;
    } catch (const std::exception &e) {
        std::cout << MGNT << "ERROR: Invalid input" << RST << std::endl;
        continue;
    }
}

    Span bigCont(val);
    std::vector<int> numbers;
    
    // Generates 'val' random numbers
    for (int i = 0; i < val; ++i) {
        numbers.push_back(rand() % (val * 10));
    }
    
    // Adds a batch of numbers to the container
    bigCont.addMultipleNumbers(numbers.begin(), numbers.end());
    std::cout << GRN << "Success: " << RST << val << " numbers added to the container" << std::endl;
    
    try {
        std::cout << "Shortest Span: " << RST << bigCont.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << RST << bigCont.longestSpan() << std::endl;
    } catch (const Span::InsufficientValuesException &e) {
        std::cout << MGNT << "ERROR: " << RST << e.what() << std::endl;
    }
    
    std::cout << YLW << "\n======== Testing Small Container (subject test) ========" << RST << std::endl;
    
    Span smallCont(5);
    smallCont.addNumber(6);
    smallCont.addNumber(3);
    smallCont.addNumber(17);
    smallCont.addNumber(9);
    smallCont.addNumber(11);
    
    try {
        std::cout << "\nShortest Span: " << RST << smallCont.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << RST << smallCont.longestSpan() << std::endl;
    } catch (const Span::InsufficientValuesException &e) {
        std::cout << MGNT << "ERROR: " << RST << e.what() << std::endl;
    }

    std::cout << YLW << "\n======== Testing Full Container Exception ========" << RST << std::endl;
    
    Span fullCont(3);
    fullCont.addNumber(1);
    fullCont.addNumber(2);
    fullCont.addNumber(3);
    
    try {
        fullCont.addNumber(4);
    } catch (const Span::ContainerFullException &e) {
        std::cout << MGNT << "ERROR: " << RST << e.what() << std::endl;
    }
    
    std::cout << YLW << "\n======== Testing Insufficient Stored Values Exception ========" << RST << std::endl;
    
    Span tooSmallCont(5);
    tooSmallCont.addNumber(42);
    
    try {
        tooSmallCont.shortestSpan();
    } catch (const Span::InsufficientValuesException &e) {
        std::cout << MGNT << "ERROR: " << RST << e.what() << std::endl;
    }
    return 0;
}