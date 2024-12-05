#include "BitcoinExchange.hpp"

int main(int ac, char **av) {

    if (ac < 2) {
        std::cerr << "Error: add a file to convert bitcoin." << std::endl;
        return 1;
    }
    try {
        BitcoinExchange exchange;

        exchange.loadExchangeRates("data.csv");
        exchange.manageInputFile(av[1]);

    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}