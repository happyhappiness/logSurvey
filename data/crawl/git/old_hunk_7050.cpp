#include "cache.h"
#include "pack.h"

static int verify_one_pack(const char *path, int verbose)
{
	char arg[PATH_MAX];
