    if (p->domain)
        storeAppendPrintf(sentry, " forceddomain=%s", p->domain);

    if(p->connection_auth == 0)
	storeAppendPrintf(sentry, " connection-auth=off");
    else if(p->connection_auth == 1)
	storeAppendPrintf(sentry, " connection-auth=on");
    else if(p->connection_auth == 2)
	storeAppendPrintf(sentry, " connection-auth=auto");

    storeAppendPrintf(sentry, "\n");
}

