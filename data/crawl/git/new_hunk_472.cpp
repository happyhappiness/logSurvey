#include "git-compat-util.h"
#include "cache.h"

void vreportf(const char *prefix, const char *err, va_list params)
{
	char msg[4096];
	char *p;

	vsnprintf(msg, sizeof(msg), err, params);
	for (p = msg; *p; p++) {
		if (iscntrl(*p) && *p != '\t' && *p != '\n')
			*p = '?';
	}
	fprintf(stderr, "%s%s\n", prefix, msg);
}

static NORETURN void usage_builtin(const char *err, va_list params)
