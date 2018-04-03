#define free_kb_int64_t free_b_int64_t

static void
dump_u_short(StoreEntry * entry, const char *name, u_short var)
{
    storeAppendPrintf(entry, "%s %d\n", name, var);
}

static void
free_u_short(u_short * u)
{
    *u = 0;
}

static void
parse_u_short(u_short * var)
{
    ConfigParser::ParseUShort(var);
}
