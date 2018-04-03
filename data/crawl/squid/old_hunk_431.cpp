#include "squid.h"
#include "helpers/defines.h"

#include <cstring>

/**
 * options:
 * -d enable debugging.
 * -h interface help.
 */
char *program_name = NULL;

static void
usage(void)
{
    fprintf(stderr,
            "Usage: %s [-d] [-v] [-h]\n"
            " -d  enable debugging.\n"
            " -h  this message\n\n",
            program_name);
}

static void
