
    if (ntlm_validate_packet(&auth->hdr, NTLM_AUTHENTICATE)) {
        fprintf(stderr, "ntlmDecodeAuth: header check fails\n");
        return -1;
    }
    debug("ntlmDecodeAuth: size of %d\n", size);
    debug("ntlmDecodeAuth: flg %08x\n", auth->flags);
