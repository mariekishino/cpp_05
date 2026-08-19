/* 
P.494
10.4.1 std::exception とwhat()メンバ関数
*/

#include <iostream>
#include <exception>

class my_exception : public std::exception
{
	const char *message;

	public:
		explicit my_exception(const char *message);
		const char* what() const throw();
};

my_exception::my_exception(const char *message) : message(message)
{
}

const char *my_exception::what() const throw()
{
	return message;
}

int main()
{
	try
	{
		throw my_exception("My Exception");
	}
	catch(const std::exception& e)
	{
		std::cout << "what: " << e.what() << std::endl;
	}
}