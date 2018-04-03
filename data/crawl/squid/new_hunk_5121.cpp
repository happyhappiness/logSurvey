    authenticateStateFree(r);
}

void
AuthBasicConfig::dump(StoreEntry * entry, const char *name, AuthConfig * scheme)
{
    wordlist *list = authenticate;
    storeAppendPrintf(entry, "%s %s", name, "basic");

    while (list != NULL) {
