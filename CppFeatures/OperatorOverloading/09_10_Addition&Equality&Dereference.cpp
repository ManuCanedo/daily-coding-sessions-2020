#include <iostream>

class Complex {
public:
	Complex(double re = 0.0, double im = 0.0) : real(re), imaginary(im)
	{
	}

	~Complex()
	{
	}

	Complex(const Complex& other)
	{
		*this = other;
	}

	const Complex& operator=(const Complex& other)
	{
		real = other.real;
		imaginary = other.imaginary;
		return *this;
	}

	bool operator==(const Complex& other) const
	{
		return real == other.real && imaginary == other.imaginary;
	}

	bool operator!=(const Complex& other) const
	{
		return !(*this == other);
	}

	Complex operator*() const
	{
		return Complex(real, -imaginary);
	}

	friend std::ostream& operator<<(std::ostream& os, const Complex& other)
	{
		os << other.real << " " << other.imaginary << "i";
		return os;
	}

	friend Complex operator+(const Complex& c1, const Complex& c2)
	{
		return Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
	}

	friend Complex operator+(const Complex& c1, const double c2)
	{
		return Complex(c1.real + c2, c1.imaginary);
	}

	friend Complex operator+(const double c1, const Complex& c2)
	{
		return Complex(c2.real + c1, c2.imaginary);
	}

private:
	double real;
	double imaginary;
};

int main()
{
	Complex c1(0.8, 0.2);
	Complex c2(1.0, 0.5);

	std::cout << c1 + c2 << std::endl;
	std::cout << *c1 + *(c2 + 2.0) << std::endl;

	if (c1 == c2)
		std::cout << "c1 and c2 are equal" << std::endl;
	else
		std::cout << "c1 and c2 are not equal" << std::endl;

	return 0;
}