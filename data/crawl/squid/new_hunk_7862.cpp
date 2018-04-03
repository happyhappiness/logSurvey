}


void ipcacheOpenServers()
{
    int N = getDnsChildren();
    char *prg = getDnsProgram();
    int i;
    int dnssocket;
    static char fd_note_buf[FD_ASCII_NOTE_SZ];

    if (mkdir("dns", 0755) < 0 && errno != EEXIST)
	debug(14, 0, "ipcacheOpenServers: mkdir %s\n", xstrerror());

    /* start up companion process */
    safe_free(dns_child_table);
    dns_child_table = (dnsserver_entry **) xcalloc(N, sizeof(dnsserver_entry));
    dns_child_alive = 0;
    debug(14, 1, "ipcache_init: Starting %d 'dns_server' processes\n", N);
    for (i = 0; i < N; i++) {
	dns_child_table[i] = (dnsserver_entry *) xcalloc(1, sizeof(dnsserver_entry));
	if ((dnssocket = ipcache_create_dnsserver(prg)) < 0) {
	    debug(14, 1, "ipcache_init: WARNING: Cannot run 'dnsserver' process.\n");
	    debug(14, 1, "              Fallling back to the blocking version.\n");
	    dns_child_table[i]->alive = 0;
