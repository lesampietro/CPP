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
        std::stack<int> _operands;
        int _result;

        ReversePolishNotation();
        ReversePolishNotation(const ReversePolishNotation &other);
        ReversePolishNotation &operator=(const ReversePolishNotation &other);

        bool isValidNumber(const char num) const;
        bool isValidOperator(const char op) const;
        int  convertNumber(const std::string &str) const;
        int  performOperation(int operand1, int operand2, const char op) const;
        int  calculateRPN(const std::string &expression);
        
        public:
        ReversePolishNotation(const std::string &expression);
        ~ReversePolishNotation();
        
        int  getResult() const;

};


#endif