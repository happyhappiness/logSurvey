        memPoolDestroy(&ntlm_helper_state_pool);
    }

#endif
    debug(29, 2) ("authNTLMDone: NTLM authentication Shutdown.\n");
}

/* free any allocated configuration details */
void
AuthNTLMConfig::done()
{
    if (authenticate)
        wordlistDestroy(&authenticate);
}

void
AuthNTLMConfig::dump(StoreEntry * entry, const char *name, AuthConfig * scheme)
{
    wordlist *list = authenticate;
    storeAppendPrintf(entry, "%s %s", name, "ntlm");

    while (list != NULL) {
