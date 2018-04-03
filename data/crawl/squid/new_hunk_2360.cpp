    storeAppendPrintf(entry, "%s %d %s\n", name, (int) var, B_BYTES_STR);
}

#if !USE_DNSHELPER
static void
dump_b_ssize_t(StoreEntry * entry, const char *name, ssize_t var)
{
