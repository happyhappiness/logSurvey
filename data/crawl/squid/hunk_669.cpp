             break;
         }
 
-        option = strtok(NULL, ":,");
-    }
+        static const CharacterSet delims("TLS-option-delim",":,");
+        if (!tok.skipAll(delims) && !tok.atEnd()) {
+            fatalf("Unknown TLS option '" SQUIDSBUFPH "'", SQUIDSBUFPRINT(tok.remaining()));
+        }
 
-    safe_free(tmp);
-    }
+    } while (!tok.atEnd());
 
 #if SSL_OP_NO_SSLv2
     // compliance with RFC 6176: Prohibiting Secure Sockets Layer (SSL) Version 2.0
