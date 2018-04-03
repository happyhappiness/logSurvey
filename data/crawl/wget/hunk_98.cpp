         }
     }
 
+    pinsuccess = pkp_pin_peer_pubkey (cert, opt.pinnedpubkey);
+    if (!pinsuccess)
+      {
+        logprintf (LOG_ALWAYS, _("The public key does not match pinned public key!\n"));
+        success = false;
+      }
+
 
   if (success)
     DEBUGP (("X509 certificate successfully verified and matches host %s\n",
