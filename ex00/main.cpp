#include "Converter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Wrong argumen amount" << std::endl;
		return (0);
	}
	Data conv;
	conv.Convert(argv[1]);
}