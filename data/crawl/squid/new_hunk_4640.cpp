static void
authenticateDigestStats(StoreEntry * sentry)
{
    helperStats(sentry, digestauthenticators, "Digest Authenticator Statistics");
}

/* NonceUserUnlink: remove the reference to auth_user and unlink the node from the list */
