{
    ipcache_entry *this;
    ipcache_entry *next;
    assert(ip_table != NULL);
    while (ipcacheDequeue());
    next = (ipcache_entry *) hash_first(ip_table);
    while ((this = next)) {
