 
     if (!untrustedSigningCert) {
         char buf[128];
-        fatalf("Unable to generate  signing SSL certificate for untrusted sites for %s_port %s", protocol, s.ToURL(buf, sizeof(buf)));
+        fatalf("Unable to generate  signing SSL certificate for untrusted sites for %s_port %s", protocol, s.toUrl(buf, sizeof(buf)));
     }
 
     if (crlfile)
