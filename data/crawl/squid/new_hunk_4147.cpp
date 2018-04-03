        debug("Got '%s' from Squid\n", buf);

    if (memcmp(buf, "YR ", 3) == 0) {	/* refresh-request */
        /* figure out what we got */
        decoded = base64_decode(buf + 3);
        /*  Note: we don't need to manage memory at this point, since
         *  base64_decode returns a pointer to static storage.
         */
        if (!decoded) {		/* decoding failure, return error */
            SEND("NA * Packet format error, couldn't base64-decode");
            return 1;
        }
        /* Obtain server blob against SSPI */
        plen = (strlen(buf) - 3) * 3 / 4;		/* we only need it here. Optimization */
        c = (char *) SSP_MakeNegotiateBlob(decoded, plen, &Done, &status, cred);

        if (status == SSP_OK) {
            if (Done) {
                lc(cred);		/* let's lowercase them for our convenience */
                have_serverblob = 0;
                Done = FALSE;
                if (Negotiate_packet_debug_enabled) {
                    printf("AF %s %s\n",c,cred);
                    decoded = base64_decode(c);
                    debug("sending 'AF' %s to squid with data:\n", cred);
                    hex_dump(decoded, (strlen(c) * 3) / 4);
                } else
                    SEND3("AF %s %s", c, cred);
            } else {
                if (Negotiate_packet_debug_enabled) {
                    printf("TT %s\n",c);
                    decoded = base64_decode(c);
                    debug("sending 'TT' to squid with data:\n");
                    hex_dump(decoded, (strlen(c) * 3) / 4);
                } else {
                    SEND2("TT %s", c);
