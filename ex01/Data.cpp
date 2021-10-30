#include "Data.hpp"
Data::Data(void ) {

}
Data::Data(const Data& origin) {

}
Data::Data& operator =(const Data& origin) {

}

Data::~Data(void ) {

}

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);