#include <iostream>
#include <exception>
#include <string>

class MyException : public std::exception {
public:
	virtual const char* what() const throw()
	{
		return "Something bad happened!";
	}
};

class Test {
public:
	Test()
	{
	}

	Test(bool bExceptions) : m_bUseExceptions(bExceptions)
	{
		if (m_bUseExceptions) {
			char* pMemory = new char[9999];
			delete[] pMemory;
		}
	}

	void mightGoWrong()
	{
		bool error1 = false, error2 = false, error3 = true;

		if (error1 && m_bUseExceptions)
			throw std::exception();
		if (error2 && m_bUseExceptions)
			throw std::bad_alloc();
		if (error3 && m_bUseExceptions)
			throw MyException();
	}

	void usesMightGoWrong()
	{
		mightGoWrong();
	}

private:
	bool m_bUseExceptions = false;
};

int main()
{
	Test test2(true);

	try {
		test2.usesMightGoWrong();
		std::cout << "test2 OK" << std::endl;
	} catch (std::bad_alloc& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	} catch (MyException& e) {
		std::cout << "Caught personal exception: " << e.what() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Caught generic exception: " << e.what() << std::endl;
	}
	std::cout << "Still running" << std::endl;

	return 0;
}