

    /* Authenticating against the NT response doesn't seem to work... */
    tmp = ntlm_fetch_string((char *) auth, auth_length, &auth->lmresponse);
    if (tmp.str == NULL || tmp.l == 0) {
        fprintf(stderr, "No auth at all. Returning no-auth\n");
        ntlm_errno = NTLM_LOGON_ERROR;
        return NULL;
    }
    if (tmp.l > MAX_PASSWD_LEN) {
        print_debug("Password string exceeds %d bytes, rejecting\n", MAX_PASSWD_LEN);
        ntlm_errno = NTLM_LOGON_ERROR;
        return NULL;
    }