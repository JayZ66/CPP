 #include "ScalarConverter.hpp"


 int    main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "There is no literal to convert, please write something." << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);

    return 0;
 }