#include "squid.h"
#include "helpers/defines.h"

#include <iostream>
#include <string>

/**
 * options:
 * -d enable debugging.
 * -h interface help.
 */
std::string program_name;

static void
usage(void)
{
    std::cerr <<
            "Usage: " << program_name << " [-d] [-h]" << std::endl <<
            " -d  enable debugging." << std::endl <<
            " -h  this message" << std::endl << std::endl;
}

static void
