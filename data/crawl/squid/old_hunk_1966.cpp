}

#include "ConfigParser.h"
void
ConfigParser::destruct()
{
// CALLED as shutdown no-op
//    fatal("ConfigParser::destruct. Not implemented.");
}

void
eventAdd(const char *name, EVH * func, void *arg, double when, int, bool cbdata)