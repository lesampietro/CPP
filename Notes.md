# CPP Notes

## Floating point numbers

Floating point numbers can be unprecise, or generate unprecise results when applied to mathematical formulae. Why is that?

I. Accuracy vs. Precision
"Accuracy refers to how close a measurement is to the true value, whereas precision has to do with how much information you have about a quantity, how uniquely you have it pinned down"

Integers can be completely accurate, but lack precision because they are unable to keep track of the fractional part (if we divide both 5 and 4 by 2, we will always get 2 as a result). 

Floating point numbers are the opposite: they have good precision but poor accuracy.

"Not every fraction can be represented exactly in binary, whereas any integer can."

------------------------------------------------

#### Floating point number representation

"Floating point representations vary from machine to machine.
Fortunately one is by far the most common these days: the IEEE-754 standard."

An IEEE-754 float (4 bytes) or double (8 bytes) has three components:
- a sign bit telling whether the number is positive or negative
- an exponent giving its order of magnitude
- a mantissa specifying the actual digits of the number. 

The value of the number is the mantissa times 2^x, where x is the exponent.

------------------------------------------------

#### Representação de números fixed-point: 

Um número fixed-point usa um número inteiro para representar tanto a parte inteira quanto a parte fracionária de um número real. Isso é feito implicitamente, reservando um número fixo de bits para a parte fracionária.

------------------------------------------------

## C++ literals
Values such as numbers, characters or string characters whose values are self-evident are know as literals

Integer literals:
We can write an integer literal using decimal, octal, or hexadecimal notation
- Decimal - "normal representation"
- Octal - Integer literals that begin with 0 (zero) are interpreted as octal
- Hexadecimal - Integer literals that begin with either 0x or 0X are interpreted as hexadecimal 

***Different interpretations of the same number:***
- decimal: 25
- octal: 031
- hexadecimal: 0x19

------------------------------------------------

## Templates

### Function Templates
Templates let you write a function or class that works with different data types. To create a function template, we use the keyword ***template***:

``` c++
template <typename_T>
return_type	function_name(T parameter) {
	// code
}
```
- ***T is the common placeholder*** for a data type (like int, float, etc).

#### Example
``` c++
template <typename T>
T add(T a, T b) {
	return a + b;
}

int main() {
	cout << add<int>(5, 3) << "\n";
	cout << add<double>(2.5, 1.5) << "\n";
	return 0;
}
```

- In the example above, add<int>(5, 3) tells the compiler to use int for T, while add<double>(2.5, 1.5) tells it to use double.

### Class Templates

Following the same idea for the function templates, here's the syntax for classes:
``` c++
template <typename_T>
class ClasName {
	// code
}
```
The example below defines a ***template class Box that can store and display a value of any data type***, and then creates one box for an int and one for a string:
```c++
template <typename_T>
class Box {
	public:
		T _value;
		
		//Parametrized Constructor implemented inside class declaration
		Box(T val) : _value(val) {}

		//getter implemented inside class declaration
		void getVal() {
			std::cout << "Value: " << this->_value << std::endl ;
		}
};

int main() {
	Box<int> intBox(42); // name the constructor function as we wish
	Box<string> strBox("Hello");

	intBox.getVal();
	strBox.getVal();
	return 0;
}
```

It is possible to create and define a class that store two or even more values of different types, like the example below:
```c++
template <typename T1, typename T2>
class Pair {
	public:
		T1 _first;
		T2 _second;
	
	Pair (T1 a, T2 b) : _first(a), _second(b) {}
	void display() {
		std::cout << "First: " << this->_first << ", Second: " << this->_second << std::endl;
	}
};

int main() {
	Pair<string, int> person("Alice", 28);
	Pair<int, double> scores(42, 9.8);

	person.display();
	scores.display();
	return (0);
}
```

> **Note:** Templates must be defined in the same file where they are used (usually in the .h file).

------------------------------------------------

## Data Structures & Containers
#### Data Structures
- **Conceptual Focus**: A data structure is a theoretical or abstract way of storing and organizing data to perform operations (like insertion, deletion, and retrieval) efficiently.
- **Generality**: The term is language-agnostic. Concepts like linked lists, binary trees, and hash tables are data structures that can be implemented in virtually any programming language.
- **Implementation**: Programmers can implement custom data structures from scratch using primitive types and classes in C++.

#### CPP Containers
- **Implementation Focus**: C++ containers are concrete class templates provided by the STL that offer ready-to-use, robust implementations of common data structures.
- **Standardized Interface**: ***All STL containers share a common interface*** (e.g., begin(), end(), size(), empty(), swap() member functions), allowing them to work seamlessly with STL algorithms and iterators.
- **Memory Management**: Containers automatically handle memory management for the elements they contain (e.g., dynamic resizing in std::vector), reducing boilerplate code and potential memory leaks.

### CPP STL
STL is a library that consist of different data structures and algorithms to effectively store and manipulate data.

#### Key Concepts of the STL
The key components of the STL consist of containers, iterators, and algorithms, and the relationship between them:

- **Containers** are data structures that provide a way to store data, like vectors, lists, etc.
- **Iterators** are objects used to access elements of a data structure.
- **Algorithms** include functions, like sort() and find(), that perform operations on data structures through iterators.

