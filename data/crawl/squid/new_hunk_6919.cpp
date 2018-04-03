static void
serverConnectionsOpen(void)
{
    clientHttpConnectionsOpen();
    icpConnectionsOpen();
#ifdef SQUID_SNMP
    snmpConnectionOpen();
#endif
    clientdbInit();
    icmpOpen();
    netdbInit();
