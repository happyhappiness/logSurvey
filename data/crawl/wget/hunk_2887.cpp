 
      - When matching against common names, it should loop over all
        common names and choose the most specific one, i.e. the last
-       one, not the first one, which the current code picks.  */
+       one, not the first one, which the current code picks.
+
+     - Make sure that the names are encoded as UTF-8 which, being
+       ASCII-compatible, can be easily compared against HOST.  */
 
-  peer_CN[0] = '\0';
-  X509_NAME_get_text_by_NID (X509_get_subject_name (peer_cert),
-			     NID_commonName, peer_CN, sizeof (peer_CN));
-  if (!pattern_match (peer_CN, host))
+  common_name[0] = '\0';
+  X509_NAME_get_text_by_NID (X509_get_subject_name (cert),
+			     NID_commonName, common_name, sizeof (common_name));
+  if (!pattern_match (common_name, host))
     {
       logprintf (LOG_NOTQUIET, _("\
 %s: certificate common name `%s' doesn't match requested host name `%s'.\n"),
-		 severity, escnonprint (peer_CN), escnonprint (host));
-      retval = 0;
+		 severity, escnonprint (common_name), escnonprint (host));
+      success = 0;
       goto out;
     }
 
   /* The certificate was found, verified, and matched HOST. */
-  retval = 1;
+  success = 1;
 
  out:
-  if (peer_cert)
-    X509_free (peer_cert);
+  if (cert)
+    X509_free (cert);
+
+  if (opt.check_cert && !success)
+    logprintf (LOG_NOTQUIET, _("\
+To connect to %s insecurely, use `--no-check-certificate'.\n"),
+	       escnonprint (host));
 
   /* Allow --no-check-cert to disable certificate checking. */
-  return opt.check_cert ? retval : 1;
+  return opt.check_cert ? success : 1;
 }
