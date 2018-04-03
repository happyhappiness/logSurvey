         unsigned short *s = (unsigned short *)rv.str;
         rv.str = d = buf;
 
-        for (l >>= 1; l; s++, l--) {
+        for (l >>= 1; l; ++s, --l) {
             unsigned short c = le16toh(*s);
             if (c > 254 || c == '\0') {
                 fprintf(stderr, "ntlmssp: bad unicode: %04x\n", c);
                 return rv;
             }
             *d++ = c;
-            rv.l++;
+            ++rv.l;
         }
     } else {
         /* ASCII/OEM string */
         char *sc = rv.str;
 
-        for (; l>=0; sc++, l--) {
+        for (; l>=0; ++sc, --l) {
             if (*sc == '\0' || !xisprint(*sc)) {
                 fprintf(stderr, "ntlmssp: bad ascii: %04x\n", *sc);
                 return rv;
             }
-            rv.l++;
+            ++rv.l;
         }
     }
 
