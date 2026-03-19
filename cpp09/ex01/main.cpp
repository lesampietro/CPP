#include "RPN.hpp"

int main(int argc, char **argv) {
    {
        if (argc != 2) {
            std::cerr << MGNT << "Error: " << RST;
            std::cerr << "Invalid number of arguments.\nUsage: ./RPN \"your expression\"" << std::endl;
            return 1;
        }
    }
    
    try {
        ReversePolishNotation rpn(argv[1]);
        std::cout << GRN << "Result: " << RST << rpn.getResult() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << MGNT << "Error: " << RST << e.what() << std::endl;
    }
    return 0;
}
