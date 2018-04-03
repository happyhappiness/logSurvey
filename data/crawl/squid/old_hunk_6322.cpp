};

static PF dnsShutdownRead;
static dnsserver_t **dns_child_table = NULL;

dnsserver_t *
dnsGetFirstAvailable(void)
