    storeAppendPrintf(entry, "%s -- UNIMPLEMENTED\n", name);
}

#if SQUID_SNMP
static void
parse_snmp_conf(snmpconf ** s)
{
