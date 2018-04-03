     stmem_stats *thing;
     void *p;
{
    thing->n_pages_in_use--;
    if (thing->total_pages_allocated > thing->max_pages) {
	xfree(p);