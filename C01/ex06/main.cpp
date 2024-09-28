

// CHECK VIDEOS + GPT COURSE !!

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl    mood;

    if (argc != 2) {
        std::cout << "One complain at a time please !" << std::endl;
        return 1;
    }
    std::string complainLevel = argv[1];
    mood.complain(complainLevel);
    return 0;
}