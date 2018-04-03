    }

    /* Now send it and get a response */

    if (RFCNB_Send(Con_Handle->Trans_Connect, pkt, pkt_len) < 0) {

#ifdef DEBUG
        fprintf(stderr, "Error sending SessSetupX request\n");
#endif

        RFCNB_Free_Pkt(pkt);
        SMBlib_errno = SMBlibE_SendFailed;
        return (SMBlibE_BAD);

    }
    /* Now get the response ... */

    if (RFCNB_Recv(Con_Handle->Trans_Connect, pkt, pkt_len) < 0) {

#ifdef DEBUG
        fprintf(stderr, "Error receiving response to SessSetupAndX\n");
#endif

        RFCNB_Free_Pkt(pkt);
        SMBlib_errno = SMBlibE_RecvFailed;
        return (SMBlibE_BAD);

    }
    /* Check out the response type ... */

    if (CVAL(SMB_Hdr(pkt), SMB_hdr_rcls_offset) != SMBC_SUCCESS) {	/* Process error */

#ifdef DEBUG
        fprintf(stderr, "SMB_SessSetupAndX failed with errorclass = %i, Error Code = %i\n",
                CVAL(SMB_Hdr(pkt), SMB_hdr_rcls_offset),
                SVAL(SMB_Hdr(pkt), SMB_hdr_err_offset));
#endif

        SMBlib_SMB_Error = IVAL(SMB_Hdr(pkt), SMB_hdr_rcls_offset);
        RFCNB_Free_Pkt(pkt);
        SMBlib_errno = SMBlibE_Remote;
        return (SMBlibE_BAD);

    }
    /** @@@ mdz: check for guest login { **/
    if (SVAL(SMB_Hdr(pkt), SMB_ssetpr_act_offset) & 0x1) {
        /* do we allow guest login? NO! */
        return (SMBlibE_BAD);

    }
    /** @@@ mdz: } **/


#ifdef DEBUG
    fprintf(stderr, "SessSetupAndX response. Action = %i\n",
            SVAL(SMB_Hdr(pkt), SMB_ssetpr_act_offset));
#endif

    /* Now pick up the UID for future reference ... */

    Con_Handle->uid = SVAL(SMB_Hdr(pkt), SMB_hdr_uid_offset);
    RFCNB_Free_Pkt(pkt);

    return (0);

}


/* Disconnect from the server, and disconnect all tree connects */

int
SMB_Discon(SMB_Handle_Type Con_Handle, BOOL KeepHandle)
{

    /* We just disconnect the connection for now ... */
    if (Con_Handle != NULL)
        RFCNB_Hangup(Con_Handle->Trans_Connect);
