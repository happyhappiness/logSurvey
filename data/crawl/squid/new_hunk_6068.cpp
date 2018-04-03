void
accessLogRotate(void)
{
#if FORW_VIA_DB
    fvdbClear();
#endif
    if (NULL == logfile)
	return;
    logfileRotate(logfile);
}

void
accessLogClose(void)
{
    logfileClose(logfile);
    logfile = NULL;
}

void
