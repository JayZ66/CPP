
#pragma once

#include <cstddef>
#include <cstdlib>
#include <sstream>

template <typename T>
class   Array {
    private:
        T* array; // Pointeur vers le tableau qui contient des elements de type T.
        size_t  sizeArray;

    public:
        Array() : array(NULL), sizeArray(0) {}

        Array(unsigned int n) : array(new T[n]) {
            sizeArray = n;
            for (unsigned int i = 0; i < n; i++) {
                array[i] = T(); // Check if it really gives the default value of the right type ! (int, string, double, ...)
            };
        }

        Array(const Array& other) {
            this->sizeArray = other.size();
            if (this->sizeArray > 0) {
                this->array = new T[this->sizeArray];
                for (size_t i = 0; i < this->sizeArray; i++) {
                    this->array[i] = other.array[i];
                }
            }
            else
                this->array = NULL;
        }


        ~Array() {
            if (array)
                delete[] array;
        }

        Array& operator=(const Array& other) {
            if (this != &other) {
                delete[] this->array; // Libérer l'ancien tableau de l'objet courant.
                this->sizeArray = other.size();
                if (this->sizeArray > 0) {
                    this->array = new T[this->sizeArray];
                    for (size_t i = 0; i < this->sizeArray; i++) {
                        this->array[i] = other.array[i];
                    }
                }
                else
                    this->array = NULL;
            }
            return *this;
        }

        // Return a ref. because it represents the direct access to an element of the array.
        T&    operator[](size_t index) {
            if (index >= this->size()) {
                std::ostringstream message;
                message << "Index " << index << " is out of range (size : " << this->size() << ")";
                throw std::out_of_range(message.str());
            }
            else
                return (this->array[index]);
        }

        // Pour accéder aux éléments d'un tableau const.
        const T&    operator[](size_t index) const {
            if (index >= this->size()) {
                std::ostringstream message;
                message << "Index " << index << " is out of range (size : " << this->size() << ")";
                throw std::out_of_range(message.str());
            }
            else
                return (this->array[index]);
        }

        size_t  size() const {
            return (this->sizeArray);
        }

};

// #include "Array.tpp"

/*
Le fichier .tpp contient les définitions des 
fonctions membres du template. Ces définitions 
doivent être accessibles au moment de l’instanciation.
*/
