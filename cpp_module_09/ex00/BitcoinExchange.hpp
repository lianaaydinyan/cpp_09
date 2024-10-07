#ifndef _my_coin_
#define _my_coin_

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>  
#include <limits>

class BitcoinExchange
{
    private:
        std::map<std::string, double> couple;
        std::string file;
        std::ifstream data;
    public:
        bool loadDatabase();
        BitcoinExchange(const std::string& filename);
        void processInputFile(const std::string& inputFilename);
    private:
        std::string trim(const std::string& str) const;
        bool isValidDate(const std::string& date) const;
        std::string findClosestDate(const std::string& inputDate) const;
};

#endif