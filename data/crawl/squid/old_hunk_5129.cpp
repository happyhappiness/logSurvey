    }

    storeAppendPrintf(entry, "\n%s %s children %d\n%s %s max_challenge_reuses %d\n%s %s max_challenge_lifetime %d seconds\n",
                      name, "ntlm", config->authenticateChildren,
                      name, "ntlm", config->challengeuses,
                      name, "ntlm", (int) config->challengelifetime);

}

static void
authNTLMParse(authScheme * scheme, int n_configured, char *param_str)
{
    if (scheme->scheme_data == NULL) {
        assert(ntlmConfig == NULL);
        /* this is the first param to be found */
        scheme->scheme_data = xmalloc(sizeof(auth_ntlm_config));
        memset(scheme->scheme_data, 0, sizeof(auth_ntlm_config));
        ntlmConfig = static_cast<auth_ntlm_config *>(scheme->scheme_data);
        ntlmConfig->authenticateChildren = 5;
        ntlmConfig->challengeuses = 0;
        ntlmConfig->challengelifetime = 60;
    }

    ntlmConfig = static_cast<auth_ntlm_config *>(scheme->scheme_data);

    if (strcasecmp(param_str, "program") == 0) {
        if (ntlmConfig->authenticate)
            wordlistDestroy(&ntlmConfig->authenticate);

        parse_wordlist(&ntlmConfig->authenticate);

        requirePathnameExists("authparam ntlm program", ntlmConfig->authenticate->key);
    } else if (strcasecmp(param_str, "children") == 0) {
        parse_int(&ntlmConfig->authenticateChildren);
    } else if (strcasecmp(param_str, "max_challenge_reuses") == 0) {
        parse_int(&ntlmConfig->challengeuses);
    } else if (strcasecmp(param_str, "max_challenge_lifetime") == 0) {
        parse_time_t(&ntlmConfig->challengelifetime);
    } else {
        debug(28, 0) ("unrecognised ntlm auth scheme parameter '%s'\n", param_str);
    }
