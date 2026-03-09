#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <cctype>
#include <cerrno>


BitCoinExchange::BitCoinExchange() {}

BitCoinExchange::BitCoinExchange(const std::string &filename) {
    loadDatabase(filename);
}

BitCoinExchange::BitCoinExchange(const BitCoinExchange &other) {
    *this = other;
}

BitCoinExchange &BitCoinExchange::operator=(const BitCoinExchange &other) {
    if (this != &other) {
        this->_data = other._data;
    }
    return *this;
}

BitCoinExchange::~BitCoinExchange() {}

void BitCoinExchange::Exchange(std::ifstream &inputFile) {
    std::string line;
    std::getline(inputFile, line); // ignores first line

    while (std::getline(inputFile, line)) {
        std::string::size_type pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cerr << MGNT << "Error: bad input => " << line << RST << std::endl;
            continue;
        }

        std::string dateStr = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 1));
        double value;

        if (!isValidDate(dateStr)) {
            std::cerr << MGNT << "Error: bad input => " << dateStr << RST << std::endl;
            continue;
        }
        if (!isValidValue(valueStr, value)) { //isVaidValue already outputs error message depending on each case
            continue;
        }

        try {
            double rate = getExchangeRate(dateStr);
            std::cout << dateStr << " => " << value << " = " << (value * rate) << std::endl;
        } catch (const std::exception &e) {
            std::cerr << MGNT << "Error: " << e.what() << RST << std::endl;
        }
    }
}

void BitCoinExchange::loadDatabase(const std::string &filename) {
    std::ifstream dbFile(filename.c_str());
    if (!dbFile.is_open()) {
        throw std::runtime_error("could not open database file.");
    }

    std::string line;
    std::getline(dbFile, line); // ignores file first line

    while (std::getline(dbFile, line)) {
        std::string::size_type commaPos = line.find(',');
        if (commaPos == std::string::npos) continue;

        std::string date = trim(line.substr(0, commaPos));
        std::string rateStr = trim(line.substr(commaPos + 1));

        char *end = NULL;
        double rate = std::strtod(rateStr.c_str(), &end);

        if (isValidDate(date) && end != rateStr.c_str() && *end == '\0') {
            _data[date] = rate;
        }
    }
}

double BitCoinExchange::getExchangeRate(const std::string &date) const {
    if (_data.empty()) {
        throw std::runtime_error("database is empty");
    }

    std::map<std::string, double>::const_iterator it = _data.lower_bound(date);

    if (it != _data.end() && it->first == date) {
        return it->second;
    }
    if (it == _data.begin()) {
        throw std::runtime_error("no data for or before this date");
    }
    --it;
    return it->second;
}

std::string BitCoinExchange::trim(const std::string &s) {
    std::string::size_type start = s.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) return "";
    std::string::size_type end = s.find_last_not_of(" \t\n\r");
    return s.substr(start, end - start + 1);
}

bool BitCoinExchange::isLeapYear(int y) {
    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}

int BitCoinExchange::daysInMonth(int y, int m) {
    static const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && isLeapYear(y)) return 29;
    return days[m];
}

bool BitCoinExchange::isValidDate(const std::string &date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i]))) return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1) return false;
    if (day > daysInMonth(year, month)) return false;

    return true;
}

bool BitCoinExchange::isValidValue(const std::string &valueStr, double &outValue) {
    char *end = NULL;
    errno = 0;
    outValue = std::strtod(valueStr.c_str(), &end);

    if (errno != 0 || end == valueStr.c_str() || *end != '\0') {
        std::cerr << MGNT << "Error: invalid number format." << RST << std::endl;
        return false;
    }
    if (outValue < 0) {
        std::cerr << MGNT << "Error: not a positive number." << RST << std::endl;
        return false;
    }
    if (outValue > 1000) {
        std::cerr << MGNT << "Error: too large a number." << RST << std::endl;
        return false;
    }
    return true;
}