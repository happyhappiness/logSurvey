    statHistDump(&f->client_http.nm_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "client_http.hit_svc_time histogram:\n");
    statHistDump(&f->client_http.hit_svc_time, sentry, NULL);
#endif
#if USE_CACHE_DIGESTS
    StatCounters *f = &Counter;
    storeAppendPrintf(sentry, "\nicp.query_svc_time histogram:\n");
    statHistDump(&f->icp.query_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "\nicp.reply_svc_time histogram:\n");
    statHistDump(&f->icp.reply_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "\nicp.server_svc_time histogram:\n");
    statHistDump(&f->icp.server_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "\nicp.client_svc_time histogram:\n");
    statHistDump(&f->icp.client_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "\ncd.server_svc_time histogram:\n");
    statHistDump(&f->cd.server_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "\ncd.client_svc_time histogram:\n");
    statHistDump(&f->cd.client_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "\ncd.peer_choice_count histogram:\n");
    statHistDump(&f->cd.peer_choice_count, sentry, &statHistIntDumper);
    storeAppendPrintf(sentry, "\ncd.peer_ichoice_count histogram:\n");
    statHistDump(&f->cd.peer_ichoice_count, sentry, &statHistIntDumper);
    storeAppendPrintf(sentry, "\ncd.on_xition_count histogram:\n");
    statHistDump(&f->cd.on_xition_count, sentry, &statHistIntDumper);
#endif
#if TOO_MUCH_OUTPUT
    storeAppendPrintf(sentry, "icp.query_svc_time histogram:\n");
    statHistDump(&f->icp.query_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "icp.reply_svc_time histogram:\n");
