#include <iostream>
#include <fstream>
#include "utils.hpp"
#include "SedForLosers.hpp"

static void	openInputFile(SedForLosers &input, std::ifstream &ifs)
{
	try {
		if (ifs){

			std::string str;
			input.setNewFilename(input.getFilename());

	} else {

		throw input.getFilename();

	  } 
	}
	catch (std::string filename)
	{
		std::cerr << HRED << "Error: cannot open file " << filename \
			<< RESET << "\n";
		ifs.close();
		exit(1);
	}

	return ;
}

static void	openOutputFile(SedForLosers &input, std::ifstream &ifs, std::ofstream &ofs)
{
	try {
		if (ofs){
			
			copyAndReplace(input, ifs, ofs);

	} else {

		throw input.getNewFilename();

	  } 
	}
	catch (std::string filename)
	{
		std::cerr << HRED << "Error: cannot open file: " << filename \
			<< RESET << "\n";
		ofs.close();
		ifs.close();
		exit(1);
	}

	return ;
}

int main(int ac, char **av)
{
	if (ac != 4){
		std::cerr << HRED << "Error: incorrect number of arguments:\n./sedForLosers" \
			<< " <filename> <stringToBeReplaced> <string 2>\n" << RESET;
		return (1);
	}

	SedForLosers   input(av[1], av[2], av[3]);

	std::ifstream   ifs(input.getFilename());
	openInputFile(input, ifs);

	std::ofstream   ofs(input.getNewFilename());
	openOutputFile(input, ifs, ofs);

    ofs.close();
    ifs.close();

	return (0);
}