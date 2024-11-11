#include "Serializer.hpp"
#include "Data.hpp"

int main(){
    Data data;

    data.id = 66;
    data.name = "Donnée";
    data.value = 3.33f;

    // Print add. de base de l'objet data
    std::cout << "Data address: " << &data << std::endl;

    // Serializer l'objet Data
    uintptr_t serialized = Serializer::serialize(&data);

    std::cout << "Data object serialized: " << serialized << std::endl;

    // Deserializer l'entier contenant l'add. de l'objet.
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Int 'serialized' that contains Data object add. has been deserialized: " << deserialized << std::endl;

    // Check si les add. sont les même et donc que le cast s'est bien déroulé !
    if (&data == deserialized)
        std::cout << "Serialization is a success !" << std::endl;
    else {
        std::cout << "Serialization is a failure !" << std::endl;
        return 1;
    }
    // Check si values are the same ??

    std::cout << "Let's check object values: " << std::endl;
    std::cout << "Data values: " << std::endl << "ID - " << data.id << std::endl 
                                            << "NAME - " << data.name << std::endl
                                            << "VALUE - " << data.value << std::endl;
    std::cout << "Serialized Data values: " << std::endl << "ID - " << deserialized->id << std::endl 
                                            << "NAME - " << deserialized->name << std::endl
                                            << "VALUE - " << deserialized->value << std::endl;

    return 0;
}