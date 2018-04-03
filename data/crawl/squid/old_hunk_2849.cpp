
    return aclMapNfmark(Ip::Qos::TheConfig.nfmarkToServer, &ch);
}


/**** WIP_FWD_LOG *************************************************************/

#if WIP_FWD_LOG
void
fwdUninit(void)
{
    if (NULL == logfile)
        return;

    logfileClose(logfile);

    logfile = NULL;
}

void
fwdLogRotate(void)
{
    if (logfile)
        logfileRotate(logfile);
}

static void
FwdState::log()
{
    if (NULL == logfile)
        return;

    logfilePrintf(logfile, "%9d.%03d %03d %s %s\n",
                  (int) current_time.tv_sec,
                  (int) current_time.tv_usec / 1000,
                  last_status,
                  RequestMethodStr(request->method),
                  request->canonical);
}

void
FwdState::status(http_status s)
{
    last_status = s;
}

#endif
