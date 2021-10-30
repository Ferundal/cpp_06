#include "Data.hpp"
Data::Data(void ) : secret("I love seals") {

}
Data::Data(const Data& origin) {
	*this = origin;
}
Data& Data::operator =(const Data& origin) {
	secret = origin.secret;
	return (*this);
}

Data::~Data(void ) {

}

void Data::TellSecret(void) {
	std::cout << secret << std::endl;
}

uintptr_t	serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data*		deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}