
#include "Array.hpp"

template <typename T>
Array<T>::Array() : sizeArray(0), array(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]) {
    sizeArray = n;
    for (int i = 0; i < n; i++) {
        array[i] = T(); // Check if it really gives the default value of the right type ! (int, string, double, ...)
    };
}

template <typename T>
Array<T>::~Array() {
    if (array)
        delete[] array;
}

template <typename T>
Array<T>::Array(const Array& other) {
    this->sizeArray = other.size();
    if (this->sizeArray > 0) {
        this->array = new T[this->sizeArray];
        for (int i = 0; i < this->sizeArray; i++) {
            this->array[i] = other.array[i];
        }
    }
    else
        this->array = NULL;
}

template <typename T>
Array& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] this->array; // Libérer l'ancien tableau de l'objet courant.
        this->sizeArray = other.size();
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

template <typename T>
T&    Array<T>::operator[](unsigned int index) {
    if (index >= this->size()) {
        std::ostringstream message;
        message << "Index " << index << "is out of range (size : " << this->size() << ")";
        throw std::out_of_range(message.str());
    }
    else
        return (this->array[index]);
 }

template <typename T>
const T&    Array<T>::operator[](unsigned int index) {
    if (index >= this->size()) {
        std::ostringstream message;
        message << "Index " << index << "is out of range (size : " << this->size << ")";
        throw std::out_of_range(message.str());
    }
    else
        return (this->array[index]);
 }

template <typename T>
size_t  Array<T>::size() const {
    return (this->sizeArray);
}