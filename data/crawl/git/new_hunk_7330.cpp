#include "progress.h"
#include "refs.h"

static inline void remove_entry(int remove)
{
	if (remove >= 0)
		remove_cache_entry_at(remove);
}

/* Unlink the last component and attempt to remove leading
 * directories, in case this unlink is the removal of the
 * last entry in the directory -- empty directories are removed.
