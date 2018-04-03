     basic_auth = static_cast<basic_data *>(auth_user->scheme_data);
 
     /* if the password is not ok, do an identity */
+
     if (basic_auth->flags.credentials_ok != 1)
-	return;
+        return;
 
     /* are we about to recheck the credentials externally? */
     if ((basic_auth->credentials_checkedtime + basicConfig->credentialsTTL) <= squid_curtime) {
-	debug(29, 4) ("authBasicAuthenticate: credentials expired - rechecking\n");
-	return;
+        debug(29, 4) ("authBasicAuthenticate: credentials expired - rechecking\n");
+        return;
     }
+
     /* we have been through the external helper, and the credentials haven't expired */
     debug(29, 9) ("authenticateBasicAuthenticateuser: user '%s' authenticated\n",
-	basic_auth->username);
+                  basic_auth->username);
 
     /* Decode now takes care of finding the auth_user struct in the cache */
     /* after external auth occurs anyway */
     auth_user->expiretime = current_time.tv_sec;
+
     return;
 }
 
 int
 authenticateBasicDirection(auth_user_request_t * auth_user_request)
 {
-/* null auth_user is checked for by authenticateDirection */
+    /* null auth_user is checked for by authenticateDirection */
     auth_user_t *auth_user = auth_user_request->auth_user;
     basic_data *basic_auth = static_cast<basic_data *>(auth_user->scheme_data);
+
     switch (basic_auth->flags.credentials_ok) {
+
     case 0:			/* not checked */
-	return -1;
+        return -1;
+
     case 1:			/* checked & ok */
-	if (basic_auth->credentials_checkedtime + basicConfig->credentialsTTL <= squid_curtime)
-	    return -1;
-	return 0;
+
+        if (basic_auth->credentials_checkedtime + basicConfig->credentialsTTL <= squid_curtime)
+            return -1;
+
+        return 0;
+
     case 2:			/* paused while waiting for a username:password check on another request */
-	return -1;
+        return -1;
+
     case 3:			/* authentication process failed. */
-	return -2;
+        return -2;
     }
+
     return -2;
 }
 
 void
 authenticateBasicFixErrorHeader(auth_user_request_t * auth_user_request, HttpReply * rep, http_hdr_type type, request_t * request)
 {
     if (basicConfig->authenticate) {
-	debug(29, 9) ("authenticateFixErrorHeader: Sending type:%d header: 'Basic realm=\"%s\"'\n", type, basicConfig->basicAuthRealm);
-	httpHeaderPutStrf(&rep->header, type, "Basic realm=\"%s\"", basicConfig->basicAuthRealm);
+        debug(29, 9) ("authenticateFixErrorHeader: Sending type:%d header: 'Basic realm=\"%s\"'\n", type, basicConfig->basicAuthRealm);
+        httpHeaderPutStrf(&rep->header, type, "Basic realm=\"%s\"", basicConfig->basicAuthRealm);
     }
 }
 
