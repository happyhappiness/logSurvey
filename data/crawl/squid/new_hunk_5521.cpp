static void
authNTLMCfgDump(StoreEntry * entry, const char *name, authScheme * scheme)
{
    auth_ntlm_config *config = static_cast<auth_ntlm_config *>(scheme->scheme_data);
    wordlist *list = config->authenticate;
    storeAppendPrintf(entry, "%s %s", name, "ntlm");
    while (list != NULL) {
