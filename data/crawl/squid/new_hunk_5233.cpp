    if (al->hier.host[0] == '\0')
        xstrncpy(al->hier.host, dash_str, SQUIDHOSTNAMELEN);

    for (log = Config.Log.accesslogs; log; log = log->next) {
        if (checklist && log->aclList && checklist->matchAclListFast(log->aclList))
            continue;

        switch (log->type) {

        case CLF_AUTO:

            if (Config.onoff.common_log)
                accessLogCommon(al, log->logfile);
            else
                accessLogSquid(al, log->logfile);

            break;

        case CLF_SQUID:
            accessLogSquid(al, log->logfile);

            break;

        case CLF_COMMON:
            accessLogCommon(al, log->logfile);

            break;

        case CLF_CUSTOM:
            accessLogCustom(al, log);

            break;

        case CLF_NONE:
            goto last;

        default:
            fatalf("Unknown log format %d\n", log->type);

            break;
        }

        logfileFlush(log->logfile);

        if (!checklist)
            break;
    }

last:
    (void)0; /* NULL statement for label */

#if MULTICAST_MISS_STREAM

    if (al->cache.code != LOG_TCP_MISS)
