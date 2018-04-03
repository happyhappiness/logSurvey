
    }
    /* at the moment, store one char to make a storage manager happy */
    storeAppendPrintf(sentry, " ");
    storeAppend(sentry, tempbuf, strlen(tempbuf));
}

void log_disable(obj, sentry)
     cacheinfo *obj;
     StoreEntry *sentry;
{
    if (obj->logfile_status == LOG_ENABLE)
	file_close(obj->logfile_fd);

    obj->logfile_status = LOG_DISABLE;
    /* at the moment, store one char to make a storage manager happy */
    storeAppendPrintf(sentry, " ");
}


