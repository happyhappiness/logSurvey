		
}

/* ========== LOCAL FUNCTIONS ABOVE, GLOBAL FUNCTIONS BELOW ========== */

void
DiskdSwapDir::statfs(StoreEntry & sentry)const
{
    UFSSwapDir::statfs (sentry);
    DiskdIO *DIO = dynamic_cast<DiskdIO *>(IO);
    storeAppendPrintf(&sentry, "Pending operations: %d\n", DIO->away);
}

static void
storeDiskdDirParseQ1(SwapDir * sd, const char *name, const char *value, int reconfiguring)
{
    DiskdIO *IO = dynamic_cast<DiskdIO *>(((DiskdSwapDir *)sd)->IO);
    int old_magic1 = IO->magic1;
    IO->magic1 = atoi(value);
    if (!reconfiguring)
	return;
    if (old_magic1 < IO->magic1) {
       /*
	* This is because shm.nbufs is computed at startup, when
	* we call shmget().  We can't increase the Q1/Q2 parameters
