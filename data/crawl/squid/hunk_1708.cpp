 
     if (!signingCert) {
         char buf[128];
-        fatalf("No valid signing SSL certificate configured for %s_port %s", protocol,  s.ToURL(buf, sizeof(buf)));
+        fatalf("No valid signing SSL certificate configured for %s_port %s", protocol,  s.toUrl(buf, sizeof(buf)));
     }
 
     if (!signPkey)
