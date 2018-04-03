static void
authenticateBasicStats(StoreEntry * sentry)
{
    storeAppendPrintf(sentry, "Basic Authenticator Statistics:\n");
    helperStats(sentry, basicauthenticators);
}

CBDATA_TYPE(AuthenticateStateData);
