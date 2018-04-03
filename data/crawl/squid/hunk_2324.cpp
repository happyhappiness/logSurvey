     int32_t o;			/* offset */
     static char buf[NTLM_MAX_FIELD_LENGTH];
     lstring rv;
-    unsigned short *s, c;
-    char *d, *sc;
+    char *d;
 
     lstring_zero(rv);
 
     l = le16toh(str->len);
     o = le32toh(str->offset);
-    /* debug("fetch_string(plength=%d,l=%d,o=%d)\n",packet_size,l,o); */
+    // debug("ntlm_fetch_string(plength=%d,l=%d,o=%d)\n",packet_size,l,o);
 
     if (l < 0 || l > NTLM_MAX_FIELD_LENGTH || o + l > packet_size || o == 0) {
-        /* debug("ntlmssp: insane data (l: %d, o: %d)\n", l,o); */
+        debug("ntlm_fetch_string: insane data (pkt-sz: %d, fetch len: %d, offset: %d)\n", packet_size,l,o);
         return rv;
     }
     rv.str = (char *)packet + o;
     if ((flags & NTLM_NEGOTIATE_ASCII) == 0) {
         /* UNICODE string */
-        s = (unsigned short *) ((char *) packet + o);
+        unsigned short *s = (unsigned short *)rv.str;
         rv.str = d = buf;
 
         for (l >>= 1; l; s++, l--) {
-            c = le16toh(*s);
+            unsigned short c = le16toh(*s);
             if (c > 254 || c == '\0') {
                 fprintf(stderr, "ntlmssp: bad unicode: %04x\n", c);
                 return rv;
