#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h> //uintptr_t
# include "Data.hpp"

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define MAGENTA "\033[0;35m"
# define BLUE "\033[34m"
# define CYAN "\033[0;36m"
# define RST "\033[0m"

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &other);
		~Serializer();

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};
	std::ostream &operator<<(std::ostream &out, const Data &data);

#endif

// Key insight: serialization only converts the pointer's address value, not the data it points to: it simply takes the memory address stored in the pointer and converts it to a raw integer representation.
// The serialization process doesn't attempt to access or validate the memory location - it just treats the pointer as a number.

// uintptr_t is a special integer that is big enough to hold a pointer value, and works in both architectures (64 and 32 bits)