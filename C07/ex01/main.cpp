#include "iter.hpp"

template<typename T>
void    printArrayElement(T& element) {

	std::cout << element << " ";
}

void    toUpper(char& letter) {
	if (letter >= 'a' && letter <= 'z')
		letter -= 32;
}

template<typename T>
void    addOne(T& digit) {
	digit += 1;
}


// If value needs to be a ref. we cannot send a direct value (rvalue) but we must send an existing var. (lvalue).
template<typename T>
void    initArray(T* array, T& value, int size)
{
	for (int i = 0; i < size; i++) {
		array[i] = value;
		value++;
	}
}

void    initStringArray(std::string* array) { // Created because we can't use initArray() cause of value modification (cannot ++ a string)
	array[0] = "Salut";
	array[1] = "comment";
	array[2] = "tu";
	array[3] = "vas ?";
}

void	changeWord(std::string& string) {
	string = "Modified";
}



// CHECK FOR CREATION OF EMPTY ARRAY
int main() {

	// Testing int array
	int* intArray = new int[4];
	int value = 0;
	initArray(intArray, value, 4);
	std::cout << "Int array: [ ";
	::iter(intArray, 4, printArrayElement<int>);
	std::cout << "]" << std::endl;

	::iter(intArray, 4, addOne<int>);
	std::cout << "Int array updated: [ ";
	::iter(intArray, 4, printArrayElement<int>);
	std::cout << "]" << std::endl;

	// Testing char array

	char*   charArray = new char[4];
	char	character = 'a';
	initArray(charArray, character, 4);
	std::cout << "Char array: [ ";
	::iter(charArray, 4, printArrayElement<char>);
	std::cout << "]" << std::endl;

	::iter(charArray, 4, toUpper);
	std::cout << "Char array updated: [ ";
	::iter(charArray, 4, printArrayElement<char>);
	std::cout << "]" << std::endl;

	//Testing char* array
	std::string*   stringArray = new std::string[4];
	initStringArray(stringArray);
	std::cout << "String array: [ ";
	::iter(stringArray, 4, printArrayElement<std::string>);
	std::cout << "]" << std::endl;
	::iter(stringArray, 4, changeWord);
	std::cout << "String array updated: [ ";
	::iter(stringArray, 4, printArrayElement<std::string>);
	std::cout << "]" << std::endl;

	// Testing float array
	float*	floatArray = new float[4];
	float digit = 6.6;
	initArray(floatArray, digit, 4);
	std::cout << "Float array: [ ";
	::iter(floatArray, 4, printArrayElement<float>);
	std::cout << "]" << std::endl;

	::iter(floatArray, 4, addOne<float>);
	std::cout << "Float array updated: [ ";
	::iter(floatArray, 4, printArrayElement<float>);
	std::cout << "]" << std::endl;

	delete[]	intArray;
	delete[]	charArray;
	delete[]    stringArray;
	delete[]	floatArray;

	return 0;
}

/*
":" - l'operateur de resolution de portee globale : 
	=> permet d’accéder à des éléments globaux ou dans des namespaces.
Lorsque tu appelles une fonction template globale, il peut être nécessaire de spécifier le :: pour clarifier que cette 
fonction est bien celle définie globalement, en particulier si une fonction du même nom existe localement.

Pourquoi add <type> apres template de fonction ?
	=> spécifies explicitement le type T pour cette fonction template (ici int). C'est important car dans certains contextes, 
	le compilateur ne peut pas toujours déduire automatiquement le type des templates de fonction.
*/