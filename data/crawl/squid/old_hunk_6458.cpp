    statHistDump(&f->icp.client_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "\ncd.client_svc_time histogram:\n");
    statHistDump(&f->cd.client_svc_time, sentry, NULL);
#endif
#if TOO_MUCH_OUTPUT
    storeAppendPrintf(sentry, "icp.query_svc_time histogram:\n");
