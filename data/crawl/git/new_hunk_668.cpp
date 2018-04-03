}

/*
 * Associate a ref store with a name. It is a fatal error to call this
 * function twice for the same name.
 */
static void register_ref_store_map(struct hashmap *map,
				   const char *type,
				   struct ref_store *refs,
				   const char *name)
{
	if (!map->tablesize)
		hashmap_init(map, ref_store_hash_cmp, 0);

	if (hashmap_put(map, alloc_ref_store_hash_entry(name, refs)))
		die("BUG: %s ref_store '%s' initialized twice", type, name);
}

struct ref_store *get_submodule_ref_store(const char *submodule)