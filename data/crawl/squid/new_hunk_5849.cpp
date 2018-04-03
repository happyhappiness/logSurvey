	    return;
	    /* notreached */
	case NTLM_CHALLENGE:
	    SEND
		("NA Got a challenge. We refuse to have our authority disputed");
	    return;
	    /* notreached */
	case NTLM_AUTHENTICATE:
	    /* check against the DC */
	    plen = strlen(buf) * 3 / 4;		/* we only need it here. Optimization */
	    cred = ntlm_check_auth((ntlm_authenticate *) decoded, plen);
	    if (cred == NULL) {
		int smblib_err, smb_errorclass, smb_errorcode, nb_error;
		/* there was an error. We have two errno's to look at.
		 * libntlmssp's erno is insufficient, we'll have to look at
		 * the actual SMB library error codes, to acually figure
		 * out what's happening. The thing has braindamaged interfacess..*/
		smblib_err = SMB_Get_Last_Error();
		smb_errorclass = SMBlib_Error_Class(SMB_Get_Last_SMB_Err());
		smb_errorcode = SMBlib_Error_Code(SMB_Get_Last_SMB_Err());
		nb_error = RFCNB_Get_Last_Error();
		debug
		    ("No creds. SMBlib error %d, SMB error class %d, SMB error code %d, NB error %d\n",
		    smblib_err, smb_errorclass, smb_errorcode, nb_error);
		/* Should I use smblib_err? Actually it seems I can do as well
		 * without it.. */
		if (nb_error != 0) {	/* netbios-level error */
		    send_bh_or_ld("NetBios error!",
			(ntlm_authenticate *) decoded, plen);
		    fprintf(stderr, "NetBios error code %d (%s)\n", nb_error,
			RFCNB_Error_Strings[abs(nb_error)]);
		    return;
		}
		switch (smb_errorclass) {
		case SMBC_SUCCESS:
		    debug("Huh? Got a SMB success code but could check auth..");
		    SEND("NA Authentication failed");
		    /*
		     * send_bh_or_ld("SMB success, but no creds. Internal error?",
		     * (ntlm_authenticate *) decoded, plen);
		     */
		    return;
		case SMBC_ERRDOS:
		    /*this is the most important one for errors */
		    debug("DOS error\n");
		    switch (smb_errorcode) {
			/* two categories matter to us: those which could be
			 * server errors, and those which are auth errors */
		    case SMBD_noaccess:	/* 5 */
			SEND("NA Access denied");
			return;
		    case SMBD_badformat:
			SEND("NA bad format in authentication packet");
			return;
		    case SMBD_badaccess:
			SEND("NA Bad access request");
			return;
		    case SMBD_baddata:
			SEND("NA Bad Data");
			return;
		    default:
			send_bh_or_ld("DOS Error",
			    (ntlm_authenticate *) decoded, plen);
			return;
		    }
		case SMBC_ERRSRV:	/* server errors */
		    debug("Server error");
		    switch (smb_errorcode) {
			/* mostly same as above */
		    case SMBV_badpw:
			SEND("NA Bad password");
			return;
		    case SMBV_access:
			SEND("NA Server access error");
			return;
		    default:
			send_bh_or_ld("Server Error",
			    (ntlm_authenticate *) decoded, plen);
			return;
		    }
		case SMBC_ERRHRD:	/* hardware errors don't really matter */
		    send_bh_or_ld("Domain Controller Hardware error",
			(ntlm_authenticate *) decoded, plen);
		    return;
		case SMBC_ERRCMD:
		    send_bh_or_ld("Domain Controller Command Error",
			(ntlm_authenticate *) decoded, plen);
		    return;
		}
	    }
