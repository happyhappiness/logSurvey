	add_index_entry(&o->result, new, ADD_CACHE_OK_TO_ADD|ADD_CACHE_OK_TO_REPLACE);
}

/*
 * Unlink the last component and schedule the leading directories for
 * removal, such that empty directories get removed.
