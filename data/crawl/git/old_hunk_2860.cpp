#include "cache.h"

static FILE *error_handle;

void vreportf(const char *prefix, const char *err, va_list params)
{
	char msg[4096];
	FILE *fh = error_handle ? error_handle : stderr;
	vsnprintf(msg, sizeof(msg), err, params);
	fprintf(fh, "%s%s\n", prefix, msg);
}

static NORETURN void usage_builtin(const char *err, va_list params)
