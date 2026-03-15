#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <stack>
# include <stdexcept>

# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define MGNT "\033[0;35m"
# define BLU "\033[34m"
# define CYN "\033[0;36m"
# define RST "\033[0m"

class ReversePolishNotation {
    private:
        std::stack<int> _numbers;

        bool isValidNumber(const std::string &str) const;
        bool isValidOperator(const std::string &str) const;
        int convertNumber(const std::string &str) const;
        int performOperation(int operand1, int operand2, const std::string &op) const;
        int calculateRPN(const std::string &expression);

    public:
        ReversePolishNotation();
        ReversePolishNotation(const std::string &expression);
        ReversePolishNotation(const ReversePolishNotation &other);
        ReversePolishNotation &operator=(const ReversePolishNotation &other);
        ~ReversePolishNotation();

        // int     calculateRPN(const std::string &expression);

        class RPNException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};


#endif