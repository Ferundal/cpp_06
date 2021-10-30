#include "Data.hpp"

int main(){
	Data *ptr = new Data();
	ptr->TellSecret();
	uintptr_t _my_uintptr_t = serialize(ptr);
	_my_uintptr_t = _my_uintptr_t + 10;
	_my_uintptr_t = _my_uintptr_t - 10;
	Data *new_ptr = deserialize(_my_uintptr_t);
	new_ptr->TellSecret();
}