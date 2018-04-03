    return f;
}

static fqdncache_entry *
fqdncache_GetFirst()
{
    return (fqdncache_entry *) hash_first(fqdn_table);
}

static fqdncache_entry *
fqdncache_GetNext()
{
    return (fqdncache_entry *) hash_next(fqdn_table);
}

static int
fqdncache_compareLastRef(fqdncache_entry ** e1, fqdncache_entry ** e2)
{
    if (!e1 || !e2)
	fatal_dump(NULL);
