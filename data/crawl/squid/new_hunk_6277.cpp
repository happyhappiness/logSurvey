fqdncache_restart(void)
{
    fqdncache_entry *this;
    assert(fqdn_table);
    while (fqdncacheDequeue());
    hash_first(fqdn_table);
    while ((this = (fqdncache_entry *) hash_next(fqdn_table))) {