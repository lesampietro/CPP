#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    {
        if (argc != 2) {
            std::cerr << MGNT << "Error: Invalid number of arguments." << RST << std::endl;
            std::cerr << "Usage: " << argv[0] << " <data_file>" << std::endl;
            return 1;
        }
    }

    std::ifstream dataFile(argv[1]);
    if (!dataFile.is_open()) {
        std::cerr << MGNT << "Error: Could not open file " << argv[1] << RST << std::endl;
        return 1;
    }
    else if (dataFile.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << MGNT << "Error: File " << argv[1] << " is empty." << RST << std::endl;
        return 1;
    }

    
    BitCoinExchange btc = BitCoinExchange("data.csv");
    btc.Exchange(dataFile);

    return 0;
}

//dataFile.peek() - Peeks at the next character in the file without extracting it. If the file is empty, it returns the EOF (end-of-file) marker.