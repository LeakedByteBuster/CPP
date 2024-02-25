#include <sstream>
#include <iomanip>      // std::setprecision
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const char *in)
{   
    dataFile.open(DATA_FILE);
    if (!dataFile.is_open()) {
        throw std::invalid_argument("Error: invalid database file");
    }
    inputFile.open(in);
    if (!inputFile.is_open()) {
        throw std::invalid_argument("Error: invalid input file");
    }

    std::string token;
    std::string prev;
    std::string line;

    //  Skip first line
    std::getline(dataFile, line, '\n');

    while (std::getline(dataFile, line)) {
        std::stringstream   ss(line);
        if (!line.empty()) {
            for (int i = 0; std::getline(ss, token, ','); i++) {
                if (i == 1) {
                    db[prev] = std::strtod(token.data(), NULL);
                }
                prev = token;
            }
        }
    }
    if (db.size() == 0)
        throw std::invalid_argument("Error: empty data map");
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange )
{
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    if (inputFile.is_open())
        inputFile.close();
    if (dataFile.is_open())
        dataFile.close();
}

std::ostream&  operator<<(std::ostream &os, const BitcoinExchange &b)
{
    DataBase::const_iterator  it = b.getDb().begin();
    for (; it != b.getDb().end(); it++) {

        os << it->first << " ";
        os << it->second << "\n";
    }
    return (os);
}

const DataBase &   BitcoinExchange::getDb() const {
    return (this->db);
}

DataBase&      BitcoinExchange::setDb() {
    return (this->db);
}

void    BitcoinExchange::readInputFile()
{
    std::string line;
    std::getline(inputFile, line);
    if (line.compare("date | value"))
        std::cout <<  BitcoinExchange::getError(line, BAD_INPUT) << std::endl;
    while (std::getline(inputFile, line)) {

        size_t  n = std::count(line.begin(), line.end(), '|');
        size_t n2 = std::count(line.begin(), line.end(), ' ');
        if ((n != 1) || (n2 != 2)) {
            std::cout << BitcoinExchange::getError(line, BAD_INPUT) << std::endl;
            continue ;
        }

        size_t  pos = line.find('|');
        std::string date = line.substr(0, pos);

        /* Check numbers of '-' in substring "date"*/
        n = std::count(date.begin(), date.end(), '-');
        if (n != 2 || !isDateCorrect(date) ){
            std::cout << BitcoinExchange::getError(line, BAD_INPUT) << std::endl;
            continue ;
        }
        std::string value = line.substr(pos +1, line.size());
        if (!isValueCorrect(value)) {
            continue ;
        }
        DataBase::iterator  it = db.lower_bound(date);
        if (it != db.begin()) { it--; }
        // if (it->first.compare(date) > 0) {
        //     std::cout << BitcoinExchange::getError(line, BAD_INPUT) << std::endl;
        //     continue ;
        // }
        std::cout   << std::fixed << std::setprecision(2) << date << " ==> " << value << " = " 
                    << it->second * std::strtod(value.data(), NULL) 
                    << std::endl;
    }
    return ;
}

std::string BitcoinExchange::getError(std::string e, int type)
{
    std::string s;

    switch (type)
    {
    case TOO_LARGE_NUMBER:
        s = "Error: too large a number.";
        break;
    
    case BAD_INPUT:
        s = "Error: bad input ➤  " + e;
        break;

    case NOT_A_POSITIVE:
        s = "Error: not a positive number.";
        break;
    }
    return (s);
}
