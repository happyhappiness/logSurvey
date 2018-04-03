    statHistDump(&f->icp.query_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "\nicp.reply_svc_time histogram:\n");
    statHistDump(&f->icp.reply_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "\nicp.client_svc_time histogram:\n");
    statHistDump(&f->icp.client_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "\ncd.client_svc_time histogram:\n");
    statHistDump(&f->cd.client_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "\ncd.peer_choice_count histogram:\n");