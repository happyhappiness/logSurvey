  * there is enough space in the payload string to accommodate the
  * added value.
  * payload_length and hdr will be modified as a side-effect.
- * base_offset is the payload offset from the packet's beginning, and is
  */
 void
-ntlm_add_to_payload(char *payload, int *payload_length,
-                    strhdr * hdr, char *toadd,
-                    int toadd_length, int base_offset)
+ntlm_add_to_payload(const ntlmhdr *packet_hdr,
+                    char *payload,
+                    int *payload_length,
+                    strhdr * hdr,
+                    const char *toadd,
+                    const int toadd_length)
 {
-
     int l = (*payload_length);
     memcpy(payload + l, toadd, toadd_length);
 
     hdr->len = htole16(toadd_length);
     hdr->maxlen = htole16(toadd_length);
-    hdr->offset = htole32(l + base_offset);	/* 48 is the base offset of the payload */
+    hdr->offset = htole32(l + payload - (char*)packet_hdr);
     (*payload_length) += toadd_length;
 }
 
 
+/* ************************************************************************* */
+/* Negotiate Packet functions */
+/* ************************************************************************* */
+
+// ??
+
+
+/* ************************************************************************* */
+/* Challenge Packet functions */
+/* ************************************************************************* */
+
+/* 
+ * Generates a challenge request nonce. The randomness of the 8 byte
+ * challenge strings can be guarenteed to be poor at best.
+ */
+void
+ntlm_make_nonce(char *nonce)
+{
+    static unsigned hash;
+    int i;
+    int r = (int) rand();
+    r = (hash ^ r) + r;
+
+    for (i = 0; i < NTLM_NONCE_LEN; i++) {
+        nonce[i] = r;
+        r = (r >> 2) ^ r;
+    }
+    hash = r;
+}
+
+#if DEAD_API
 /**
  * Prepares a base64-encode challenge packet to be sent to the client
  * \note domain should be upper_case
  * \note the storage type for the returned value depends on
  *    base64_encode_bin. Currently this means static storage.
  */
-const char *
-ntlm_make_challenge(char *domain, char *domain_controller,
-                    char *challenge_nonce, int challenge_nonce_len)
+void
+ntlm_make_challenge(const char *domain, const char *dc_UNUSED,
+                    const char *cn, const int cnl)
+{
+    /* This function API has changes somewhat, and not all user helpers */
+    ntlm_challenge chal;
+
+    /*  ORIGINAL flags was HARD-CODED set to these:
+        TODO: find all old callers (without flags field) and have them send these in manually now...
+    */
+    u_int32_t flags = REQUEST_NON_NT_SESSION_KEY |
+                      CHALLENGE_TARGET_IS_DOMAIN |
+                      NEGOTIATE_ALWAYS_SIGN |
+                      NEGOTIATE_USE_NTLM |
+                      NEGOTIATE_USE_LM |
+                      NEGOTIATE_ASCII;
+
+    ntlm_make_challenge(&chal, domain, dc_UNUSED, cn, cnl, flags);
+
+/*  ORIGINAL handling of ntlm_challenge object was to encode it like this:
+    TODO: find all old callers and have them do teh decode themselves now.
+*/
+    return base64_encode_bin((char *)&chal, NTLM_CHALLENGE_HEADER_OFFSET + pl);
+}
+#endif
+
+/**
+ * Prepares a challenge packet to be sent to the client
+ * \note domain should be upper_case
+ */
+void
+ntlm_make_challenge(ntlm_challenge *ch,
+                    const char *domain, const char *domain_controller_UNUSED,
+                    const char *challenge_nonce, const int challenge_nonce_len,
+                    const u_int32_t flags)
 {
-    ntlm_challenge ch;
     int pl = 0;
-    const char *encoded;
-    memset(&ch, 0, sizeof(ntlm_challenge));	/* reset */
-    memcpy(ch.hdr.signature, "NTLMSSP", 8);		/* set the signature */
-    ch.hdr.type = htole32(NTLM_CHALLENGE);	/* this is a challenge */
-    ntlm_add_to_payload(ch.payload, &pl, &ch.target, domain, strlen(domain),
-                        NTLM_CHALLENGE_HEADER_OFFSET);
-    ch.flags = htole32(
-                   REQUEST_NON_NT_SESSION_KEY |
-                   CHALLENGE_TARGET_IS_DOMAIN |
-                   NEGOTIATE_ALWAYS_SIGN |
-                   NEGOTIATE_USE_NTLM |
-                   NEGOTIATE_USE_LM |
-                   NEGOTIATE_ASCII |
-                   0
-               );
-    ch.context_low = 0;		/* check this out */
-    ch.context_high = 0;
-    memcpy(ch.challenge, challenge_nonce, challenge_nonce_len);
-    encoded = base64_encode_bin((char *) &ch, NTLM_CHALLENGE_HEADER_OFFSET + pl);
-    return encoded;
+    memset(ch, 0, sizeof(ntlm_challenge));	/* reset */
+    memcpy(ch->hdr.signature, "NTLMSSP", 8);		/* set the signature */
+    ch->hdr.type = htole32(NTLM_CHALLENGE);	/* this is a challenge */
+    if (domain != NULL) {
+        ntlm_add_to_payload(&ch->hdr, ch->payload, &pl, &ch->target, domain, strlen(domain));
+    }
+    ch->flags = htole32(flags);
+    ch->context_low = 0;		/* check this out */
+    ch->context_high = 0;
+    memcpy(ch->challenge, challenge_nonce, challenge_nonce_len);
+}
+
+/* ************************************************************************* */
+/* Authenticate Packet functions */
+/* ************************************************************************* */
+
+/**
+ * Unpack the strings in an NTLM authentication response from client.
+ * The caller is responsible for initializing the user and domain buffers
+ * this function will only insert data if the packet contains any. Otherwise
+ * the buffers will be left untouched.
+ *
+ * \retval -1	packet type is not an authentication packet.
+ * \retval  0	username present and maybe also domain.
+ * \retval  1	no username.
+ */
+int
+ntlm_unpack_auth(const ntlm_authenticate *auth, char *user, char *domain, const int32_t size)
+{
+    const char *p;
+    unsigned int s;
+    lstring rv;
+
+    if (ntlm_validate_packet(&auth->hdr, NTLM_AUTHENTICATE)) {
+        fprintf(stderr, "ntlmDecodeAuth: header check fails\n");
+        return -1;
+    }
+    debug("ntlmDecodeAuth: size of %d\n", size);
+    debug("ntlmDecodeAuth: flg %08x\n", auth->flags);
+    debug("ntlmDecodeAuth: usr o(%d) l(%d)\n", auth->user.offset, auth->user.len);
+
+    rv = ntlm_fetch_string(&auth->hdr, size, &auth->domain, auth->flags);
+    if (rv.l > 0) {
+        memcpy(rv.str, domain, rv.l);
+        domain[rv.l] = '\0';
+        debug("ntlm_unpack_auth: Domain '%s'.\n", domain);
+    }
+    if (rv.l >= size)
+        return 1;
+
+    rv = ntlm_fetch_string(&auth->hdr, size, &auth->user, auth->flags);
+    if (rv.l > 0) {
+        memcpy(rv.str, user, rv.l);
+        user[rv.l] = '\0';
+        debug("ntlm_unpack_auth: Username '%s'.\n", user);
+    } else
+        return 1;
+
+    return 0;
 }