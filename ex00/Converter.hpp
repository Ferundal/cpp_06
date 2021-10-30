#ifndef _Converter_hpp_
#define _Converter_hpp_

# include <string>
# include <iostream>
# include <sstream>
# include <cctype>
# include <iomanip>
# define CONVERT_TYPE_AMNT 4
# define DOUBLE_LITERAL_AMNT 3


class Data {
private:
	static const std::string	dLiterals[DOUBLE_LITERAL_AMNT];
	bool						(Data::*checkers[CONVERT_TYPE_AMNT])(const char *arg);
	void						(Data::*actions[CONVERT_TYPE_AMNT])(const char *arg);
public:

	Data(void );
	Data(const Data& origin);
	Data& operator =(const Data& origin);

	~Data(void );

	void Convert(const char *arg);

	bool isChar(const char *arg);
	bool isInt(const char *arg);
	bool isDouble(const char *arg);
	bool isFloat(const char *arg);
	void fromChar(const char *arg);
	void fromInt(const char *arg);
	void fromDouble(const char *arg);
	void fromFloat(const char *arg);
	void PutChar(const char &_t_char);
	void PutInt(const int &_t_int);
	void PutDouble(const double &_t_double);
	void PutFloat(const float &_t_float);
};
#endif