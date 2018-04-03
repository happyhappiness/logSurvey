static int
saneDiff(time_t diff)
{
    return abs(diff) > squid_curtime/2 ? 0 : diff;
}

void
peerDigestStatsReport(const PeerDigest *pd, StoreEntry * e)
{
#define f2s(flag) (pd->flags.flag ? "yes" : "no")
#define appendTime(tm) storeAppendPrintf(e, "%s\t %10d\t %+d\t %+d\n", \
