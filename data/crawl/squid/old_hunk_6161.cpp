    memset(addr, '\0', sizeof(struct in_addr));
}

static void
dump_http_header(StoreEntry * entry, const char *name, HttpHeaderMask header)
{
