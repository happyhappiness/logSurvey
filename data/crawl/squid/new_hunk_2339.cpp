#include "ConfigParser.h"
#include "wordlist.h"

#define STUB_API "cache_cf.cc"
#include "tests/STUB.h"

void self_destruct(void) STUB
void parse_int(int *var) STUB
void parse_onoff(int *var) STUB
void parse_eol(char *volatile *var) STUB
#if 0
{
    unsigned char *token = (unsigned char *) strtok(NULL, null_string);
    safe_free(*var);
