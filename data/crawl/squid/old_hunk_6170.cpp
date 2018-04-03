    memset(addr, '\0', sizeof(struct in_addr));
}

static void
dump_cachedir(StoreEntry * entry, const char *name, cacheSwap swap)
{
