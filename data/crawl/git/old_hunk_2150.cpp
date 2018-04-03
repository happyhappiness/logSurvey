#include "submodule-config.h"
#include "string-list.h"
#include "run-command.h"

struct module_list {
	const struct cache_entry **entries;
