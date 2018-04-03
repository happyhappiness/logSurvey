                          (long int) http->start.tv_sec,
                          (int) http->start.tv_usec,
                          tvSubDsec(http->start, current_time));
#if DELAY_POOLS

        storeAppendPrintf(s, "delay_pool %d\n", DelayId::DelayClient(http) >> 16);
#endif

        storeAppendPrintf(s, "\n");