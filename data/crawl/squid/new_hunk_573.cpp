    {
        const strhdr * str = &auth->ntresponse;
        int16_t len = le16toh(str->len);
        // NT response field may be absent. that is okay.
        if (len != 0) {
            int32_t offset = le32toh(str->offset);

            if (len != ENCODED_PASS_LEN || offset + len > auth_length || offset == 0) {
                debug("NT response: insane data (pkt-sz: %d, fetch len: %d, offset: %d)\n", auth_length, len, offset);
                ntlm_errno = NTLM_ERR_LOGON;
                return NULL;
            }
            tmp.str = (char *)packet + offset;
            tmp.l = len;

            debug("Empty NT pass detection: user: '%s', ours:'%s', his: '%s' (length: %d)\n",
                  user,ntencoded_empty_pass,tmp.str,tmp.l);
            if (memcmp(tmp.str,lmencoded_empty_pass,ENCODED_PASS_LEN)==0) {
                fprintf(stderr,"ERROR: Empty NT password supplied for user %s\\%s. No-auth\n", domain, user);
                ntlm_errno = NTLM_ERR_LOGON;
                return NULL;
            }
        }
    }

    debug("checking domain: '%s', user: '%s', pass='%s'\n", domain, user, pass);
