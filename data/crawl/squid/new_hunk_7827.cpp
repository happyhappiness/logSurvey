	obj->logfile_status = LOG_DISABLE;
    }
    /* at the moment, store one char to make a storage manager happy */
    storeAppendPrintf(sentry, " ");
    storeAppend(sentry, tempbuf, strlen(tempbuf));
}

