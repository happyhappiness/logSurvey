#include "git-compat-util.h"
#include "cache.h"

void vreportf(const char *prefix, const char *err, va_list params)
{
	char msg[4096];
