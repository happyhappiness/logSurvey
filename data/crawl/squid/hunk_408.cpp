         }
         sslFlags = SBuf(token + 6);
         parsedFlags = parseFlags();
-    } else if (strncmp(token, "no-default-ca", 13) == 0) {
-        flags.tlsDefaultCa = false;
+    } else if (strncmp(token, "default-ca=off", 14) == 0 || strncmp(token, "no-default-ca", 13) == 0) {
+        if (flags.tlsDefaultCa.configured() && flags.tlsDefaultCa)
+            fatalf("ERROR: previous default-ca settings conflict with %s", token);
+        flags.tlsDefaultCa.configure(false);
+    } else if (strncmp(token, "default-ca=on", 13) == 0 || strncmp(token, "default-ca", 10) == 0) {
+        if (flags.tlsDefaultCa.configured() && !flags.tlsDefaultCa)
+            fatalf("ERROR: previous default-ca settings conflict with %s", token);
+        flags.tlsDefaultCa.configure(true);
     } else if (strncmp(token, "domain=", 7) == 0) {
         sslDomain = SBuf(token + 7);
     } else if (strncmp(token, "no-npn", 6) == 0) {
