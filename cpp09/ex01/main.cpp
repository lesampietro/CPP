#include "RPN.hpp"

int main(int argc, char **argv) {
    {
        if (argc != 2) {
            std::cerr << MGNT << "Error: Invalid number of arguments." << RST << std::endl;
            std::cerr << "Usage: " << argv[0] << " <your reverse polish notation>" << std::endl;
            return 1;
        }
    }

    ReversePolishNotation rpn = ReversePolishNotation(argv[1]);

    return 0;
}
