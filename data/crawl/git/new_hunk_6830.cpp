#include "cache.h"
#include "commit.h"
#include "tag.h"
#include "merge-recursive.h"

static const char *better_branch_name(const char *branch)
{
	static char githead_env[8 + 40 + 1];
