        SMBlib_SMB_Error = IVAL(SMB_Hdr(pkt), SMB_hdr_rcls_offset);
        RFCNB_Free_Pkt(pkt);
        SMBlib_errno = SMBlibE_Remote;
        return(NULL);

    }

    tree -> tid = SVAL(SMB_Hdr(pkt), SMB_tconr_tid_offset);
    tree -> mbs = SVAL(SMB_Hdr(pkt), SMB_tconr_mbs_offset);

#ifdef DEBUG
    fprintf(stderr, "TConn succeeded, with TID=%i, Max Xmit=%i\n",
            tree -> tid, tree -> mbs);
#endif

    /* Now link the Tree to the Server Structure ... */

    if (Con_Handle -> first_tree == NULL) {

        Con_Handle -> first_tree = tree;
        Con_Handle -> last_tree = tree;

    } else {

        Con_Handle -> last_tree -> next = tree;
        tree -> prev = Con_Handle -> last_tree;
        Con_Handle -> last_tree = tree;

    }

    RFCNB_Free_Pkt(pkt);
    return(tree);

}

int SMB_TreeDisconnect(SMB_Tree_Handle Tree_Handle, BOOL discard)

{
    struct RFCNB_Pkt *pkt;
    int pkt_len;

    pkt_len = SMB_tdis_len;

    pkt = (struct RFCNB_Pkt *)RFCNB_Alloc_Pkt(pkt_len);

    if (pkt == NULL) {

        SMBlib_errno = SMBlibE_NoSpace;
        return(SMBlibE_BAD); /* Should handle the error */

    }

    /* Now plug in the values ... */

    memset(SMB_Hdr(pkt), 0, SMB_tdis_len);
    SIVAL(SMB_Hdr(pkt), SMB_hdr_idf_offset, SMB_DEF_IDF);  /* Plunk in IDF */
    *(SMB_Hdr(pkt) + SMB_hdr_com_offset) = SMBtdis;
    SSVAL(SMB_Hdr(pkt), SMB_hdr_pid_offset, Tree_Handle -> con -> pid);
    SSVAL(SMB_Hdr(pkt), SMB_hdr_mid_offset, Tree_Handle -> con -> mid);
    SSVAL(SMB_Hdr(pkt), SMB_hdr_uid_offset, Tree_Handle -> con -> uid);
    *(SMB_Hdr(pkt) + SMB_hdr_wct_offset) = 0;

    SSVAL(SMB_Hdr(pkt), SMB_hdr_tid_offset, Tree_Handle -> tid);
    SSVAL(SMB_Hdr(pkt), SMB_tcon_bcc_offset, 0);

    /* Now send the packet and sit back ... */

    if (RFCNB_Send(Tree_Handle -> con -> Trans_Connect, pkt, pkt_len) < 0) {

#ifdef DEBUG
        fprintf(stderr, "Error sending TDis request\n");
#endif

        RFCNB_Free_Pkt(pkt);
        SMBlib_errno = -SMBlibE_SendFailed;
        return(SMBlibE_BAD);

    }

    /* Now get the response ... */

    if (RFCNB_Recv(Tree_Handle -> con -> Trans_Connect, pkt, pkt_len) < 0) {

#ifdef DEBUG
        fprintf(stderr, "Error receiving response to TCon\n");
#endif

        RFCNB_Free_Pkt(pkt);
        SMBlib_errno = -SMBlibE_RecvFailed;
        return(SMBlibE_BAD);

    }

    /* Check out the response type ... */

    if (CVAL(SMB_Hdr(pkt), SMB_hdr_rcls_offset) != SMBC_SUCCESS) {  /* Process error */

#ifdef DEBUG
        fprintf(stderr, "SMB_TDis failed with errorclass = %i, Error Code = %i\n",
