	(int) f->icp.kbytes_sent.kb);
    storeAppendPrintf(sentry, "icp.kbytes_recv = %d\n",
	(int) f->icp.kbytes_recv.kb);
    storeAppendPrintf(sentry, "icp.query_svc_time histogram:\n");
    statLogHistDump(sentry, &f->icp.query_svc_time);
    storeAppendPrintf(sentry, "icp.reply_svc_time histogram:\n");
    statLogHistDump(sentry, &f->icp.reply_svc_time);

    storeAppendPrintf(sentry, "dns.svc_time histogram:\n");
    statLogHistDump(sentry, &f->dns.svc_time);
    storeAppendPrintf(sentry, "unlink.requests = %d\n",
