    /* NOTREACHED */
}

static int
get_nlines(void)
{
	if (interactive)
		return getmaxy(w) - 6;
	else
		return 50;
}

static void
StringCounter_report(StringCounter * list, char *what)
{
    StringCounter *sc;
    int nlines = get_nlines();
    print_func("%-30s %9s %6s\n", what, "count", "%");
    print_func("%-30s %9s %6s\n",
	"------------------------------", "---------", "------");
    for (sc = list; sc; sc = sc->next) {
	print_func("%-30.30s %9d %6.1f\n",
	    sc->s,
	    sc->count,
	    100.0 * sc->count / query_count_total);
	if (0 == --nlines)
	    break;
    }
}

static void
StringCounter_free(StringCounter ** headP)
{
    StringCounter *sc;
    void *next;
    for (sc = *headP; sc; sc = next) {
	next = sc->next;
	free(sc->s);
	free(sc);
    }
    *headP = NULL;
}

static void
StringAddrCounter_free(StringAddrCounter ** headP)
{
    StringAddrCounter *ssc;
    void *next;
    for (ssc = *headP; ssc; ssc = next) {
	next = ssc->next;
	free(ssc->str);
	free(ssc);
    }
    *headP = NULL;
}

static void
Tld_report(void)
{
    StringCounter_report(Tlds, "TLD");
}

static void
Sld_report(void)
{
    if (0 == sld_flag) {
	print_func("\tYou must start %s with the -s option\n", progname);
	print_func("\tto collect 2nd level domain stats.\n", progname);
    } else {
	StringCounter_report(Slds, "SLD");
    }
}

static void
Nld_report(void)
{
    if (0 == nld_flag) {
	print_func("\tYou must start %s with the -t option\n", progname);
	print_func("\tto collect 3nd level domain stats.\n", progname);
    } else {
	StringCounter_report(Nlds, "3LD");
    }
}

static void
Qtypes_report(void)
{
    int type;
    int nlines = get_nlines();
    print_func("%-10s %9s %6s\n", "Query Type", "count", "%");
    print_func("%-10s %9s %6s\n", "----------", "---------", "------");
    for (type = 0; type < T_MAX; type++) {
	if (0 == qtype_counts[type])
	    continue;
	print_func("%-10s %9d %6.1f\n",
	    qtype_str(type),
	    qtype_counts[type],
	    100.0 * qtype_counts[type] / query_count_total);
	if (0 == --nlines)
	    break;
    }
}

static void
Opcodes_report(void)
{
    int op;
    int nlines = get_nlines();
    print_func("%-10s %9s %6s\n", "Opcode    ", "count", "%");
    print_func("%-10s %9s %6s\n", "----------", "---------", "------");
    for (op = 0; op < OP_MAX; op++) {
	if (0 == opcode_counts[op])
	    continue;
	print_func("%-10s %9d %6.1f\n",
	    opcode_str(op),
	    opcode_counts[op],
	    100.0 * opcode_counts[op] / query_count_total);
	if (0 == --nlines)
	    break;
    }
}

static void
AgentAddr_report(AgentAddr * list, const char *what)
{
    AgentAddr *agent;
    int nlines = get_nlines();
    print_func("%-16s %9s %6s\n", what, "count", "%");
    print_func("%-16s %9s %6s\n", "----------------", "---------", "------");
    for (agent = list; agent; agent = agent->next) {
	print_func("%-16s %9d %6.1f\n",
	    anon_inet_ntoa(agent->src),
	    agent->count,
	    100.0 * agent->count / query_count_total);
	if (0 == --nlines)
	    break;
    }
}

static void
Combo_report(StringAddrCounter * list, char *what1, char *what2)
{
    StringAddrCounter *ssc;
    int nlines = get_nlines();
    print_func("%-16s %-32s %9s %6s\n", what1, what2, "count", "%");
    print_func("%-16s %-32s %9s %6s\n",
	"----------------", "--------------------", "---------", "------");
    for (ssc = list; ssc; ssc = ssc->next) {
	print_func("%-16s %-32s %9d %6.1f\n",
	    anon_inet_ntoa(ssc->src),
	    ssc->str,
	    ssc->count,
	    100.0 * ssc->count / query_count_total);
	if (0 == --nlines)
	    break;
    }
}

static void
SldBySource_report(void)
{
    if (0 == sld_flag) {
	print_func("\tYou must start %s with the -s option\n", progname);
	print_func("\tto collect 2nd level domain stats.\n", progname);
    } else {
	Combo_report(SSC2, "Source", "SLD");
    }
}

static void
NldBySource_report(void)
{
    if (0 == nld_flag) {
	print_func("\tYou must start %s with the -t option\n", progname);
	print_func("\tto collect 3nd level domain stats.\n", progname);
    } else {
	Combo_report(SSC3, "Source", "3LD");
    }
}


static void
AgentAddr_free(AgentAddr ** headP)
{
    AgentAddr *aa;
    void *next;
    for (aa = *headP; aa; aa = next) {
	next = aa->next;
	free(aa);
    }
    *headP = NULL;
}

