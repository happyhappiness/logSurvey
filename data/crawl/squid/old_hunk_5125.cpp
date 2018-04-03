    }

    storeAppendPrintf(entry, "\n%s %s realm %s\n%s %s children %d\n%s %s nonce_max_count %d\n%s %s nonce_max_duration %d seconds\n%s %s nonce_garbage_interval %d seconds\n",
                      name, "digest", config->digestAuthRealm,
                      name, "digest", config->authenticateChildren,
                      name, "digest", config->noncemaxuses,
                      name, "digest", (int) config->noncemaxduration,
                      name, "digest", (int) config->nonceGCInterval);
}

void
authSchemeSetup_digest(authscheme_entry_t * authscheme)
{
    assert(!authdigest_initialised);
    authscheme->Active = authenticateDigestActive;
    authscheme->configured = authDigestConfigured;
    authscheme->parse = authDigestParse;
    authscheme->freeconfig = authDigestFreeConfig;
    authscheme->dump = authDigestCfgDump;
    authscheme->init = authDigestInit;
    authscheme->authAuthenticate = NULL;
    authscheme->authenticated = NULL;
    authscheme->authFixHeader = authenticateDigestFixHeader;
    authscheme->FreeUser = authenticateDigestUserFree;
#if WAITING_FOR_TE

    authscheme->AddTrailer = authDigestAddTrailer;
#endif

    authscheme->authStart = authenticateDigestStart;
    authscheme->authStats = authenticateDigestStats;
    authscheme->authUserUsername = authenticateDigestUsername;
    authscheme->getdirection = NULL;
    authscheme->oncloseconnection = NULL;
    authscheme->decodeauth = authenticateDigestDecodeAuth;
    authscheme->donefunc = authDigestDone;
    authscheme->requestFree = NULL;
    authscheme->authConnLastHeader = NULL;
}

static int
authenticateDigestActive(void)
{
    return (authdigest_initialised == 1) ? 1 : 0;
}

static int
authDigestConfigured(void)
{
    if ((digestConfig != NULL) && (digestConfig->authenticate != NULL) &&
            (digestConfig->authenticateChildren != 0) &&
            (digestConfig->digestAuthRealm != NULL) && (digestConfig->noncemaxduration > -1))
        return 1;

    return 0;
}

int
digest_request_h::authenticated() const
{
    if (credentials() == Ok)
        return 1;
