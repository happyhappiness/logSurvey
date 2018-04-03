    }

    storeAppendPrintf(entry, "\n%s %s realm %s\n%s %s children %d\n%s %s nonce_max_count %d\n%s %s nonce_max_duration %d seconds\n%s %s nonce_garbage_interval %d seconds\n",
                      name, "digest", digestAuthRealm,
                      name, "digest", authenticateChildren,
                      name, "digest", noncemaxuses,
                      name, "digest", (int) noncemaxduration,
                      name, "digest", (int) nonceGCInterval);
}

bool
AuthDigestConfig::active() const
{
    return authdigest_initialised == 1;
}

bool
AuthDigestConfig::configured() const
{
    if ((authenticate != NULL) &&
            (authenticateChildren != 0) &&
            (digestAuthRealm != NULL) && (noncemaxduration > -1))
        return true;

    return false;
}

int
AuthDigestUserRequest::authenticated() const
{
    if (credentials() == Ok)
        return 1;
