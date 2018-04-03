    c->page_faults = rusage_pagefaults(&rusage);
    c->cputime = rusage_cputime(&rusage);
    c->timestamp = current_time;
    xmemmove(p, t, (N_COUNT_HIST - 1) * sizeof(StatCounters));
    memcpy(t, c, sizeof(StatCounters));
    NCountHist++;
}

void
statCounters(StoreEntry * e)
{
    statCountersDump(e);
}

void
statAvg5min(StoreEntry * e)
{
    statAvgDump(e, 5);
}

void
statAvg60min(StoreEntry * e)
{
    statAvgDump(e, 60);
}

void
statLogHistInit(StatLogHist * H, double min, double max)
{
    H->min = min;
    H->max = max;
    H->scale = (STAT_LOG_HIST_BINS - 1) / log(1.0 + max - min);
}

void
statLogHistCount(StatLogHist * H, double val)
{
    int bin = statLogHistBin(H, val);
    assert(H->scale != 0.0);	/* make sure it got initialized */
    assert(0 <= bin && bin < STAT_LOG_HIST_BINS);
    H->bins[bin]++;
}

double
statLogHistDeltaMedian(StatLogHist * A, StatLogHist * B)
{
    StatLogHist D;
    int i;
    int s1 = 0;
    int h = 0;
    int a = 0;
    int b = 0;
    int I = 0;
    int J = STAT_LOG_HIST_BINS;
    int K;
    double f;
    memset(&D, '\0', sizeof(StatLogHist));
    for (i = 0; i < STAT_LOG_HIST_BINS; i++) {
	assert(B->bins[i] >= A->bins[i]);
	D.bins[i] = B->bins[i] - A->bins[i];
    }
    for (i = 0; i < STAT_LOG_HIST_BINS; i++)
	s1 += D.bins[i];
    h = s1 >> 1;
    for (i = 0; i < STAT_LOG_HIST_BINS; i++) {
	J = i;
	b += D.bins[J];
	if (a <= h && h <= b)
	    break;
	I = i;
	a += D.bins[I];
    }
    if (s1 == 0)
	return 0.0;
    if (a > h) {
	debug(0, 0) ("statLogHistDeltaMedian: a=%d, h=%d\n", a, h);
	return 0.0;
    }
    if (a >= b) {
	debug(0, 0) ("statLogHistDeltaMedian: a=%d, b=%d\n", a, b);
	return 0.0;
    }
    if (I >= J) {
	debug(0, 0) ("statLogHistDeltaMedian: I=%d, J=%d\n", I, J);
	return 0.0;
    }
    f = (h - a) / (b - a);
    K = f * (double) (J - I) + I;
    return statLogHistVal(A, K);
}

static int
statLogHistBin(StatLogHist * H, double v)
{
    int bin;
    double x = 1.0 + v - H->min;
    if (x < 0.0)
	return 0;
    bin = (int) (H->scale * log(x) + 0.5);
    if (bin < 0)
	bin = 0;
    if (bin > STAT_LOG_HIST_BINS - 1)
	bin = STAT_LOG_HIST_BINS - 1;
    return bin;
}

static double
statLogHistVal(StatLogHist * H, double bin)
{
    return exp(bin / H->scale) + H->min - 1.0;
}

enum {
    HTTP_SVC, ICP_SVC, DNS_SVC
