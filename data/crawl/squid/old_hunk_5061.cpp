    threadp = threads;

    for (i = 0; i < NUMTHREADS; i++) {
        storeAppendPrintf(sentry, "%i\t0x%lx\t%ld\n", i + 1, threadp->thread, threadp->requests);
        threadp = threadp->next;
    }
}