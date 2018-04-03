	/* we have been given a Challenge */
	/* we should check we weren't given an empty challenge */
	/* copy the challenge to the state data */
	helperstate = helperStatefulServerGetData(lastserver);
	if (helperstate == NULL)
	    fatal("lost NTLM helper state! quitting\n");
	helperstate->challenge = xstrndup(reply, NTLM_CHALLENGE_SZ + 5);
