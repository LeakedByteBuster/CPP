#include "SedForLosers.hpp"
#include <iostream>

// Filename: Setter && Getter
std::string    SedForLosers::getFilename() const
{
    return (this->filename);
}

void           SedForLosers::setFilename(std::string filename)
{
    this->filename = filename;
}

// oldStr: Setter && Getter
std::string    SedForLosers::getOldStr() const
{
    return (this->oldStr);
}

void           SedForLosers::setOldStr(std::string oldStr)
{
    this->oldStr = oldStr;
}

// newStr: Setter && Getter
std::string    SedForLosers::getNewStr() const
{
    return (this->newStr);
}

void           SedForLosers::setNewStr(std::string newStr)
{
    this->newStr = newStr;
}

// newStr: Setter && Getter
std::string    SedForLosers::getNewFilename() const
{
    return (this->newFilename);
}

void           SedForLosers::setNewFilename(std::string newFilename)
{

    this->newFilename = newFilename.append(".replace");
}

SedForLosers::SedForLosers(char *filename, char *oldStr, char *newStr)
{
    setFilename(filename);
    setOldStr(oldStr);
    setNewStr(newStr);

    // getNewStr().empty()? replace with an empty string
    if (getFilename().empty() || getOldStr().empty())
    {	
        std::cerr << HRED << "Error: empty string\n" << RESET;
		exit(1);
    }

    return ;
}

SedForLosers::~SedForLosers()
{
    return ;
}
