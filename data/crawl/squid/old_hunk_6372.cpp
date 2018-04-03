    swap->n_configured = 0;
}

static void
dump_peer(StoreEntry * entry, const char *name, peer * p)
{
    while (p != NULL) {
	storeAppendPrintf(entry, "%s %s %s %d %d",
	    name,
