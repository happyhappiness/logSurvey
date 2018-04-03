    if (p->domain)
        storeAppendPrintf(sentry, " forceddomain=%s", p->domain);

    storeAppendPrintf(sentry, "\n");
}

