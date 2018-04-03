               auth_stat = xmalloc (sizeof (uerr_t));
               *auth_stat = RETROK;
 
+              if (ntlm)
+                www_authenticate = ntlm;
+              else if (digest)
+                www_authenticate = digest;
+              else
+                www_authenticate = basic;
+
+              logprintf (LOG_NOTQUIET, _("Authentication selected: %s\n"), www_authenticate);
+
               value =  create_authorization_line (www_authenticate,
                                                   user, passwd,
                                                   request_method (req),
