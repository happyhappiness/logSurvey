 }
 
 /**
+ * Locates the FTP user:password login.
+ *
+ * Highest to lowest priority:
+ *  - Checks URL (ftp://user:pass@domain)
+ *  - Authorization: Basic header
+ *  - squid.conf anonymous-FTP settings (default: anonymous:Squid@).
+ *
+ * Special Case: A username-only may be provided in the URL and password in the HTTP headers.
+ *
  \retval 1	if we have everything needed to complete this request.
  \retval 0	if something is missing.
  */
 int
 FtpStateData::checkAuth(const HttpHeader * req_hdr)
 {
-    char *orig_user;
     const char *auth;
-    loginParser(request->login, FTP_LOGIN_ESCAPED);
-
-    if (!user[0])
-        return 1;		/* no name */
 
-    if (password_url || password[0])
-        return 1;		/* passwd provided in URL */
+    /* default username */
+    xstrncpy(user, "anonymous", MAX_URL);
 
-    /* URL has name, but no passwd */
-    if (!(auth = req_hdr->getAuth(HDR_AUTHORIZATION, "Basic")))
-        return 0;		/* need auth header */
+    /* Check HTTP Authorization: headers (better than defaults, but less than URL) */
+    if ( (auth = req_hdr->getAuth(HDR_AUTHORIZATION, "Basic")) ) {
+        flags.authenticated = 1;
+        loginParser(auth, FTP_LOGIN_NOT_ESCAPED);
+    }
+    /* we fail with authorization-required error later IFF the FTP server requests it */
 
-    flags.authenticated = 1;
+    /* Test URL login syntax. Overrides any headers received. */
+    loginParser(request->login, FTP_LOGIN_ESCAPED);
 
-    orig_user = xstrdup(user);
+    /* name is missing. thats fatal. */
+    if (!user[0])
+        fatal("FTP login parsing destroyed username info");
 
-    loginParser(auth, FTP_LOGIN_NOT_ESCAPED);
+    /* name + password == success */
+    if (password[0])
+        return 1;
 
-    if (strcmp(orig_user, user) == 0) {
-        xfree(orig_user);
-        return 1;		/* same username */
+    /* Setup default FTP password settings */
+    /* this has to be done last so that we can have a no-password case above. */
+    if (!password[0]) {
+        if (strcmp(user, "anonymous") == 0)
+            xstrncpy(password, Config.Ftp.anon_user, MAX_URL);
+        else
+            xstrncpy(password, null_string, MAX_URL);
     }
 
-    xstrncpy(user, orig_user, sizeof(user));
-    xfree(orig_user);
     return 0;			/* different username */
 }
 
