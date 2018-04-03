         * challenge - release the helper and use the existing auth_user 
         * details. */

        ntlm_request->ntlmauthenticate = xstrdup(proxy_auth);

        /* cache entries have authenticateauthheaderchallengestring */
        snprintf(ntlmhash, sizeof(ntlmhash) - 1, "%s%s",