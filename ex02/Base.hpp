#ifndef _Data_hpp_
#define _Data_hpp_

# include <string>
# include <iostream>

class Data {
private:
	std::string secret;
public:
	Data(void );
	Data(const Data& origin);
	Data& operator =(const Data& origin);

	~Data(void );
	void TellSecret(void);
};

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif