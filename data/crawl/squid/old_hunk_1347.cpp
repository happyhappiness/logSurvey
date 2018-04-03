
    /* NP: for some reason this helper sometimes needs to accept
     * from clients that send no negotiate packet. */
    if (memcpy(local_nego.signature, "NTLMSSP", 8) != 0) {
        memset(&local_nego, 0, sizeof(ntlm_negotiate));	/* reset */
        memcpy(local_nego.signature, "NTLMSSP", 8);     /* set the signature */
        local_nego.type = le32toh(NTLM_NEGOTIATE);      /* this is a challenge */
        local_nego.flags = le32toh(NTLM_NEGOTIATE_ALWAYS_SIGN |
                                   NTLM_NEGOTIATE_USE_NTLM |
                                   NTLM_NEGOTIATE_USE_LM |
                                   NTLM_NEGOTIATE_ASCII );
    }

try_again:
    if (fgets(buf, BUFFER_SIZE, stdin) == NULL)
        return 0;

    c = memchr(buf, '\n', BUFFER_SIZE);	/* safer against overrun than strchr */
    if (c) {
        if (oversized) {
            helperfail("illegal request received");
            fprintf(stderr, "Illegal request received: '%s'\n", buf);
            return 1;
        }
        *c = '\0';
    } else {
        fprintf(stderr, "No newline in '%s'\n", buf);
        oversized = 1;
        goto try_again;
    }
    if ((strlen(buf) > 3) && NTLM_packet_debug_enabled) {
        decodedLen = base64_decode(decoded, sizeof(decoded), buf+3);
        strncpy(helper_command, buf, 2);
        debug("Got '%s' from Squid with data:\n", helper_command);
        hex_dump(decoded, decodedLen);
    } else
        debug("Got '%s' from Squid\n", buf);
    if (memcmp(buf, "YR", 2) == 0) {	/* refresh-request */
