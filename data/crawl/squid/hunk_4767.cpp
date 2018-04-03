 	fprintf(stderr, "ntlmGetString: insane: l:%d o:%d\n", l, o);
 	return (NULL);
     }
-    if ((flags & 2) == 0) {
+    if ((flags & NEGOTIATE_ASCII) == 0) {
 	/* UNICODE string */
 	s = (u_short *) ((char *) hdr + o);
 	d = buf;
 
 	for (l >>= 1; l; s++, l--) {
 	    c = le16toh(*s);
-	    if (c > 254 || c == '\0' || !isprint(c)) {
+	    if (c > 254 || c == '\0') {
 		fprintf(stderr, "ntlmGetString: bad uni: %04x\n", c);
 		return (NULL);
 	    }
 	    *d++ = c;
-	    fprintf(stderr, "ntlmGetString: conv: '%c'\n", c);
 	}
 
 	*d = 0;
     } else {
-	/* ASCII string */
+	/* ASCII/OEM string */
 	sc = (char *) hdr + o;
 	d = buf;
 
 	for (; l; l--) {
-	    if (*sc == '\0' || !isprint((int)(unsigned char)*sc)) {
+	    if (*sc == '\0' || !isprint((int) (unsigned char) *sc)) {
 		fprintf(stderr, "ntlmGetString: bad ascii: %04x\n", *sc);
 		return (NULL);
 	    }
