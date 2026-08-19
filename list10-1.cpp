#include <iostream>

void throw_zero()
{
	std::cout << "例外を投げる前" << std::endl;

	throw 0;

	std::cout << "例外を投げた後" << std::endl;
}

int main()
{
	try
	{
		std::cout << "関数呼び出し前"<< std::endl;
		throw_zero(); // おの関数の中で例外が投げられる
		std::cout << "関数呼び出しの後" << std::endl;
	}
	//catch(const std::exception& e)
	catch(int e)
	{
		std::cout << "投げられた例外オブジェクトの値は" << e << " です" << std::endl;
		// std::cerr << e.what() << '\n';
	}
	std::cout << "捕まえた後" << std::endl;
	
}