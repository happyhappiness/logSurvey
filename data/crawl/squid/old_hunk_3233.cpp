
#endif /* USE_SSL */


static void
clientHttpConnectionsOpen(void)
{
    http_port_list *s = NULL;
    int fd = -1;
#if USE_SSL
    int bumpCount = 0; // counts http_ports with sslBump option
#endif
