#if !defined(BITCOINEXCHANGE_HPP)
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <exception>

#define DATA_FILE "/Users/mfouadi/Desktop/42Cursus/CPP/module09/ex00/cpp_09/data.csv"

typedef std::map<std::string, double> DataBase;
typedef std::map<std::string, double> Input;

class   BitcoinExchange {
public :
    BitcoinExchange();
    BitcoinExchange(std::string input);
    BitcoinExchange &operator=(BitcoinExchange rhs);
    ~BitcoinExchange();

    const DataBase & getDb() const;
    inline DataBase&       setDb();

    Input           input;
    std::ifstream   dataFile;
    std::ifstream   inputFile;

private :
    DataBase    db;
};

std::ostream&  operator<<(std::ostream &os, const BitcoinExchange &b);
#endif // BITCOINEXCHANGE_HPP