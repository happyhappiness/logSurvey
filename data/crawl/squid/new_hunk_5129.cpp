    }

    storeAppendPrintf(entry, "\n%s %s children %d\n%s %s max_challenge_reuses %d\n%s %s max_challenge_lifetime %d seconds\n",
                      name, "ntlm", authenticateChildren,
                      name, "ntlm", challengeuses,
                      name, "ntlm", (int) challengelifetime);

}

AuthNTLMConfig::AuthNTLMConfig()
{
    /* TODO Move into initialisation list */
    authenticateChildren = 5;
    challengeuses = 0;
    challengelifetime = 60;
}

void
AuthNTLMConfig::parse(AuthConfig * scheme, int n_configured, char *param_str)
{
    if (strcasecmp(param_str, "program") == 0) {
        if (authenticate)
            wordlistDestroy(&authenticate);

        parse_wordlist(&authenticate);

        requirePathnameExists("authparam ntlm program", authenticate->key);
    } else if (strcasecmp(param_str, "children") == 0) {
        parse_int(&authenticateChildren);
    } else if (strcasecmp(param_str, "max_challenge_reuses") == 0) {
        parse_int(&challengeuses);
    } else if (strcasecmp(param_str, "max_challenge_lifetime") == 0) {
        parse_time_t(&challengelifetime);
    } else {
        debug(28, 0) ("unrecognised ntlm auth scheme parameter '%s'\n", param_str);
    }
