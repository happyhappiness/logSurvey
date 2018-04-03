fqdncacheAddNew(const char *name, const struct hostent *hp, fqdncache_status_t status)
{
    fqdncache_entry *f;
    assert(fqdncache_get(name) == NULL);
    debug(14, 10) ("fqdncacheAddNew: Adding '%s', status=%c\n",
	name,
	fqdncache_status_char[status]);
