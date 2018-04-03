	(int) sizeof(struct _net_db_name),
	             (int) (meta_data.netdb_hosts * sizeof(struct _net_db_name) >> 10));

    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
	"NetDB Peer Entries",
	meta_data.netdb_peers,
	(int) sizeof(struct _net_db_peer),
	             (int) (meta_data.netdb_peers * sizeof(struct _net_db_peer) >> 10));

    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
	"ClientDB Entries",
	meta_data.client_info,
