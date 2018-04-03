
/*      debug("fetching user name\n"); */
    tmp = ntlm_fetch_string((char *) auth, auth_length, &auth->user);
    if (tmp.str == NULL) {
	debug("No username supplied. Returning no-auth\n");
	ntlm_errno = NTLM_LOGON_ERROR;
	return NULL;
    }
    memcpy(user, tmp.str, tmp.l);
    *(user + tmp.l) = '\0';

    debug("checking domain: '%s', user: '%s', pass='%s'\n", domain, user, pass);

    rv = SMB_Logon_Server(handle, user, pass, domain, 1);
