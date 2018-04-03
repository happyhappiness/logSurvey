     return op;
 }
 
+long
+Security::ParseFlags(const SBuf &flags)
+{
+    if (flags.isEmpty())
+        return 0;
+
+    static struct {
+        SBuf label;
+        long mask;
+    } flagTokens[] = {
+        { SBuf("NO_DEFAULT_CA"), SSL_FLAG_NO_DEFAULT_CA },
+        { SBuf("DELAYED_AUTH"), SSL_FLAG_DELAYED_AUTH },
+        { SBuf("DONT_VERIFY_PEER"), SSL_FLAG_DONT_VERIFY_PEER },
+        { SBuf("DONT_VERIFY_DOMAIN"), SSL_FLAG_DONT_VERIFY_DOMAIN },
+        { SBuf("NO_SESSION_REUSE"), SSL_FLAG_NO_SESSION_REUSE },
+#if X509_V_FLAG_CRL_CHECK
+        { SBuf("VERIFY_CRL"), SSL_FLAG_VERIFY_CRL },
+        { SBuf("VERIFY_CRL_ALL"), SSL_FLAG_VERIFY_CRL_ALL },
+#endif
+        { SBuf(), 0 }
+    };
+
+    ::Parser::Tokenizer tok(flags);
+    static const CharacterSet delims("Flag-delimiter", ":,");
+
+    long fl = 0;
+    do {
+        long found = 0;
+        for (size_t i = 0; flagTokens[i].mask; ++i) {
+            if (tok.skip(flagTokens[i].label) == 0) {
+                found = flagTokens[i].mask;
+                break;
+            }
+        }
+        if (!found)
+            fatalf("Unknown SSL flag '" SQUIDSBUFPH "'", SQUIDSBUFPRINT(tok.remaining()));
+        fl |= found;
+    } while (tok.skipOne(delims));
+
+    return fl;
+}
+
 void
 parse_securePeerOptions(Security::PeerOptions *opt)
 {
