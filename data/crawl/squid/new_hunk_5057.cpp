        /* first the standard KK stuff */
        debug(29, 4) ("authenticateNTLMHandleReply: Error validating user via NTLM. Error returned '%s'\n", reply);

        /* now we mark the helper for resetting. */
        helperstate->starve = 1;

        ntlm_request->auth_state = AUTHENTICATE_STATE_FAILED;

        reply += 3;

        if (*reply)
            auth_user_request->setDenyMessage(reply);
    } else {
        /* TODO: only work with auth_user here if it exists */
        /* TODO: take the request state into consideration */
