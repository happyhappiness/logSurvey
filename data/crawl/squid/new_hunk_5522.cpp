	/* we have been given a Challenge */
	/* we should check we weren't given an empty challenge */
	/* copy the challenge to the state data */
	helperstate = static_cast<ntlm_helper_state_t *>(helperStatefulServerGetData(static_cast<helper_stateful_server *>(lastserver)));
	if (helperstate == NULL)
	    fatal("lost NTLM helper state! quitting\n");
	helperstate->challenge = xstrndup(reply, NTLM_CHALLENGE_SZ + 5);
