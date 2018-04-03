             /** \par n
              * Set global option opt_signal_service (to true).
              * Stores the additional parameter given in global service_name */
-            // XXX: verify that the new name has ONLY alphanumeric characters
-            xfree(service_name);
-            service_name = xstrdup(optarg);
-            opt_signal_service = true;
+            if (optarg || *optarg == '\0') {
+                const SBuf t(optarg);
+                ::Parser::Tokenizer tok(t);
+                const CharacterSet chr = CharacterSet::ALPHA+CharacterSet::DIGIT;
+                if (!tok.prefix(service_name, chr) || !tok.atEnd())
+                    fatalf("Expected alphanumeric service name for the -n option but got: " SQUIDSBUFPH, SQUIDSBUFPRINT(service_name));
+                if (service_name.length() > 32)
+                    fatalf("Service name (-n option) must be limited to 32 characters but got %u", service_name.length());
+                opt_signal_service = true;
+            } else {
+                fatal("A service name is required for the -n option");
+            }
             break;
 
 #if USE_WIN32_SERVICE
