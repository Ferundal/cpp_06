#include "Data.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Wrong argumen amount" << std::endl;
		return (0);
	}
	Converter conv;
	conv.Convert(argv[1]);
}