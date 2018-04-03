                          (long int) http->start.tv_sec,
                          (int) http->start.tv_usec,
                          tvSubDsec(http->start, current_time));
        storeAppendPrintf(s, "\n");
    }
}