
    storeAppendPrintf(entry, "\n");

    storeAppendPrintf(entry, "%s basic realm %s\n", name, basicAuthRealm);
    storeAppendPrintf(entry, "%s basic children %d\n", name, authenticateChildren);
    storeAppendPrintf(entry, "%s basic concurrency %d\n", name, authenticateConcurrency);
    storeAppendPrintf(entry, "%s basic credentialsttl %d seconds\n", name, (int) credentialsTTL);

}

AuthBasicConfig::AuthBasicConfig()
{
    /* TODO: move into initialisation list */
    authenticateChildren = 5;
    credentialsTTL = 2 * 60 * 60;	/* two hours */
}

void
AuthBasicConfig::parse(AuthConfig * scheme, int n_configured, char *param_str)
{
    if (strcasecmp(param_str, "program") == 0) {
        if (authenticate)
            wordlistDestroy(&authenticate);

        parse_wordlist(&authenticate);

        requirePathnameExists("authparam basic program", authenticate->key);
    } else if (strcasecmp(param_str, "children") == 0) {
        parse_int(&authenticateChildren);
    } else if (strcasecmp(param_str, "concurrency") == 0) {
        parse_int(&authenticateConcurrency);
    } else if (strcasecmp(param_str, "realm") == 0) {
        parse_eol(&basicAuthRealm);
    } else if (strcasecmp(param_str, "credentialsttl") == 0) {
        parse_time_t(&credentialsTTL);
    } else {
        debug(28, 0) ("unrecognised basic auth scheme parameter '%s'\n", param_str);
    }
