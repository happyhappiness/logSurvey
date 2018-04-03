#define dump_eol dump_string
#define free_eol free_string

static void
dump_snmp_conf(StoreEntry * entry, const char *name, snmpconf * head)
{
    storeAppendPrintf(entry, "%s -- UNIMPLEMENTED\n", name);
}

static void
dump_refreshpattern(StoreEntry * entry, const char *name, refresh_t * head)
{
