	storeAppendPrintf(e, "\t%4d  %9d\n", i, server_pconn_hist[i]);
    }
}

void
statAvgInit(void)
{
    memset(Deltas, '\0', N_DELTAS * sizeof(StatCounters));
    eventAdd("statAvgTick", statAvgTick, NULL, 60);
}

static void
statAvgTick(void *notused)
{
    StatCounters *t = &Deltas[0];
    StatCounters *p = &Deltas[1];
    StatCounters *c = &Counter;
    struct rusage rusage;
    eventAdd("statAvgTick", statAvgTick, NULL, 60);
    memmove(p, t, (N_DELTAS - 1) * sizeof(StatCounters));
    t->client_http.requests = c->client_http.requests - p->client_http.requests;
    t->client_http.hits = c->client_http.hits - p->client_http.hits;
    t->client_http.errors = c->client_http.errors - p->client_http.errors;
    t->client_http.bytes_in = c->client_http.bytes_in - p->client_http.bytes_in;
    t->client_http.bytes_out = c->client_http.bytes_out - p->client_http.bytes_out;
    t->icp.pkts_sent = c->icp.pkts_sent - p->icp.pkts_sent;
    t->icp.pkts_recv = c->icp.pkts_recv - p->icp.pkts_recv;
    t->icp.bytes_sent = c->icp.bytes_sent - p->icp.bytes_sent;
    t->icp.bytes_recv = c->icp.bytes_recv - p->icp.bytes_recv;
    t->unlink.requests = c->unlink.requests - p->unlink.requests;
    t->page_faults = c->page_faults - p->page_faults;
    t->select_loops = c->select_loops - p->select_loops;
    t->cputime = c->cputime - p->cputime;
    squid_getrusage(&rusage);
    c->page_faults = rusage_pagefaults(&rusage);
    c->cputime = rusage_cputime(&rusage);
}
