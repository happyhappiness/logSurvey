	ntlm_errno = NTLM_NOT_CONNECTED;
	return NULL;
    }

/*      debug("fetching domain\n"); */
    tmp = ntlm_fetch_string((char *) auth, auth_length, &auth->domain);
    if (tmp.str == NULL || tmp.l == 0) {
	debug("No domain supplied. Returning no-auth\n");
	ntlm_errno = NTLM_LOGON_ERROR;
	return NULL;
