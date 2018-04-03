    debug(29, 2) ("authenticateDigestDone: Digest authentication shut down.\n");
}

void
AuthDigestConfig::dump(StoreEntry * entry, const char *name, AuthConfig * scheme)
{
    wordlist *list = authenticate;
    debug(29, 9) ("authDigestCfgDump: Dumping configuration\n");
    storeAppendPrintf(entry, "%s %s", name, "digest");

