static void
authenticateDigestStats(StoreEntry * sentry)
{
    storeAppendPrintf(sentry, "Digest Authenticator Statistics:\n");
    helperStats(sentry, digestauthenticators);
}

/* NonceUserUnlink: remove the reference to auth_user and unlink the node from the list */
