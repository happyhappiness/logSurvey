{
    return x;
}

void
statHistEnumInit(StatHist * H, int last_enum)
{
    statHistInit(H, last_enum + 3, &Null, &Null, -1, last_enum + 1 + 1);
}

void
statHistEnumDumper(StoreEntry * sentry, int idx, double val, double size, int count)
{
    if (count)
	storeAppendPrintf(sentry, "%2d\t %5d\t %5d\n",
	    idx, (int) val, count);
}

void
statHistIntInit(StatHist * H, int n)
{
    statHistInit(H, n, &Null, &Null, 0, n-1);
}

void
statHistIntDumper(StoreEntry * sentry, int idx, double val, double size, int count)
{
    if (count)
	storeAppendPrintf(sentry, "%9d\t%9d\n", (int) val, count);
}
