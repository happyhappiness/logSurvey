    statHistDump(&f->icp.client_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "\ncd.client_svc_time histogram:\n");
    statHistDump(&f->cd.client_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "\ncd.peer_choice_count histogram:\n");
    statHistDump(&f->cd.peer_choice_count, sentry, &statHistIntDumper);
    storeAppendPrintf(sentry, "\ncd.peer_ichoice_count histogram:\n");
    statHistDump(&f->cd.peer_ichoice_count, sentry, &statHistIntDumper);
#endif
#if TOO_MUCH_OUTPUT
    storeAppendPrintf(sentry, "icp.query_svc_time histogram:\n");
