    /* Now send the packet */

#ifdef RFCNB_DEBUG

    fprintf(stderr, "Sending packet: ");

#endif

    if ((len = RFCNB_Put_Pkt(con, pkt, RFCNB_Pkt_Sess_Len)) < 0) {

        return(RFCNBE_Bad);       /* Should be able to write that lot ... */

    }

#ifdef RFCNB_DEBUG

    fprintf(stderr, "Getting packet.\n");

#endif

    res_pkt.data = resp;
    res_pkt.len  = sizeof(resp);
    res_pkt.next = NULL;

    if ((len = RFCNB_Get_Pkt(con, &res_pkt, sizeof(resp))) < 0) {

        return(RFCNBE_Bad);

    }

    /* Now analyze the packet ... */

    switch (RFCNB_Pkt_Type(resp)) {

    case RFCNB_SESSION_REJ:         /* Didnt like us ... too bad */

        /* Why did we get rejected ? */

        switch (CVAL(resp,RFCNB_Pkt_Error_Offset)) {

        case 0x80:
            RFCNB_errno = RFCNBE_CallRejNLOCN;
