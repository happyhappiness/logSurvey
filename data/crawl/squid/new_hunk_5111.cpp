    storeAppendPrintf(entry, "%s basic children %d\n", name, authenticateChildren);
    storeAppendPrintf(entry, "%s basic concurrency %d\n", name, authenticateConcurrency);
    storeAppendPrintf(entry, "%s basic credentialsttl %d seconds\n", name, (int) credentialsTTL);
    storeAppendPrintf(entry, "%s basic casesensitive %s\n", name, casesensitive ? "on" : "off");

}

