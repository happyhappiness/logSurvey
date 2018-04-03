{
    StoreEntry *sentry = data;
    if (number > 0)
	storeAppendPrintf(sentry, "%d\t %d\t %d\t %.1f\n", size, number, number - oldnum, xdiv((number - oldnum), xm_deltat));
}
#endif

