static void
put_free_thing(stmem_stats * thing, void *p)
{
    assert(p != NULL);
    thing->n_pages_in_use--;
    if (thing->total_pages_allocated > thing->max_pages) {
	xfree(p);
