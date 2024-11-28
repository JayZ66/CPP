
#include "easyfind.hpp"

int main() {

    int array[] = {6, 5, 4, 3, 2, 1, 0};

    std::vector<int> vectorArray;
    std::list<int>  listArray;
    std::deque<int> dequeArray;

    std::cout << "Content of containers: " << std::endl;
    for (unsigned long i = 0; i < 7; i++) {
        vectorArray.push_back(array[i]);
        listArray.push_back(array[i]);
        dequeArray.push_back(array[i]);
        std::cout << "vectorArray[" << i << "] value: " << vectorArray.at(i) << std::endl;
        std::cout << "dequeArray[ " << i << "] value: " << dequeArray.at(i) << std::endl;
    }

    try {
        std::cout << std::endl;
        std::vector<int>::iterator itFirst = ::easyfind<std::vector<int> >(vectorArray, 3); // Specifier le type T au plus grand appelant (ici le return de easyfind) et determinera celui en param. du coup
        std::cout << "Found in vectorArray value: " << *itFirst << std::endl;

    }
    catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {

        std::cout << std::endl;
        std::deque<int>::iterator itDeque = ::easyfind<std::deque<int> >(dequeArray, 10);
        std::cout << "Found in dequeArray value: " << *itDeque << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator    itList = listArray.begin();
        std::cout << std::endl;
        listArray.push_back(150);
        size_t i = 0;
        while (i < 5) {
            itList = listArray.insert(itList, 50); // The container is extended by inserting new elements before the element at the specified position.
            ++itList;
            i++;
        }
        for (itList = listArray.begin(); itList != listArray.end(); itList++) 
            std::cout << "listArray[" << i << "] modified value: " << *itList << std::endl;
        
        std::cout << std::endl;
        itList = ::easyfind<std::list<int> >(listArray, 150);
        std::cout << "Found in listArray value: " << *itList << std::endl;
        itList = ::easyfind<std::list<int> >(listArray, 350);

    }
    catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Adding number 10 to dequeArray." << std::endl;
    try {
        dequeArray.push_back(10);
        std::deque<int>::iterator itDeque = ::easyfind<std::deque<int> >(dequeArray, 10);
        std::cout << "Found in dequeArray modified value: " << *itDeque << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}