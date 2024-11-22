
#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750

// int main(int, char**)
// {

// 	std::cout << "Empty array creation." << std::endl;
// 	Array<int> empty;
// 	std::cout << "Empty array size : " << empty.size() << std::endl;

// 	std::cout << "String array creation." << std::endl;
// 	Array<std::string> stringArray(4);
// 	stringArray[0] = "Hello";
// 	stringArray[1] = "How";
// 	stringArray[2] = "are";
// 	stringArray[3] = "you ?";
// 	std::cout << "String array size : " << stringArray.size() << std::endl;
// 	std::cout << "String array elements :" << std::endl;
// 	for (size_t i = 0; i < stringArray.size(); i++)
// 		std::cout << stringArray[i] << " ";
// 	std::cout << std::endl;


// 	Array<int> numbers(MAX_VAL);
// 	int* mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	//SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 		std::cout << "Check assignation operator (nb): " << std::endl;
// 		for (int i = 0; i < MAX_VAL; i++) {
// 			std::cout << "numbers[i]: " << numbers[i] << " vs tmp[i]: " << tmp[i] << std::endl;
// 		}
// 		std::cout << std::endl;
// 		std::cout << "Check copy constructor: " << std::endl;
// 		for (int i = 0; i < MAX_VAL; i++)
// 			std::cout << "numbers[i]: " << numbers[i] << " vs test[i]: " << test[i] << std::endl;
// 	}
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		// std::cout << "Numbers[i] value: " << numbers[i] << std::endl;
// 		// std::cout << "Mirror[i] value: " << mirror[i] << std::endl;
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}

// 	std::cout << std::endl;
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << "Caught exception:" << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << "Caught exception:" << e.what() << '\n';
// 	}
// 	std::cout << std::endl;
// 	std::cout << "Modified values from numbers array: " << std::endl;
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
		
// 		numbers[i] = rand();
// 		std::cout << "numbers[" << i << "] value: " << numbers[i] << std::endl;
// 	}
	
// 	delete [] mirror;
// 	return 0;
// }

int	main() {
	Array<int>	digits(6);

	std::cout << "Digits array creation with size of " << digits.size() << std::endl;
	for (size_t i = 0; i < digits.size(); i++) {
		digits[i] = static_cast<int>(i * 50);
		std::cout << "digits[" << i << "] value: " << digits[i] << std::endl;
	}

	std::cout << "Test to access out of range value." << std::endl;
	try {
		digits[100] = 10;
	}
	catch (std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Creating empty array." << std::endl;
	Array<int> empty;
	std::cout << "Size of empty array: " << empty.size() << std::endl;

	std::cout << std::endl;
	std::cout << "Test copy constructor." << std::endl;
	Array<int>	copy(digits);
	std::cout << "Size of copy array is " << copy.size() << std::endl;
	for (size_t i = 0; i < copy.size(); i++) {
		std::cout << "copy[" << i << "] value: " << copy[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Modification of copy array values." << std::endl;
	for (size_t i = 0; i < copy.size(); i++) {
		copy[i] += 15;
		std::cout << "copy[" << i << "] modified value: " << copy[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Modification of digits array values." << std::endl;
	for (size_t i = 0; i < digits.size(); i++) {
		digits[i] *= 100;
		std::cout << "digits[" << i << "] modified value: " << digits[i] << std::endl;
	}

	std::cout << std::endl;
	Array<int>	assignation(15);
	std::cout << "Creation of assignation array with the size of " << assignation.size() << std::endl;
	for (size_t i = 0; i < assignation.size(); i++) {
		assignation[i] = static_cast<int>(i * (-10));
		std::cout << "assignation[" << i << "] value: " << assignation[i] << std::endl;
	}

	std::cout << "Test assignment operator." << std::endl;
	assignation = copy;
	std::cout << "Modification of assignation array with copy array values thanks to the assignment operator." << std::endl;
	std::cout << "Its new size is of " << assignation.size() << std::endl;
	for (size_t i = 0; i < assignation.size(); i++) {
		std::cout << "assignation[" << i << "] modified value: " << assignation[i] << std::endl;
	}

	std::cout << std::endl;
	Array<std::string>	string(6);
	string[0] = "Hello, ";
	string[1] = "how ";
	string[2] = "are ";
	string[3] = "you ";
	string[4] = "today ";
	string[5] = "??";
	std::cout << "String array creation with the size of " << string.size() << std::endl;
	std::cout << "String array values: ";
	for (size_t i = 0; i < string.size(); i++) {
		std::cout << string[i];
	}

	std::cout << std::endl;
	std::cout << "Test to access out of range value." << std::endl;
	try {
		string[-3] = "Coucou";
	}
	catch (std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Test to access a const array." << std::endl;
	try {
        Array<int> arr(5);

        for (size_t i = 0; i < arr.size(); ++i) {
            arr[i] = static_cast<int>(i * 10);
        }

        const Array<int> constArr = arr;

        // Read avec const operator[]
        for (size_t i = 0; i < constArr.size(); ++i) {
            std::cout << "Element " << i << ": " << constArr[i] << std::endl;
        }

		// constArr[1] = 0; // Test access constArr value with operator[]
    } catch (const std::exception& e) {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
    }


}

