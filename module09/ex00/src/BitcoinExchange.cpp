#include <sstream>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(std::string in)
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
        for (int i = 0; std::getline(ss, token, ','); i++) {
            if (i == 1) {
                db.insert(std::make_pair(prev, std::strtod(token.data(), NULL)));
            }
            prev = token;
        }
    }
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange )
{
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    
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

inline DataBase&      BitcoinExchange::setDb() {
    return (this->db);
}
