        memPoolDestroy(&ntlm_helper_state_pool);
    }

    if (ntlm_user_pool) {
        memPoolDestroy(&ntlm_user_pool);
    }

#endif
    debug(29, 2) ("authNTLMDone: NTLM authentication Shutdown.\n");
}

/* free any allocated configuration details */
static void
authNTLMFreeConfig(authScheme * scheme)
{
    if (ntlmConfig == NULL)
        return;

    assert(ntlmConfig == scheme->scheme_data);

    if (ntlmConfig->authenticate)
        wordlistDestroy(&ntlmConfig->authenticate);

    xfree(ntlmConfig);

    ntlmConfig = NULL;
}

static void
authNTLMCfgDump(StoreEntry * entry, const char *name, authScheme * scheme)
{
    auth_ntlm_config *config = static_cast<auth_ntlm_config *>(scheme->scheme_data);
    wordlist *list = config->authenticate;
    storeAppendPrintf(entry, "%s %s", name, "ntlm");

    while (list != NULL) {
