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
        this->_operands = other._operands;
    }
    return *this;
}

ReversePolishNotation::~ReversePolishNotation() {}

bool ReversePolishNotation::isValidNumber(const char num) const {
    return (num >= '0' && num <= '9');
}

bool ReversePolishNotation::isValidOperator(const char op) const {
    return op == '+' || op == '-' || op == '*' || op == '/';
}

int ReversePolishNotation::performOperation(int operandL, int operandR, char op) const {
    switch (op) {
        case '+': 
            return operandL + operandR;
        case '-': 
            return operandL - operandR;
        case '*': 
            return operandL * operandR;
        case '/':
            if (operandR == 0) {
                throw std::invalid_argument("Division by zero is not allowed.");
            }
            return operandL / operandR;
        default:
            throw std::invalid_argument("Invalid operator");
    }
}

int ReversePolishNotation::calculateRPN(const std::string& expression) {
    // Making sure the stack is clear before processing the expression
    while (!_operands.empty()) {
        _operands.pop();
    }

    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        if (token.length() == 1 && isValidNumber(token[0])) {
            _operands.push(token[0] - '0');
        } else if (token.length() == 1 && isValidOperator(token[0])) {
            if (_operands.size() < 2) {
                throw std::invalid_argument("Invalid expression: not enough operands.");
            }
            int operandR = _operands.top(); 
            _operands.pop();
            int operandL = _operands.top();
            _operands.pop();
            _operands.push(performOperation(operandL, operandR, token[0]));
        } else {
            throw std::invalid_argument("Invalid token: " + token);
        }
    }
    this->_result = _operands.top(); // Update result after each token is processed
    return this->_result;

    if (_operands.size() != 1) {
        throw std::invalid_argument("Invalid expression: too many operands.");
    }
    return _operands.top();
}

int ReversePolishNotation::getResult() const {
    return this->_result;
}