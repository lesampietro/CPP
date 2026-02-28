#include "Span.hpp"

// SUBJECT MAIN
// int main( void ) {
	
// 	Span sp = Span(5);
	
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
	
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
	
// 	return 0;
// }

int main(void) {
    srand(time(0));
    
    std::cout << BLU << "=== TESTE 1: Container com 10000 números ===" << RST << std::endl;
    
    Span sp(10000);
    std::vector<int> numbers;
    
    // Gera 10000 números aleatórios
    for (int i = 0; i < 10000; ++i) {
        numbers.push_back(rand() % 100000);
    }
    
    // Adiciona todos de uma vez usando addMultipleNumbers
    sp.addMultipleNumbers(numbers.begin(), numbers.end());
    std::cout << GRN << "✓ 10000 números adicionados com sucesso!" << RST << std::endl;
    
    try {
        std::cout << YLW << "Shortest Span: " << RST << sp.shortestSpan() << std::endl;
        std::cout << YLW << "Longest Span: " << RST << sp.longestSpan() << std::endl;
    } catch (const Span::InsufficientValuesException &e) {
        std::cout << MGNT << "ERROR: " << RST << e.what() << std::endl;
    }
    
    std::cout << std::endl << BLU << "=== TESTE 2: Container pequeno (SUBJECT) ===" << RST << std::endl;
    
    Span sp2(5);
    sp2.addNumber(6);
    sp2.addNumber(3);
    sp2.addNumber(17);
    sp2.addNumber(9);
    sp2.addNumber(11);
    
    try {
        std::cout << YLW << "Shortest Span: " << RST << sp2.shortestSpan() << std::endl;
        std::cout << YLW << "Longest Span: " << RST << sp2.longestSpan() << std::endl;
    } catch (const Span::InsufficientValuesException &e) {
        std::cout << MGNT << "ERROR: " << RST << e.what() << std::endl;
    }
    
    std::cout << std::endl << BLU << "=== TESTE 3: Container cheio (exceção) ===" << RST << std::endl;
    
    Span sp3(3);
    sp3.addNumber(1);
    sp3.addNumber(2);
    sp3.addNumber(3);
    
    try {
        sp3.addNumber(4);
    } catch (const Span::ContainerFullException &e) {
        std::cout << MGNT << "ERROR: " << RST << e.what() << std::endl;
    }
    
    std::cout << std::endl << BLU << "=== TESTE 4: Valores insuficientes ===" << RST << std::endl;
    
    Span sp4(5);
    sp4.addNumber(42);
    
    try {
        sp4.shortestSpan();
    } catch (const Span::InsufficientValuesException &e) {
        std::cout << MGNT << "ERROR: " << RST << e.what() << std::endl;
    }
    return 0;
}