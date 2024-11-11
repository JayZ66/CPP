#include "Base.hpp"

int main() {
    srand(time(NULL)); // Init one time to obtain random results each time.

    Base *baseObject =generate(); // Appelée sur la classe Base (non sur une instance) car elle return un obj. dynamique avec new (+ methode non-static)

    identify(baseObject);
    identify(*baseObject);

    delete baseObject;
}