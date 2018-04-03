	/* todo: action of Negotiate state on error */
	result = S_HELPER_RELEASE;	/*some error has occured. no more requests */
	ntlm_request->authserver = NULL;
	ntlm_request->flags.credentials_ok = 2;	/* Login/Usercode failed */
	debug(29, 4) ("authenticateNTLMHandleReply: Error validating user via NTLM. Error returned '%s'\n", reply);
	ntlm_request->auth_state = AUTHENTICATE_STATE_NONE;
	if ((t = strchr(reply, ' ')))	/* strip after a space */
	    *t = '\0';
    } else if (strncasecmp(reply, "NA", 2) == 0) {
	/* NTLM Helper protocol violation! */
	fatal ("NTLM Helper returned invalid response \"NA\" - a error message MUST be attached\n");
    } else if (strncasecmp(reply, "BH ", 3) == 0) {
	/* TODO kick off a refresh process. This can occur after a YR or after
	 * a KK. If after a YR release the helper and resubmit the request via 
