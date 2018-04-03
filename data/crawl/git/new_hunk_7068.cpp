#include "parse-options.h"

static int boolean = 0;
static unsigned long integer = 0;
static int abbrev = 7;
static int verbose = 0, dry_run = 0, quiet = 0;
static char *string = NULL;

int length_callback(const struct option *opt, const char *arg, int unset)
{
	printf("Callback: \"%s\", %d\n",
		(arg ? arg : "not set"), unset);
	if (unset)
		return 1; /* do not support unset */

	*(unsigned long *)opt->value = strlen(arg);
	return 0;
}

int main(int argc, const char **argv)
{
	const char *usage[] = {
