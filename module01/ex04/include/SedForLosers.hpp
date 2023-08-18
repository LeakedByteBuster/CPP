#ifndef SEDFORLOSERS_HPP
#define SEDFORLOSERS_HPP

#include <string>

# define HRED "\e[1;91m"
# define RESET "\x1b[0m"

class SedForLosers
{

private:
	std::string		filename;
	std::string		newFilename;
	std::string		oldStr;
	std::string		newStr;

public:
	// Constructor && Destructor
	SedForLosers(char *filename, char *oldStr, char *newStr);
	~SedForLosers();

	// Filename: Setter && Getter
	std::string    getFilename() const;
	void           setFilename(std::string filename);

	// oldStr: Setter && Getter
	std::string    getOldStr() const;
	void           setOldStr(std::string oldStr);

	// newStr: Setter && Getter
	std::string    getNewStr() const;
	void           setNewStr(std::string newStr);

	// newStr: Setter && Getter
	std::string    getNewFilename() const;
	void           setNewFilename(std::string newFilename);
};

#endif // SEDFORLOSERS_HPP
