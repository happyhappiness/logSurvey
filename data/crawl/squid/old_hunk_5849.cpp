	    return;
	    /* notreached */
	case NTLM_CHALLENGE:
	    SEND("NA Got a challenge. We refuse to have our authority disputed");
	    return;
	    /* notreached */
	case NTLM_AUTHENTICATE:
	    /* check against the DC */
	    plen = strlen(buf) * 3 / 4;		/* we only need it here. Optimization */
	    cred = ntlm_check_auth((ntlm_authenticate *) decoded, plen);
	    if (cred == NULL) {
		int errorclass, errorcode;
#ifdef DEBUG
		SMB_Get_Error_Msg(SMB_Get_Last_SMB_Err(),
		    error_messages_buffer, BUFFER_SIZE);
		debug("Authentication failure. SMB error: %d: %s\n. Class=%d, "
		    "Code=%d\n",
		    SMB_Get_Last_SMB_Err(), error_messages_buffer,
		    SMB_Get_Last_SMB_Err() & 0xff, SMB_Get_Last_SMB_Err() >> 16);
#endif
		/* This is kind of a special case, which happens when the
		 * client sends credentials in a domain which is not trusted
		 * by the domain we're using when authenticating. Unfortunately,
		 * it can't currently be accommodated in the current framework so
		 * I'll leave it hanging here, waiting for the general framework
		 * to be expanded to better accommodate the generale case. */
		errorclass = SMB_Get_Last_SMB_Err() & 0xff;
		errorcode = SMB_Get_Last_SMB_Err() >> 16;
		if (errorclass == 1 && errorcode == 5) {
		    SEND("NA Wrong password or untrusted domain");
		    return;
		}
		switch (ntlm_errno) {
		case NTLM_LOGON_ERROR:
		    SEND("NA authentication failure");
		    /* I must have been drugged when I wrote the following two lines */
		    /* dc_disconnect();
		     * current_dc = current_dc->next; */
		    return;
		case NTLM_SERVER_ERROR:
		    send_bh_or_ld("BH Domain Controller Error", (ntlm_authenticate *) decoded, plen);
		    /* SEND("BH Domain Controller Error"); */
		    /* we don't really need to disconnect NOW.
		     * Besides, we asked squid to force a reconnect. This way, if we
		     * have authentications in flight, we might even succeed.
		     */
		    /* dc_disconnect(); */

		    SMB_Get_Error_Msg(SMB_Get_Last_Error(), smb_error_buffer, 1000);
		    debug("Last error was: %s, RFC errno=%d\n", smb_error_buffer,
			RFCNB_Get_Last_Errno());
		    if (failover_enabled)
			current_dc = current_dc->next;
		    return;
		case NTLM_PROTOCOL_ERROR:
		    send_bh_or_ld("BH Domain Controller communication error", (ntlm_authenticate *) decoded, plen);
		    /* SEND("BH Domain Controller communication error"); */
		    /* dc_disconnect(); */
		    if (failover_enabled)
			current_dc = current_dc->next;
		    return;
		case NTLM_NOT_CONNECTED:
		    send_bh_or_ld("BH Domain Controller (or network) died on us", (ntlm_authenticate *) decoded, plen);
		    /* SEND("BH Domain Controller (or network) died on us"); */
		    /* dc_disconnect(); */
		    if (failover_enabled)
			current_dc = current_dc->next;
		    return;
		case NTLM_BAD_PROTOCOL:
		    send_bh_or_ld("BH Domain controller failure", (ntlm_authenticate *) decoded, plen);
		    /* SEND("BH Domain controller failure"); */
		    /* dc_disconnect(); *//* maybe we're overreacting? */
		    SMB_Get_Error_Msg(SMB_Get_Last_Error(), smb_error_buffer, 1000);
		    debug("Last error was: %s. RFCNB errno=%d\n", smb_error_buffer,
			RFCNB_Get_Last_Errno());
		    if (failover_enabled)
			current_dc = current_dc->next;
		    return;
		default:
		    send_bh_or_ld("BH Unhandled error while talking to Domain Controller", (ntlm_authenticate *) decoded, plen);
		    /* SEND("BH Unhandled error while talking to Domain Controller"); */
		    /* dc_disconnect(); *//* maybe we're overreacting? */
		    if (failover_enabled)
			current_dc = current_dc->next;
		    return;
		}
	    }
