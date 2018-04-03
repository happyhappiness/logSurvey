
#if 1
    debug("Empty LM pass detection: user: '%s', ours:'%s', his: '%s'"
           "(length: %d)\n",
           user,lmencoded_empty_pass,tmp.str,tmp.l);
    if (memcmp(tmp.str,lmencoded_empty_pass,ENCODED_PASS_LEN)==0) {
        fprintf(stderr,"Empty LM password supplied for user %s\\%s. "
                "No-auth\n",domain,user);
