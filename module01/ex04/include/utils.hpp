#ifndef UTILS_HPP
#define UTILS_HPP

#include <fstream>
#include "SedForLosers.hpp"

void    copyAndReplace(SedForLosers &input, std::ifstream &ifs, std::ofstream &ofs);

#endif // UTILS_HPP