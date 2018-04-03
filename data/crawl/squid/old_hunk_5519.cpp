static void
authBasicCfgDump(StoreEntry * entry, const char *name, authScheme * scheme)
{
    auth_basic_config *config = scheme->scheme_data;
    wordlist *list = config->authenticate;
    storeAppendPrintf(entry, "%s %s", name, "basic");
    while (list != NULL) {