
    if (pkt == NULL) {

        RFCNB_errno = RFCNBE_NoSpace;
        RFCNB_saved_errno = errno;
        return (RFCNBE_Bad);

    }
    pkt->next = Data;		/* Plug in the data portion */

    if ((ret_len = RFCNB_Get_Pkt(con_Handle, pkt, Length + RFCNB_Pkt_Hdr_Len)) < 0) {

#ifdef RFCNB_DEBUG
        fprintf(stderr, "Bad packet return in RFCNB_Recv... \n");
#endif

        return (RFCNBE_Bad);

    }
    /* We should check that we go a message and not a keep alive */