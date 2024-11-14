
#pragma once

template <typename T>
class   Array {
    private:
        T* array; // Pointeur vers le tableau qui contient des elements de type T.
        size_t  sizeArray;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other); // Check if Array& becomes T&
        ~Array();

        Array& operator=(const Array& other);
        T*    operator[](size_t index);

        size_t size();

        T*  giveArray() const;
};

