
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
        T*    operator[](unsigned int index);
        const T*    operator[](unsigned int index) const; // Pour accéder aux éléments d'un tableau const.

        size_t size() const;

        T*  getArray() const;
};

