#if !defined(BITCOINEXCHANGE_HPP)
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <utility>
#include <exception>
#include <cstdlib>
#include "utils.hpp"

#if !defined(DATA_FILE)
#define DATA_FILE "./cpp_09/data.csv"
#endif  // DATA_FILE

typedef std::map<std::string, double> DataBase;

enum    BeErrors {
    TOO_LARGE_NUMBER,
    BAD_INPUT,
    NOT_A_POSITIVE
};

class   BitcoinExchange {
public :

    std::ifstream   dataFile;
    std::ifstream   inputFile;

    BitcoinExchange();
    BitcoinExchange(const char *in);
    BitcoinExchange &operator=(BitcoinExchange rhs);
    ~BitcoinExchange();

    const DataBase & getDb() const;
    DataBase&       setDb();

    void            readInputFile();
    static std::string  getError(std::string e, int type);

private :
    DataBase    db;
};

std::ostream&  operator<<(std::ostream &os, const BitcoinExchange &b);

#endif // BITCOINEXCHANGE_HPP