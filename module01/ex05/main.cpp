#include "Harl.hpp"
#include <iostream>

int main()
{
    //  Instantiate a Harl object
    Harl    msg;

    /* Check Normal Cases */
    msg.complain("debug");
    msg.complain("info");
    msg.complain("warning");
    msg.complain("error");

    /* Check Error Case */
    msg.complain("Testerror");

    return (0);
}