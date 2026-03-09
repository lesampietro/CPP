#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <stdexcept>

# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define MGNT "\033[0;35m"
# define BLU "\033[34m"
# define CYN "\033[0;36m"
# define RST "\033[0m"

class BitCoinExchange {
    private:
        std::map<std::string, double> _data;

        // Private class methods
        void    loadDatabase(const std::string &filename);
        double  getExchangeRate(const std::string &date) const;

        // Static Helpers
        static bool isValidDate(const std::string &date);
        static bool isValidValue(const std::string &valueStr, double &outValue);
        static std::string trim(const std::string &s);
        static bool isLeapYear(int y);
        static int daysInMonth(int y, int m);

        // Private standar constructor
        BitCoinExchange(); 

    public:
        BitCoinExchange(const std::string &filename);
        BitCoinExchange(const BitCoinExchange &other);
        BitCoinExchange &operator=(const BitCoinExchange &other);
        ~BitCoinExchange();

        void Exchange(std::ifstream &inputFile);
};

#endif