static void
Sources_report(void)
{
    AgentAddr_report(Sources, "Sources");
}

static void
Destinatioreport(void)
{
    AgentAddr_report(Destinations, "Destinations");
}

static void
report(void)
{
    move(0, 0);
    print_func("%d new queries, %d total queries",
	query_count_intvl, query_count_total);
    clrtoeol();
    if (last_ts.tv_sec) {
	time_t t = (time_t) last_ts.tv_sec;
	move(0, 50);
	print_func("%s", ctime(&t));
    }
    move(2, 0);
    clrtobot();
    if (SubReport)
	SubReport();
    refresh();
}

/*
 * === BEGIN FILTERS ==========================================================
 */

#include "known_tlds.h"

static int
UnknownTldFilter(unsigned short qt, unsigned short qc, const char *qn, const struct in_addr sip, const struct in_addr dip)
{
    const char *tld = QnameToNld(qn, 1);
    unsigned int i;
    if (NULL == tld)
	return 1;		/* tld is unknown */
    for (i = 0; KnownTLDS[i]; i++)
	if (0 == strcmp(KnownTLDS[i], tld))
	    return 0;		/* tld is known */
    return 1;			/* tld is unknown */
}

static int
AforAFilter(unsigned short qt, unsigned short qc, const char *qn, const struct in_addr sip, const struct in_addr dip)
{
    struct in_addr a;
    if (qt != T_A)
	return 0;  
    return inet_aton(qn, &a);
}

static int
RFC1918PtrFilter(unsigned short qt, unsigned short qc, const char *qn, const struct in_addr sip, const struct in_addr dip)
{
    char *t;
    char q[128];   
    unsigned int i = 0;
    if (qt != T_PTR)
	return 0;  
    strncpy(q, qn, sizeof(q)-1);
    q[sizeof(q)-1] = '\0';
    t = strstr(q, ".in-addr.arpa");
    if (NULL == t)
	return 0;
    *t = '\0';
    for (t = strtok(q, "."); t; t = strtok(NULL, ".")) {
	i >>= 8;
	i |= ((atoi(t) & 0xff) << 24);
    }
    if ((i & 0xff000000) == 0x0a000000)
	return 1;
    if ((i & 0xfff00000) == 0xac100000)
	return 1;
    if ((i & 0xffff0000) == 0xc0a80000)
	return 1;
    return 0;
}

static void
set_filter(const char *fn)
{
	if (0 == strcmp(fn, "unknown-tlds"))
		Filter = UnknownTldFilter;
	else if (0 == strcmp(fn, "A-for-A"))
		Filter = AforAFilter;
	else if (0 == strcmp(fn, "rfc1918-ptr"))
		Filter = RFC1918PtrFilter;
	else
		Filter = NULL;
}

/*
 * === END FILTERS ==========================================================
 */

static void
init_curses(void)
{
    w = initscr();
    cbreak();
    noecho();
    nodelay(w, 1);
}

static void
ResetCounters(void)
{
    query_count_intvl = 0;
    query_count_total = 0;
    memset(qtype_counts, '\0', sizeof(qtype_counts));
    memset(qclass_counts, '\0', sizeof(qclass_counts));
    memset(opcode_counts, '\0', sizeof(opcode_counts));
    AgentAddr_free(&Sources);
    AgentAddr_free(&Destinations);
    StringCounter_free(&Tlds);
    StringCounter_free(&Slds);
    StringCounter_free(&Nlds);
    StringAddrCounter_free(&SSC2);
    StringAddrCounter_free(&SSC3);
    memset(&last_ts, '\0', sizeof(last_ts));
}

static void
usage(void)
{
    fprintf(stderr, "usage: %s [opts] netdevice|savefile\n",
	progname);
    fprintf(stderr, "\t-a\tAnonymize IP Addrs\n");
    fprintf(stderr, "\t-b expr\tBPF program code\n");
    fprintf(stderr, "\t-i addr\tIgnore this source IP address\n");
    fprintf(stderr, "\t-p\tDon't put interface in promiscuous mode\n");
    fprintf(stderr, "\t-s\tEnable 2nd level domain stats collection\n");
    fprintf(stderr, "\t-t\tEnable 3nd level domain stats collection\n");
    fprintf(stderr, "\t-f\tfilter-name\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "Available filters:\n");
    fprintf(stderr, "\tunknown-tlds\n");
    fprintf(stderr, "\tA-for-A\n");
    fprintf(stderr, "\trfc1918-ptr\n");
    exit(1);
}

static int
pcap_select(pcap_t * p, int sec, int usec)
{
    fd_set R;
    struct timeval to;
    FD_ZERO(&R);
    FD_SET(pcap_fileno(p), &R);
    to.tv_sec = sec;
    to.tv_usec = usec;
    return select(pcap_fileno(p) + 1, &R, NULL, NULL, &to);
}

#if 0
static int
main(int argc, char *argv[])
