 #include "ScalarConverter.hpp"


 int    main(int argc, char **argv) {
    
    if (argc < 2) {
        std::cerr << "There is no literal to convert, please write something." << std::endl;
        return 1;
    }
    else if (argc > 2) {
        std::cerr << "There are too many literals to convert, please write only one." << std::endl;
        return 1;
    }

    ScalarConverter::convert(argv[1]);

    return 0;
 }