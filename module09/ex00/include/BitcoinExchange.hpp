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

#define DATA_FILE "/Users/mfouadi/Desktop/42Cursus/CPP/module09/ex00/cpp_09/data.csv"

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