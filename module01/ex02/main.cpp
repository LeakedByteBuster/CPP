#include <string>
#include <iostream>

int main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	// Prints str's address: get address with '&'
	std::cout << &str << "\n";
	// Prints (*stringPTR)'s address
	std::cout << stringPTR << "\n";
	// Prints (&stringREF)'s address
	std::cout << &stringREF << "\n";

	// Prints str
	std::cout << str << "\n";
	// Prints (*stringPTR): dereference with '*'
	std::cout << *stringPTR << "\n";
	// Prints (&stringREF):
	std::cout << stringREF << "\n"; 

	return (0);
}
