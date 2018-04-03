	httpd_accel_mode);

    /* end of stats */
    storeAppendPrintf(sentry, "}\n");
}


void log_append(obj, url, id, size, action, method, http_code, msec, ident)
     cacheinfo *obj;
     char *url;
     char *id;
