static void info_get_mallstat(int, int, StoreEntry *);
#endif

/*
 * An hour's worth, plus the 'current' counter
 */
#if 0				/* moved to defines.h to get from snmp_oidlist.c */
#define N_COUNT_HIST 61
#endif
StatCounters CountHist[N_COUNT_HIST];
static int NCountHist = 0;

void
stat_io_get(StoreEntry * sentry)
