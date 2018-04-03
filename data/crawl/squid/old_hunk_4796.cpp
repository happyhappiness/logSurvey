                          (int) http->start.tv_usec,
                          tvSubDsec(http->start, current_time));

        if (http->request->auth_user_request) {
            const char *p;

            p = http->request->auth_user_request->username();

            if (!p)
                p = "-";

            storeAppendPrintf(s, "username %s\n", p);
        }

#if DELAY_POOLS
        storeAppendPrintf(s, "delay_pool %d\n", DelayId::DelayClient(http) >> 16);

#endif