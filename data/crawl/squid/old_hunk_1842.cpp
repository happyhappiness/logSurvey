        if (squid_curtime - first_warn > 3 * 60)
            fatal("SSL servers not responding for 3 minutes");
        debugs(34, DBG_IMPORTANT, HERE << "Queue overload, rejecting");
        const char *errMsg = "BH error 45 Temporary network problem, please retry later"; // XXX: upgrade to message=""
        HelperReply failReply(errMsg,strlen(errMsg));
        callback(data, failReply);
        return;
    }
