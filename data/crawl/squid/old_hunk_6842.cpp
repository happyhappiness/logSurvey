	(int) sizeof(hash_link),
	(int) (hash_links_allocated * sizeof(hash_link) >> 10));

    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
	"NetDB Address Entries",
	meta_data.netdb_addrs,
	(int) sizeof(netdbEntry),
	(int) (meta_data.netdb_addrs * sizeof(netdbEntry) >> 10));

    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
	"NetDB Host Entries",
	meta_data.netdb_hosts,
	(int) sizeof(struct _net_db_name),
	             (int) (meta_data.netdb_hosts * sizeof(struct _net_db_name) >> 10));

    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
	"NetDB Peer Entries",
	meta_data.netdb_peers,