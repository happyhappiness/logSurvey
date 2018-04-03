

#ifdef DEBUG
	fprintf(stderr, "Error sending negotiate protocol\n");
#endif

	RFCNB_Free_Pkt(pkt);
	SMBlib_errno = -SMBlibE_SendFailed;	/* Failed, check lower layer errno */
	return (SMBlibE_BAD);

    }
    /* Now get the response ... */

    if (RFCNB_Recv(Con_Handle->Trans_Connect, pkt, alloc_len) < 0) {

#ifdef DEBUG
	fprintf(stderr, "Error receiving response to negotiate\n");
#endif

	RFCNB_Free_Pkt(pkt);
	SMBlib_errno = -SMBlibE_RecvFailed;	/* Failed, check lower layer errno */
	return (SMBlibE_BAD);

    }
    if (CVAL(SMB_Hdr(pkt), SMB_hdr_rcls_offset) != SMBC_SUCCESS) {	/* Process error */

#ifdef DEBUG
	fprintf(stderr, "SMB_Negotiate failed with errorclass = %i, Error Code = %i\n",
	    CVAL(SMB_Hdr(pkt), SMB_hdr_rcls_offset),
	    SVAL(SMB_Hdr(pkt), SMB_hdr_err_offset));
#endif

	SMBlib_SMB_Error = IVAL(SMB_Hdr(pkt), SMB_hdr_rcls_offset);
	RFCNB_Free_Pkt(pkt);
	SMBlib_errno = SMBlibE_Remote;
	return (SMBlibE_BAD);

    }
    if (SVAL(SMB_Hdr(pkt), SMB_negrCP_idx_offset) == 0xFFFF) {

#ifdef DEBUG
	fprintf(stderr, "None of our protocols was accepted ... ");
#endif

	RFCNB_Free_Pkt(pkt);
	SMBlib_errno = SMBlibE_NegNoProt;
	return (SMBlibE_BAD);

    }
    /* Now, unpack the info from the response, if any and evaluate the proto */
