	return entry ? entry->refs : NULL;
}

/*
 * Create, record, and return a ref_store instance for the specified
 * submodule (or the main repository if submodule is NULL).
