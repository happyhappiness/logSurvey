	    /* notreached */
	case NTLM_AUTHENTICATE:
	    /* check against the DC */
	    plen = strlen(buf) * 3 / 4;		/* we only need it here. Optimization */
	    cred = ntlm_check_auth((ntlm_authenticate *) decoded, plen);
	    if (cred == NULL) {
		int smblib_err, smb_errorclass, smb_errorcode, nb_error;
		/* there was an error. We have two errno's to look at.
