    lstring rv;

    if (ntlm_validate_packet(&auth->hdr, NTLM_AUTHENTICATE)) {
        fprintf(stderr, "ntlmDecodeAuth: header check fails\n");
        return NTLM_ERR_PROTOCOL;
    }
    debug("ntlmDecodeAuth: size of %d\n", size);
    debug("ntlmDecodeAuth: flg %08x\n", auth->flags);
    debug("ntlmDecodeAuth: usr o(%d) l(%d)\n", auth->user.offset, auth->user.len);

    rv = ntlm_fetch_string(&auth->hdr, size, &auth->domain, auth->flags);
    if (rv.l > 0) {
        memcpy(rv.str, domain, rv.l);
        domain[rv.l] = '\0';
        debug("ntlm_unpack_auth: Domain '%s'.\n", domain);
    }
    if (rv.l >= size) {
        debug("ntlm_unpack_auth: Domain length %d too big for %d byte packet.\n", rv.l , size);
