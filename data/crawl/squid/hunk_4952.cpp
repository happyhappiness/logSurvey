         list = list->next;
     }
 
-    storeAppendPrintf(entry, "\n%s %s children %d\n%s %s max_challenge_reuses %d\n%s %s max_challenge_lifetime %d seconds\n",
-                      name, "ntlm", authenticateChildren,
-                      name, "ntlm", challengeuses,
-                      name, "ntlm", (int) challengelifetime);
+    storeAppendPrintf(entry, "\n%s ntlm children %d\n",
+                      name, authenticateChildren);
+    storeAppendPrintf(entry, "%s %s keep_alive %s\n", name, "ntlm", keep_alive ? "on" : "off");
 
 }
 
-AuthNTLMConfig::AuthNTLMConfig()
-{
-    /* TODO Move into initialisation list */
-    authenticateChildren = 5;
-    challengeuses = 0;
-    challengelifetime = 60;
-}
+AuthNTLMConfig::AuthNTLMConfig() : authenticateChildren(5), keep_alive(1)
+{ }
 
 void
 AuthNTLMConfig::parse(AuthConfig * scheme, int n_configured, char *param_str)
