#include <iostream>
#include <string>
#include <algorithm>

void primary_school_multiplication(const std::string& num1, const std::string& num2, int* result)
{
	for (int i = 0; i < num2.length(); i++)
		for (int j = 0; j < num1.length(); j++)
			result[i + j] += ((int)num1[j] - 48) * ((int)num2[i] - 48);

	int carry = 0;
	for (int i = 0; i < num2.length() + num1.length(); i++) {
		result[i] += carry;
		carry = result[i] / 10;
		result[i] -= carry * 10;
	}
	if (carry != 0)
		fprintf(stderr, "Overflow %d", carry);
}

int main()
{
	std::string input_num1, input_num2;
	std::cout << "Enter a number:" << std::endl;
	std::cin >> input_num1;
	std::cout << "Enter another number:" << std::endl;
	std::cin >> input_num2;

	int result[1024]{};

	std::reverse(input_num1.begin(), input_num1.end());
	std::reverse(input_num2.begin(), input_num2.end());
	primary_school_multiplication(input_num1, input_num2, result);

	bool isTrim = true;
	for (int i = input_num2.length() + input_num1.length(); i >= 0; i--) {
		if (isTrim && result[i] == 0)
			continue;
		isTrim = false;
		std::cout << result[i];
	}

	return 0;
}
