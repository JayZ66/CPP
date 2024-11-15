
#include "Array.hpp"

Array::Array : sizeArray(0), array(NULL) {}

Array::Array(unsigned int n) : array(new T[n]) {
    sizeArray = n
    for (int i = 0; i < n; i++) {
        array[i] = T(); // Check if it really gives the default value of the right type ! (int, string, double, ...)
    };
}

Array::~Array() {
    if (array)
        delete[] array;
}

T*  Array::getArray() {
    return array;
}

size_t  Array::getSize() {
    return sizeArray;
}



Array::Array(const Array& other) {
    this->sizeArray = other.getSize();
    if (this->sizeArray > 0) {
        this->array = new T[this->sizeArray];
        for (int i = 0; i < this->sizeArray; i++) {
            this->array[i] = other.array[i];
        }
    }
    else
        this->array = NULL;
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] this->array; // Libérer l'ancien tableau de l'objet courant.
        this->sizeArray = other.getSize();
        if (this->sizeArray > 0) {
            this->array = new T[this->sizeArray];
            for (int i = 0; i < this->sizeArray; i++) {
                this->array[i] = other.array[i];
            }
        }
        else
            this->array = NULL;
    }
    return *this;
}

/*
Why delete[] this->array ?
    - On libère l'ancien tableau de this pour éviter qu'il reste inutilement en mémoire (car l'objet courant this
    contient déjà un tableau, d'une taille différente ou non, qui a été alloué dynamiquement).
    - Ensuite, on alloue un nouveau tableau pour y copier les données de other.
*/

 T*    Array::operator[](size_t index) {
    if (index < 0 || index >= this->getSize()) {
        std::ostringstream message;
        message << "Index " << index << "is out of range (size : " << this->size() << ")";
        throw std::out_of_range(message.str());
    }
    else
        return (this->array[index]);
 }

const T*    Array::operator[](size_t index) {
    if (index < 0 || index >= this->size()) {
        std::ostringstream message;
        message << "Index " << index << "is out of range (size : " << this->size << ")";
        throw std::out_of_range(message.str());
    }
    else
        return (this->array[index]);
 }

size_t  Array::size() const {
    return (this->sizeArray);
}