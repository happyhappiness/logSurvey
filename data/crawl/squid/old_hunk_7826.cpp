
    }
    /* at the moment, store one char to make a storage manager happy */
    sprintf(tempbuf, " ");
    storeAppend(sentry, tempbuf, strlen(tempbuf));
}

void log_disable(obj, sentry)
     cacheinfo *obj;
     StoreEntry *sentry;
{
    static char tempbuf[MAX_LINELEN];

    if (obj->logfile_status == LOG_ENABLE)
	file_close(obj->logfile_fd);

    obj->logfile_status = LOG_DISABLE;
    /* at the moment, store one char to make a storage manager happy */
    sprintf(tempbuf, " ");
    storeAppend(sentry, tempbuf, strlen(tempbuf));
}


