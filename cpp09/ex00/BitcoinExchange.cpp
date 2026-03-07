#include "BitcoinExchange.hpp"

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

void BitCoinExchange::addData(const std::string &date, double value) {
    _data[date] = value;
}

bool BitCoinExchange::isValidDate(const std::string &date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    for (std::size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7) {
            continue;
        }
        if (!std::isdigit(date[i])) {
        // if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
        }
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > daysInMonth(year, month))
        return false;
    
    return true;
}

bool BitCoinExchange::isValideValue(const std::string &value) const {
    if (value.empty()) {
        return false;
    }
    for (std::size_t i = 0; i < value.size(); ++i) {
        if (!std::isdigit(value[i]) && value[i] != '.' && value[i] != '-') {
            return false;
        }
    }
    try {
        float val = stringToFloat(value);
        if (val < 0 || val > 1000) {
            return false;
        }
    } catch (const std::exception &e) {
        return false;
    }
    return true;   
}

float BitCoinExchange::stringToFloat(const std::string &str) const {
    char *endptr;
    errno = 0; // Reset errno before conversion
    float value = std::strtof(str.c_str(), &endptr);
    
    if (errno != 0 || endptr == str.c_str() || *endptr != '\0') {
        throw std::invalid_argument("Invalid float value: " + str);
    }
    return value;
}

void BitCoinExchange::loadDatabase(const std::string &filename) {
    std::ifstream file(filename.c_str());

}

void BitCoinExchange::printData() const {
    for (std::map<std::string, double>::const_iterator it = _data.begin(); it != _data.end(); ++it) {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}
