     memcpy(user, tmp.str, tmp.l);
     *(user + tmp.l) = '\0';
 
-    /* Authenticating against the NT response doesn't seem to work... */
-    tmp = ntlm_fetch_string(&(auth->hdr), auth_length, &auth->lmresponse, auth->flags);
-    if (tmp.str == NULL || tmp.l == 0) {
-        fprintf(stderr, "No auth at all. Returning no-auth\n");
-        ntlm_errno = NTLM_ERR_LOGON;
-        return NULL;
+    // grab the *response blobs. these are fixed length 24 bytes of binary
+    const ntlmhdr *packet = &(auth->hdr);
+    {
+        const strhdr * str = &auth->lmresponse;
+
+        int16_t len = le16toh(str->len);
+        int32_t offset = le32toh(str->offset);
+
+        if (len != ENCODED_PASS_LEN || offset + len > auth_length || offset == 0) {
+            debug("LM response: insane data (pkt-sz: %d, fetch len: %d, offset: %d)\n", auth_length, len, offset);
+            ntlm_errno = NTLM_ERR_LOGON;
+            return NULL;
+        }
+        tmp.str = (char *)packet + offset;
+        tmp.l = len;
     }
     if (tmp.l > MAX_PASSWD_LEN) {
         debug("Password string exceeds %d bytes, rejecting\n", MAX_PASSWD_LEN);
         ntlm_errno = NTLM_ERR_LOGON;
         return NULL;
     }
 
+    /* Authenticating against the NT response doesn't seem to work... in SMB LM helper. */
     memcpy(pass, tmp.str, tmp.l);
     pass[min(MAX_PASSWD_LEN,tmp.l)] = '\0';
 
