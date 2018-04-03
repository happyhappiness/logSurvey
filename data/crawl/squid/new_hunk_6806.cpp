{
    return Squid_MaxFD - Number_FD;
}

/* Called when we runs out of file descriptors */
void
fdAdjustReserved(void)
{
    int new;
    int x;
    static time_t last = 0;
    /*
     * don't update too frequently
     */
    if (last + 5 > squid_curtime)
	return;
    /*
     * Calculate a new reserve, based on current usage and a small extra
     */
    new = Squid_MaxFD - Number_FD + XMIN(25, Squid_MaxFD / 16);
    if (new <= RESERVED_FD)
	return;
    x = Squid_MaxFD - 20 - XMIN(25, Squid_MaxFD / 16);
    if (new > x) {
	/* perhaps this should be fatal()? -DW */
	debug(51, 0) ("WARNING: This machine has a serious shortage of filedescriptors.\n");
	new = x;
    }
    debug(51, 0) ("Reserved FD adjusted from %d to %d due to failures\n",
	RESERVED_FD, new);
    RESERVED_FD = new;
}
