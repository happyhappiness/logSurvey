static void
authDigestCfgDump(StoreEntry * entry, const char *name, authScheme * scheme)
{
    auth_digest_config *config = scheme->scheme_data;
    wordlist *list = config->authenticate;
    debug(29, 9) ("authDigestCfgDump: Dumping configuration\n");
    storeAppendPrintf(entry, "%s %s", name, "digest");
