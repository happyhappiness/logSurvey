#include "cache.h"
#include "refs.h"
#include "object.h"
#include "parse-options.h"
#include "ref-filter.h"

static char const * const for_each_ref_usage[] = {
	N_("git for-each-ref [<options>] [<pattern>]"),
	NULL
