    t->page_faults = c->page_faults - p->page_faults;
    t->select_loops = c->select_loops - p->select_loops;
    t->cputime = c->cputime - p->cputime;
    NDeltas++;
}

void
statAvgDump(StoreEntry * sentry)
{
    int i;
    int N = NDeltas > N_DELTAS ? N_DELTAS : NDeltas;
    StatCounters A;
    StatCounters *c;
    memset(&A, '\0', sizeof(StatCounters));
    for (i = 0; i < N; i++) {
	c = &Deltas[i];
	A.client_http.requests += c->client_http.requests;
	A.client_http.hits += c->client_http.hits;
	A.client_http.errors += c->client_http.errors;
	A.client_http.bytes_in += c->client_http.bytes_in;
	A.client_http.bytes_out += c->client_http.bytes_out;
	A.icp.pkts_sent += c->icp.pkts_sent;
	A.icp.pkts_recv += c->icp.pkts_recv;
	A.icp.bytes_sent += c->icp.bytes_sent;
	A.icp.bytes_recv += c->icp.bytes_recv;
	A.unlink.requests += c->unlink.requests;
	A.page_faults += c->page_faults;
	A.select_loops += c->select_loops;
	A.cputime += c->cputime;
    }
    if (N) {
	A.client_http.requests /= N;
	A.client_http.hits /= N;
	A.client_http.errors /= N;
	A.client_http.bytes_in /= N;
	A.client_http.bytes_out /= N;
	A.icp.pkts_sent /= N;
	A.icp.pkts_recv /= N;
	A.icp.bytes_sent /= N;
	A.icp.bytes_recv /= N;
	A.unlink.requests /= N;
	A.page_faults /= N;
	A.select_loops /= N;
	A.cputime /= N;
    }
    EBIT_SET(sentry->flag, DELAY_SENDING);
    storeAppendPrintf(sentry, "client_http.requests = %d\n", A.client_http.requests);
    storeAppendPrintf(sentry, "client_http.hits = %d\n", A.client_http.hits);
    storeAppendPrintf(sentry, "client_http.errors = %d\n", A.client_http.errors);
    storeAppendPrintf(sentry, "client_http.bytes_in = %d\n", A.client_http.bytes_in);
    storeAppendPrintf(sentry, "client_http.bytes_out = %d\n", A.client_http.bytes_out);
    storeAppendPrintf(sentry, "icp.pkts_sent = %d\n", A.icp.pkts_sent);
    storeAppendPrintf(sentry, "icp.pkts_recv = %d\n", A.icp.pkts_recv);
    storeAppendPrintf(sentry, "icp.bytes_sent = %d\n", A.icp.bytes_sent);
    storeAppendPrintf(sentry, "icp.bytes_recv = %d\n", A.icp.bytes_recv);
    storeAppendPrintf(sentry, "unlink.requests = %d\n", A.unlink.requests);
    storeAppendPrintf(sentry, "page_faults = %d\n", A.page_faults);
    storeAppendPrintf(sentry, "select_loops = %d\n", A.select_loops);
    EBIT_CLR(sentry->flag, DELAY_SENDING);
    storeAppendPrintf(sentry, "cputime = %f seconds\n", A.cputime);
}