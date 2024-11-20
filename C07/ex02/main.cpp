
#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750

int main(int, char**)
{

    std::cout << "Empty array creation." << std::endl;
    Array<int> empty;
    std::cout << "Empty array size : " << empty.size() << std::endl;

    std::cout << "String array creation." << std::endl;
    Array<std::string> stringArray(4);
    stringArray[0] = "Hello";
    stringArray[1] = "How";
    stringArray[2] = "are";
    stringArray[3] = "you ?";
    std::cout << "String array size : " << stringArray.size() << std::endl;
    std::cout << "String array elements :" << std::endl;
    for (size_t i = 0; i < stringArray.size(); i++)
        std::cout << stringArray[i] << " ";
    std::cout << std::endl;


    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "Check assignation operator (nb): " << std::endl;
        for (int i = 0; i < MAX_VAL; i++) {
            std::cout << "numbers[i]: " << numbers[i] << " vs tmp[i]: " << tmp[i] << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Check copy constructor: " << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
            std::cout << "numbers[i]: " << numbers[i] << " vs test[i]: " << test[i] << std::endl;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        // std::cout << "Numbers[i] value: " << numbers[i] << std::endl;
        // std::cout << "Mirror[i] value: " << mirror[i] << std::endl;
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0; // Should create an exception ??
    }
    catch(const std::exception& e)
    {
        std::cerr << "Caught exception:" << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Caught exception:" << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "Modified values from numbers array: " << std::endl;
        numbers[i] = rand();
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    
    delete [] mirror;
    return 0;
}

/*
OTHER TESTS TO DO :
Another main with less values.
- Test de modifier les valeurs d'un array int existant (print before & after)
- Copie éléments de l'array précédent (copy constructor)
- Opérateur d'assignation
+ modification de l'array modifié et check valeur array de base (pour valider la copie profonde !)
- Test out of range values !
*/