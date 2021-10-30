#include <iostream>

class Base {
public:
	virtual ~Base(void ) {};
};

class A : public Base {
	virtual ~A(void ) {};
};

class B : public Base {
	virtual ~B(void ) {};
};

class C : public Base {
	virtual ~C(void ) {};
};

Base * generate(void) {
	std::srand(std::time(nullptr));
	switch (std::rand() % 3) {
		case 0 :
			std::cout << "A created!" << std::endl;
			return (new A());
		case 1 :
			std::cout << "B created!" << std::endl;
			return (new B());
		case 2 :
			std::cout << "C created!" << std::endl;
			return (new C());
		default:
			break;
	}
	return (nullptr);
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "Ptr A" << std::endl;
		return;
	} else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "Ptr B" << std::endl;
		return;
	} else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "Ptr C" << std::endl;
		return;
	}
	std::cout << "Woops!" <<std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "link A" << std::endl;
		return;
	}
	catch (std::exception &exception) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "link B" << std::endl;
		return;
	}
	catch (std::exception &exception) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "link C" << std::endl;
		return;
	}
	catch (std::exception &exception) {}

}

int main(){
	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
}