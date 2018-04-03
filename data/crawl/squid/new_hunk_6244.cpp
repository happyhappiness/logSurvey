
#include "squid.h"

static helper *dnsservers = NULL;

static void
dnsStats(StoreEntry * sentry)
{
    storeAppendPrintf(sentry, "Dnsserver Statistics:\n");
    helperStats(sentry, dnsservers);
}

void
dnsInit(void)
{
    static int init = 0;
    wordlist *w;
    safe_free(dnsservers);
    if (!Config.Program.dnsserver)
	return;
    dnsservers = xcalloc(1, sizeof(*dnsservers));
    dnsservers->id_name = "dnsor";
    dnsservers->n_to_start = Config.dnsChildren;
    dnsservers->ipc_type = IPC_TCP_SOCKET;
    wordlistAdd(&dnsservers->cmdline, Config.Program.dnsserver);
    if (Config.onoff.res_defnames)
	wordlistAdd(&dnsservers->cmdline, "-D");
    if (Config.dns_nameservers) {
	wordlistAdd(&dnsservers->cmdline, "-s");
	for (w = Config.dns_nameservers; w != NULL; w = w->next)
	    wordlistAdd(&dnsservers->cmdline, w->key);
    }
    helperOpenServers(dnsservers);
    if (!init) {
	cachemgrRegister("dns",
	    "Dnsserver Statistics",
	    dnsStats, 0, 1);
    }
    init++;
}

void
dnsShutdown(void)
{
    if (!dnsservers)
	return;
    helperShutdown(dnsservers);
    wordlistDestroy(&dnsservers->cmdline);
}

void
dnsSubmit(const char *lookup, HLPCB * callback, void *data)
{
    char buf[256];
    snprintf(buf, 256, "%s\n", lookup);
    helperSubmit(dnsservers, buf, callback, data);
}

#ifdef SQUID_SNMP
/*
 * The function to return the DNS via SNMP
 */
variable_list *
snmp_netDnsFn(variable_list * Var, snint * ErrP)
{
    variable_list *Answer;
    debug(49, 5) ("snmp_netDnsFn: Processing request:\n", Var->name[LEN_SQ_NET +
	    1]);
    snmpDebugOid(5, Var->name, Var->name_length);
    Answer = snmp_var_new(Var->name, Var->name_length);
    *ErrP = SNMP_ERR_NOERROR;
    Answer->val_len = sizeof(snint);
    Answer->val.integer = xmalloc(Answer->val_len);
    Answer->type = SMI_COUNTER32;
    switch (Var->name[LEN_SQ_NET + 1]) {
    case DNS_REQ:
	*(Answer->val.integer) = dnsservers->stats.requests;
	break;
    case DNS_REP:
	*(Answer->val.integer) = dnsservers->stats.replies;
	break;
    case DNS_SERVERS:
	*(Answer->val.integer) = dnsservers->n_running;
	break;
    default:
	*ErrP = SNMP_ERR_NOSUCHNAME;
