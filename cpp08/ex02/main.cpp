#include "MutantStack.hpp"
#include <list>

//SUBJECT MAIN
// int main() {
// 	MutantStack<int> mstack;

// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;

// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;

// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);

// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;

// 	while (it != ite) {
// 		std::cout << *it << std::endl;
// 		++it;
// 	}

// 	std::stack<int> s(mstack);

// 	return 0;
// }

// IMPROVED MAIN
int main() {
    std::cout << YLW << "\n======== Basic Stack Operations ========" << RST << std::endl;
    {
		std::cout << "--- Create a mutantStack and operate its elements ---" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "Top after push(5) and push(17): " << CYN << mstack.top() << RST << std::endl;
        
        mstack.pop();
        std::cout << "Size after pop(): " << CYN << mstack.size() << RST << std::endl;
        
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        std::cout << "Size after multiple push: " << CYN << mstack.size() << RST << std::endl;
		
		std::cout << "\n--- Iterator Tests ---" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		std::cout << "Iterator increment test:" << std::endl;
		++it;
		std::cout << "After ++it: " << CYN << *it << RST << std::endl;
		--it;
		std::cout << "After --it: " << CYN << *it << RST << std::endl;
		
		std::cout << "Traverse entire stack with iterator:" << std::endl;
		while (it != ite) {
			std::cout << CYN << *it << RST << std::endl;
			++it;
		}

		std::cout << "\n--- Const Iterator Tests ---" << std::endl;
		MutantStack<int>::const_iterator cit = mstack.begin();
		MutantStack<int>::const_iterator cite = mstack.end();
		
		std::cout << "Const Iterator increment test:" << std::endl;
		++cit;
		std::cout << "After ++cit: " << CYN << *cit << RST << std::endl;
		--cit;
		std::cout << "After --cit: " << CYN << *cit << RST << std::endl;
		

		std::cout << "Const iterator traversal:" << std::endl;
		while (cit != cite) {
			std::cout << CYN << *cit << RST << std::endl;
			++cit;
		}
    }

    std::cout << YLW << "\n======== Conversion to std::stack ========" << RST << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        mstack.pop();
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        
        std::stack<int> s(mstack);
        std::cout << "MutantStack converted to std::stack:" << std::endl;
        std::cout << "Top: " << CYN << s.top() << RST << std::endl;
        std::cout << "Size: " << CYN << s.size() << RST << std::endl;
        std::cout << "\nMutantStack: " << mstack << std::endl;
    }

    std::cout << YLW << "\n======== Test using String Type ========" << RST << std::endl;
    {
        MutantStack<std::string> strstack;
        strstack.push("Hello");
        strstack.push("World");
        strstack.push("!");
        
        MutantStack<std::string>::iterator it = strstack.begin();
        MutantStack<std::string>::iterator ite = strstack.end();
        std::cout << "Iterate through strings:" << std::endl;
        while (it != ite) {
			std::cout << CYN << *it << RST << std::endl;
            ++it;
        }
		
		std::cout << "\nString stack: " << strstack << std::endl;
    }

    std::cout << YLW << "\n======== Test using Double Type ========" << RST << std::endl;
    {
        MutantStack<double> dstack;
        dstack.push(3.14);
        dstack.push(2.71);
        dstack.push(1.41);
        
        std::cout << "Double stack: " << dstack << std::endl;
    }

    std::cout << YLW << "\n======== Test replacing mutantStack with std::list ========" << RST << std::endl;
	{
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		lst.pop_back();
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		
		std::cout << "Top: " << CYN << lst.back() << RST << std::endl;
        std::cout << "Size: " << CYN << lst.size() << RST << std::endl;
		std::cout << "\nIterate through list elements:" << std::endl;
		for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
			std::cout << CYN << *it << RST << std::endl;
		}
		std::cout << std::endl;
	}

    return 0;
}