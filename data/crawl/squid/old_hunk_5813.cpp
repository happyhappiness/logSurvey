		/* restart the authentication process */
		ntlm_request->auth_state = AUTHENTICATE_STATE_NONE;
		auth_user->flags.credentials_ok = 3;	/* cannot process */
		ntlm_request->authhelper = NULL;
	    }
	} else {
	    fatal("authenticateNTLMHandleReply: called with no result string\n");
