#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	std::srand(std::time(nullptr));
	switch (std::rand() % 3) {
		case 0 :
			return (new A());
			std::cout << "A created!" << std::endl;
			break;
		case 1 :
			return (new B());
			std::cout << "B created!" << std::endl;
			break;
		case 2 :
			return (new C());
			std::cout << "C created!" << std::endl;
			break;
		default:
			break;
	}
	return (nullptr);
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "C" << std::endl;
	}
	std::cout << "Woops!" <<std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception &exception) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &exception) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &exception) {}

}

int main(){
	Base *ptr = generate();
	identify(ptr);
}