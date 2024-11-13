
#pragma once

template <typename T>
class   Array {
    private:
        T* element; // Why pointer ?
        size_t  sizeArray;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other); // Check if Array& becomes T&
        ~Array();

        Array& operator=(const Array& other);
};