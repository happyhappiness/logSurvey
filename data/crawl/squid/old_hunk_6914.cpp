fqdncacheAddNew(const char *name, const struct hostent *hp, fqdncache_status_t status)
{
    fqdncache_entry *f;
    if (fqdncache_get(name))
	fatal_dump("fqdncacheAddNew: somebody adding a duplicate!");
    debug(14, 10) ("fqdncacheAddNew: Adding '%s', status=%c\n",
	name,
	fqdncache_status_char[status]);
