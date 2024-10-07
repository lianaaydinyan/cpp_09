#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    }
    BitcoinExchange btc("bitcoin_prices.csv");
    if (!btc.loadDatabase())
        return 1;
    btc.processInputFile(argv[1]);

    return 0;
}
