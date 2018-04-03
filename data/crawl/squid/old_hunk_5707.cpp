	ntlm_errno = NTLM_NOT_CONNECTED;
	return NULL;
    }
    /* Authenticating against the NT response doesn't seem to work... */
    tmp = ntlm_fetch_string((char *) auth, auth_length, &auth->lmresponse);
    if (tmp.str == NULL) {
	fprintf(stderr, "No auth at all. Returning no-auth\n");
	ntlm_errno = NTLM_LOGON_ERROR;
	return NULL;
    }
    memcpy(pass, tmp.str, tmp.l);
    pass[25] = '\0';

/*      debug("fetching domain\n"); */
    tmp = ntlm_fetch_string((char *) auth, auth_length, &auth->domain);
    if (tmp.str == NULL) {
	debug("No domain supplied. Returning no-auth\n");
	ntlm_errno = NTLM_LOGON_ERROR;
	return NULL;
