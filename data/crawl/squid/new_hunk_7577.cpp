     StoreEntry *e;
{
    hash_link *hptr = hash_lookup(in_mem_table, e->key);
    if (hptr == NULL) {
	debug_trap("storeHashMemDelete: key not found");
	return;
    }
    hash_delete_link(in_mem_table, hptr);
    meta_data.hot_vm--;
}
