#include "Bureaucrat.hpp"

int main() {
	try
	{
		Bureaucrat ok_bur ("Ok_Bur", 67);
		std::cout << ok_bur <<std::endl;
		ok_bur++;
		std::cout << ok_bur <<std::endl;
		ok_bur--;
		std::cout << ok_bur <<std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "You shoud not see that message!" <<std::endl;
	}
	try
	{
		Bureaucrat ok_bur ("Ok_Bur", 1);
		std::cout << ok_bur <<std::endl;
		ok_bur++;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat ok_bur ("Ok_Bur", 150);
		std::cout << ok_bur <<std::endl;
		ok_bur--;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat not_ok_bur ("Not_ok_Bur", -7);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat not_ok_bur ("Not_ok_Bur", 155);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}