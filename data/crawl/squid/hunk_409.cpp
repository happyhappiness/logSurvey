         if (!found)
             fatalf("Unknown TLS flag '" SQUIDSBUFPH "'", SQUIDSBUFPRINT(tok.remaining()));
         if (found == SSL_FLAG_NO_DEFAULT_CA) {
-            debugs(83, DBG_PARSE_NOTE(2), "UPGRADE WARNING: flags=NO_DEFAULT_CA is deprecated. Use tls-no-default-ca instead.");
-            flags.tlsDefaultCa = false;
+            if (flags.tlsDefaultCa.configured() && flags.tlsDefaultCa)
+                fatal("ERROR: previous default-ca settings conflict with sslflags=NO_DEFAULT_CA");
+            debugs(83, DBG_PARSE_NOTE(2), "WARNING: flags=NO_DEFAULT_CA is deprecated. Use tls-default-ca=off instead.");
+            flags.tlsDefaultCa.configure(false);
         } else
             fl |= found;
     } while (tok.skipOne(delims));
