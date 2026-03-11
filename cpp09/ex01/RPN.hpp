#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include <stdexcept>

# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define MGNT "\033[0;35m"
# define BLU "\033[34m"
# define CYN "\033[0;36m"
# define RST "\033[0m"

class ReversePolishNotation {
    private:
        std::vector<int, int> _factors;
        ReversePolishNotation(); 

        void evaluate();
        bool isOperator(const std::string& token);
        void performOperation(const std::string& op);

    public:
        ReversePolishNotation(const std::string &expression);
        ReversePolishNotation(const ReversePolishNotation &other);
        ReversePolishNotation &operator=(const ReversePolishNotation &other);
        ~ReversePolishNotation();

        bool isValidNumber(const std::string &str) const;
        bool isValidOperator(const std::string &str) const;
        void calculateRPN(const std::string &expression);

        class RPNException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif