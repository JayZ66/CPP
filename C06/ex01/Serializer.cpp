
#include "Serializer.hpp"

static uintptr_t serialize(Data *ptr) { // Prend un pointeur vers un obj. de type Data et le convert to an int de type uintptr_t.

    return reinterpret_cast<uintptr_t>(ptr);
}

// Reinterpret_cast : conçu pour les conversions de pointeurs vers des entiers (entre des types de données non liés) sans modifier les bits (représentation binaire)
// de l'adresse.

// uintptr : type entier non signé qui peut contenir l'add. mémoire d'un objet sous forme d'un nb entier sans perdre d'infos.
    
static Data* deserialize(uintptr_t raw) { // Reconvertir l'entier uintptr_t en un pointeur vers l'objet d'origine pour pouvoir y accéder ainsi qu'à ses données !
    
    return reinterpret_cast<Data*>(raw);

}

// Raw = valeur entière qui représente l'add. mémoire de l'objet.