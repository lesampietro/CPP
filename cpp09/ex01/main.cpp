#include "RPN.hpp"

int main(int argc, char **argv) {
    {
        if (argc < 2) {
            std::cerr << MGNT << "Error: Invalid number of arguments." << RST << std::endl;
            std::cerr << "Usage: " << argv[0] << " <user expression>" << std::endl;
            return 1;
        }
    }

    ReversePolishNotation rpn = ReversePolishNotation(argv[1]);
    std::cout << GRN << "Result: " << rpn.calculateRPN(argv[1]) << RST << std::endl;

    return 0;
}
