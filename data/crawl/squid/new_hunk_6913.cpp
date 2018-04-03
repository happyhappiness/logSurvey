static void
fqdncache_release(fqdncache_entry * f)
{
    int k;
    assert(f->status != FQDN_PENDING);
    assert(f->status != FQDN_DISPATCHED);
    assert(f->pending_head == NULL);
    if (hash_remove_link(fqdn_table, (hash_link *) f)) {
	debug(35, 0) ("fqdncache_release: hash_remove_link() failed for '%s'\n",
	    f->name);
	return;
