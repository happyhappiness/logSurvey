#include "builtin.h"
#include "parse-options.h"

static unsigned long garbage;

static void real_report_garbage(const char *desc, const char *path)
{
	warning("%s: %s", desc, path);
	garbage++;
}

static void count_objects(DIR *d, char *path, int len, int verbose,
			  unsigned long *loose,
			  off_t *loose_size,
