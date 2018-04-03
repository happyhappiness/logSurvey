#endif

        storeAppendPrintf(s, "start %ld.%06d (%f seconds ago)\n",
                          (long int) http->start.tv_sec,
                          (int) http->start.tv_usec,
                          tvSubDsec(http->start, current_time));

        if (http->request->auth_user_request)
            p = http->request->auth_user_request->username();