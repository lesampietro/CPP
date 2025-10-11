#include "../includes/Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &copy) {
	(void)copy;
}

Serializer &Serializer::operator=(const Serializer &other) {
	(void)other;
	return *this;
}

Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(Data *ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data *>(raw);
}

std::ostream &operator<<(std::ostream &out, const Data &data){
	out << "data.name: " << CYAN << data.name << RST << ", ";
	out << "data.age: " << CYAN << data.age << RST << ".\n";
	return out;
}