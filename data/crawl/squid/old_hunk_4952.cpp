        list = list->next;
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
