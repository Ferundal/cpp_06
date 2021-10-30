#include "Converter.hpp"

const std::string Converter::dLiterals[] = {
		"-inf",
		"+inf",
		"nan"
} ;

Converter::Converter(void ) {
	checkers[0] = &Converter::isChar;
	checkers[1] = &Converter::isInt;
	checkers[2] = &Converter::isDouble;
	checkers[3] = &Converter::isFloat;
	actions[0] = &Converter::fromChar;
	actions[1] = &Converter::fromInt;
	actions[2] = &Converter::fromDouble;
	actions[3] = &Converter::fromFloat;
}

Converter::Converter(const Converter& origin) {
	*this = origin;
}

Converter& Converter::operator =(const Converter& origin) {
	for (int i = 0; i < CONVERT_TYPE_AMNT; i++) {
		checkers[i] = origin.checkers[i];
		actions[i] = origin.actions[i];
	}
	return (*this);
}

void Converter::Convert(const char *arg) {
	for (int i = 0; i < CONVERT_TYPE_AMNT; i++) {
		if ((this->*checkers[i])(arg)) {
			(this->*actions[i])(arg);
			return;
		}
	}
}

bool Converter::isChar(const char *arg) {
	if (arg[0] != '\0' && arg[1] == '\0'
		&& std::isprint(arg[0]) && !std::isdigit(arg[0]))
		return (true);
	else
		return (false);
}
bool Converter::isInt(const char *arg) {
	std::istringstream str_stream((std::string(arg)));
	int _t_int;
	if (!(str_stream >> _t_int).fail() && str_stream.eof())
		return (true);
	else
		return (false);
}
bool Converter::isDouble(const char *arg) {
	std::string str_arg (arg);
	std::istringstream str_stream(str_arg);
	double _t_int;
	if (!(str_stream >> _t_int).fail() && str_stream.eof())
		return (true);
	else
		return (false);
}

bool Converter::isFloat(const char *arg) {
	std::string str_arg (arg);
	if (str_arg.find_last_of('f') != str_arg.length() - 1)
		return (false);
	str_arg.erase(str_arg.length() - 1);
	std::istringstream str_stream(str_arg);
	float _t_float;
	if (!(str_stream >> _t_float).fail() && str_stream.eof()) {
		std::cout << _t_float << std::endl;
		return (true);
	} else
		return (false);
}

void Converter::fromChar(const char *arg) {
	char _t_char = arg[0];
	std::cout << "char: ";
	this->PutChar(_t_char);
	std::cout << "int: ";
	try {
		int _t_int = static_cast<int>(_t_char);
		this->PutInt(_t_int);
	}
	catch (std::exception &exception)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "float: ";
	try {
		int _t_float = static_cast<int>(_t_char);
		this->PutFloat(_t_float);
	}
	catch (std::exception &exception)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "double: ";
	try {
		int _t_double = static_cast<int>(_t_char);
		this->PutDouble(_t_double);
	}
	catch (std::exception &exception)
	{
		std::cout << "impossible" << std::endl;
	}
}



void Converter::fromInt(const char *arg) {
	std::istringstream str_stream((std::string(arg)));
	int _t_int;
	str_stream >> _t_int;
	std::cout << "char: ";
	try {
		char _t_char = static_cast<char>(_t_int);
		this->PutChar(_t_char);
	}
	catch (std::exception &exception)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "int: ";
	this->PutInt(_t_int);
	std::cout << "float: ";
	try {
		int _t_float = static_cast<int>(_t_int);
		this->PutFloat(_t_float);
	}
	catch (std::exception &exception)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "double: ";
	try {
		int _t_double = static_cast<int>(_t_int);
		this->PutDouble(_t_double);
	}
	catch (std::exception &exception)
	{
		std::cout << "impossible" << std::endl;
	}
}

void Converter::fromDouble(const char *arg) {
	std::istringstream str_stream((std::string(arg)));
	double _t_double;
	str_stream >> _t_double;
	std::cout << "char: ";
	try {
		std::ostringstream ss;
		ss << _t_double;
		std::string s(ss.str());
		if (s == "nan" || s == "-inf" || s == "inf")
			throw std::exception();
		char _t_char = static_cast<char>(_t_double);
		this->PutChar(_t_char);
	}
	catch (std::exception &exception)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "int: ";
	try {
		std::ostringstream ss;
		ss << _t_double;
		std::string s(ss.str());
		if (s == "nan" || s == "-inf" || s == "inf")
			throw std::exception();
		int _t_int = static_cast<int>(_t_double);
		std::cout << _t_int << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "float: ";
	try {
		double _t_float;
		std::ostringstream ss;
		ss << _t_double;
		std::string s(ss.str());
		if (s == "nan" || s == "-inf" || s == "inf") {
			std::istringstream str_stream(s);
			str_stream >> _t_float;
		}
		else
			_t_float = static_cast<int>(_t_double);
		this->PutFloat(_t_float);
	}
	catch (std::exception &exception)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "double: ";
	this->PutDouble(_t_double);
}

void Converter::fromFloat(const char *arg) {
	std::string str_arg (arg);
	str_arg.erase(str_arg.length() - 1);
	std::istringstream str_stream(str_arg);
	float _t_float;
	str_stream >> _t_float;
	std::cout << "char: ";
	try {
		std::ostringstream ss;
		ss << _t_float;
		std::string s(ss.str());
		if (s == "nan" || s == "-inf" || s == "inf")
			throw std::exception();
		char _t_char = static_cast<char>(_t_float);
		this->PutChar(_t_char);
	}
	catch (std::exception &exception)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "int: ";
	try {
		std::ostringstream ss;
		ss << _t_float;
		std::string s(ss.str());
		if (s == "nan" || s == "-inf" || s == "inf")
			throw std::exception();
		int _t_int = static_cast<int>(_t_float);
		this->PutInt(_t_int);
	}
	catch (std::exception &exception)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "float: ";
	this->PutFloat(_t_float);
	std::cout << "double: ";
	try {
		double _t_double;
		std::ostringstream ss;
		ss << _t_float;
		std::string s(ss.str());
		if (s == "nan" || s == "-inf" || s == "inf") {
			std::istringstream str_stream(s);
			str_stream >> _t_double;
		}
		else
			_t_double = static_cast<int>(_t_float);
		this->PutDouble(_t_double);
	}
	catch (std::exception &exception)
	{
		std::cout << "impossible" << std::endl;
	}
}

void Converter::PutChar(const char &_t_char) {
	if (std::isprint(_t_char))
		std::cout << _t_char << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}
void Converter::PutInt(const int &_t_int) {
	std::cout << _t_int << std::endl;
}
void Converter::PutDouble(const double &_t_double) {
	if (static_cast<double>(static_cast<long>(_t_double)) == _t_double)
		std::cout << std::fixed << std::setprecision(1) << _t_double << std::endl;
	else
		std::cout << _t_double << std::endl;
}
void Converter::PutFloat(const float &_t_float) {
	if (static_cast<float>(static_cast<int>(_t_float)) == _t_float)
		std::cout << std::fixed << std::setprecision(1) << _t_float << 'f' << std::endl;
	else
		std::cout << _t_float << 'f' << std::endl;
}

Converter::~Converter(void ) {

}