     tmp = ntlm_fetch_string ((char *) auth, auth_length, &auth->ntresponse);
     if (tmp.str != NULL && tmp.l != 0) {
         debug("Empty NT pass detection: user: '%s', ours:'%s', his: '%s'"
-               "(length: %d)\n",
-               user,ntencoded_empty_pass,tmp.str,tmp.l);
+              "(length: %d)\n",
+              user,ntencoded_empty_pass,tmp.str,tmp.l);
         if (memcmp(tmp.str,lmencoded_empty_pass,ENCODED_PASS_LEN)==0) {
             fprintf(stderr,"Empty NT password supplied for user %s\\%s. "
                     "No-auth\n",domain,user);
