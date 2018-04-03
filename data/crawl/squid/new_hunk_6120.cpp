    storeAppendPrintf(sentry, "Category\tCount\t%%Total\n");

#define refreshCountsStatsEntry(name) { \
	storeAppendPrintf(sentry, "%s\t%6d\t%6.2f\n", \
	    #name, rc->name, xpercent(rc->name, tot)); \
    sum += rc->name; \
