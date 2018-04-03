#include "git-compat-util.h"
#include "cache.h"

static int dying;

void vreportf(const char *prefix, const char *err, va_list params)
{
	char msg[4096];
