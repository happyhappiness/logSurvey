	obj->logfile_status = LOG_DISABLE;
    }
    /* at the moment, store one char to make a storage manager happy */
    sprintf(tempbuf, " ");
    storeAppend(sentry, tempbuf, strlen(tempbuf));
}

