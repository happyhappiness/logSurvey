#include "exec_cmd.h"

static const char *pgm;
static int one_shot, quiet;
static int err;

static int merge_entry(int pos, const char *path)
{
	int found;
	const char *arguments[] = { pgm, "", "", "", path, "", "", "", NULL };
	char hexbuf[4][60];
	char ownbuf[4][60];

	if (pos >= active_nr)
		die("git merge-index: %s not in the cache", path);
	found = 0;
	do {
		struct cache_entry *ce = active_cache[pos];
		int stage = ce_stage(ce);

