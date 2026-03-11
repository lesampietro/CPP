#ifndef PMERGEME_HPP
# define PMERGEME_HPP

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

class PMergeMe {
    private:
        std::vector<int, int> _factors;
        PMergeMe(); 

        void evaluate();
        bool isOperator(const std::string& token);
        void performOperation(const std::string& op);

    public:
        PMergeMe(const std::string &expression);
        PMergeMe(const PMergeMe &other);
        PMergeMe &operator=(const PMergeMe &other);
        ~PMergeMe();

        bool isValidNumber(const std::string &str) const;
        bool isValidOperator(const std::string &str) const;
        void calculateRPN(const std::string &expression);

        class PmergeMeException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif