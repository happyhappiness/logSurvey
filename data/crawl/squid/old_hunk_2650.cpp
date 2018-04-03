{
    debugs(16, 5, HERE);
    Must(entry != NULL);
    if (UsingSmp() && IamWorkerProcess())
        storeAppendPrintf(entry, "by kid%d {\n", KidIdentifier);
    handler(entry);
    if (atomic() && UsingSmp() && IamWorkerProcess())
        storeAppendPrintf(entry, "} by kid%d\n\n", KidIdentifier);
}
