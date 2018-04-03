#include "ConfigParser.h"
#include "wordlist.h"

void
self_destruct(void)
{
    /*    fatalf("Bungled %s line %d: %s",
               cfg_filename, config_lineno, config_input_line);*/
    fatalf("bungled line");
}

void
parse_int(int *var)
{
    fatal("not implemented 1");
}

void
parse_onoff(int *var)
{
    fatal("not implemented 2");
}

void
parse_eol(char *volatile *var)
{
    unsigned char *token = (unsigned char *) strtok(NULL, null_string);
    safe_free(*var);
