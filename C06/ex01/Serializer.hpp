
#pragma once

#include <iostream>
#include <cstdint>
#include "Data.hpp"

class Serializer {
    private:

    Serializer();
    Serializer(const Serializer& other);
    ~Serializer();

    Serializer& operator=(const Serializer& other);

    public:

    static uintptr_t serialize(Data *ptr); // Prend un pointeur vers un obj. de type Data et le convert to an int de type uintptr_t.
    static Data* deserialize(uintptr_t raw); // Prend un entier de type uintptr_t et le convert en un pointeur vers un obj. de type Data.
};

// uintptr_t : type entier qui garantit qu'il peut contenir un pointeur (la taille d'un pointeur dans le syst.).
// Cela permet de convertir un pointeur en entier et inversement, utile pour la sérialisation et désérialisation.

// Sérialisation : transformer un objet (pointeur) en un format qui peut être stocké ou transmis (entier de type uintptr_t)
// => On va convert l'add. mémoire de l'objet Data en un entier.

// Désérialisation : reconstruire un objet à partir de sa représentation sérialisée (entier de type uintptr_t)
// => On va convertir l'entier (uintptr_t) en un pointeur vers l'objet d'origine.