#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <cerrno>

# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define MGNT "\033[0;35m"
# define BLU "\033[34m"
# define CYN "\033[0;36m"
# define RST "\033[0m"

class BitCoinExchange {
    private: 
        std::map<std::string, double> _data;        
        
        bool    isValidDate(const std::string &date) const;
        bool    isValidValue(const std::string &value) const;
        double  getExchangeRate(const std::string &date) const;
        float   stringToFloat(const std::string &str) const;
        void    loadDatabase(const std::string &filename);
        
        BitCoinExchange();

        public:
        BitCoinExchange(const std::string &filename);
        BitCoinExchange(const BitCoinExchange &other);
        BitCoinExchange &operator=(const BitCoinExchange &other);
        ~BitCoinExchange();

        void addData(const std::string &date, double value);
        void printData() const;

        void Exchange(std::ifstream &inputFile);
};

#endif