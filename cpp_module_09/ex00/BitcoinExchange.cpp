
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& filename) : file(filename) {}

bool BitcoinExchange::loadDatabase()
{
    data.open(file.c_str());
    if (!data.is_open())
    {
        std::cerr << "Error: could not open file " << file << std::endl;
        return false;
    }

    std::string line;
    while (getline(data, line))
    {
        std::string date;
        double price;
        std::stringstream ss(line);
        if (getline(ss, date, ',') && (ss >> price))
            couple[trim(date)] = price;
    }
    data.close();
    return true;
}

void BitcoinExchange::processInputFile(const std::string& inputFilename)
{
    std::ifstream inputFile(inputFilename.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    while (getline(inputFile, line))
    {
        std::stringstream ss(line);
        std::string date, valueStr;
        if (getline(ss, date, '|') && getline(ss, valueStr))
        {
            date = trim(date);
            valueStr = trim(valueStr);
            if (!isValidDate(date))
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            double value = std::atof(valueStr.c_str());
            if (value < 0)
            {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            else if (value > 1000)
            {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }
            std::string closestDate = findClosestDate(date);
            double btcPrice = couple[closestDate];
            std::cout << closestDate << " => " << value << " = " << (value * btcPrice) << std::endl;
        }
        else
            std::cerr << "Error: bad input => " << line << std::endl;
    }
    inputFile.close();
}

std::string BitcoinExchange::trim(const std::string& str) const
{
    size_t first = str.find_first_not_of(" \t");
    size_t last = str.find_last_not_of(" \t");
    return (first == std::string::npos || last == std::string::npos) ? "" : str.substr(first, last - first + 1);
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    return true;
}

std::string BitcoinExchange::findClosestDate(const std::string& inputDate) const
{
    std::map<std::string, double>::const_iterator it = couple.lower_bound(inputDate);
    if (it != couple.begin() && (it == couple.end() || it->first != inputDate))
        --it;
    return it->first;
}
