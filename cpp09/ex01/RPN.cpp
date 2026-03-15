#include "RPN.hpp"
#include <sstream>

ReversePolishNotation::ReversePolishNotation() {}

ReversePolishNotation::ReversePolishNotation(const std::string &expression) {
    calculateRPN(expression);
}

ReversePolishNotation::ReversePolishNotation(const ReversePolishNotation &other) {
    *this = other;
}

ReversePolishNotation &ReversePolishNotation::operator=(const ReversePolishNotation &other) {
    if (this != &other) {
        this->_numbers = other._numbers;
    }
    return *this;
}

ReversePolishNotation::~ReversePolishNotation() {}


bool ReversePolishNotation::isValidNumber(const std::string &str) const {
    if (str.empty()) {
        return false;
    }
    for (size_t i = 0; i < str.size(); ++i) {
        if (!std::isdigit(str[i]))
            return false;
    }
    if (str.size() > 1 && str[0] == '0') {
        return false; // Leading zeros are not allowed
    }
    if (str.size() > 1 && str[0] == '-' && std::isdigit(str[1])) {
        return false; // Negative numbers are not allowed
    }
    if (str.size() > 1 && str[0] == '+' && std::isdigit(str[1])) {
        return false; // Positive sign is not allowed
    }
    const int number = convertNumber(str);
    if (number < 0 || number > 9) {
        std::cerr << MGNT << "Error: Invalid number: '" << str << RST;
        std::cerr <<  "'. Only single-digit numbers are allowed." << std::endl;
        return false;
    }
    return true;
}

int ReversePolishNotation::convertNumber(const std::string &str) const {
    int number = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        number = number * 10 + (str[i] - '0');
    }
    return number;
}

bool ReversePolishNotation::isValidOperator(const std::string &str) const {
    if (str.size() != 1) {
        return false;
    }
    char op = str[0];
    return op == '+' || op == '-' || op == '*' || op == '/';
}

int ReversePolishNotation::performOperation(int operand1, int operand2, const std::string &op) const {
    if (op == "+") {
        return operand1 + operand2;
    } else if (op == "-") {
        return operand1 - operand2;
    } else if (op == "*") {
        return operand1 * operand2;
    } else if (op == "/") {
        return operand1 / operand2;
    }
    throw RPNException();
}

// ReversePolishNotation::RPNException::~RPNException() throw() {}

const char* ReversePolishNotation::RPNException::what() const throw() {
    return "Error";
}

int ReversePolishNotation::calculateRPN(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isValidNumber(token)) {
            _numbers.push(convertNumber(token));
        } else if (isValidOperator(token)) {
            if (_numbers.size() < 2) {
                throw RPNException();
            }
            int operand2 = _numbers.top(); _numbers.pop();
            int operand1 = _numbers.top(); _numbers.pop();
            int result = performOperation(operand1, operand2, token);
            _numbers.push(result);
        } else {
            throw RPNException();
        }
    }

    if (_numbers.size() != 1) {
        throw RPNException();
    }
    return _numbers.top();
}