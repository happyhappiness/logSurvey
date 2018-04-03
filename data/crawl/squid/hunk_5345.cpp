 ACLChecklist::authenticated()
 {
     http_hdr_type headertype;
+
     if (NULL == request) {
-	fatal ("requiresRequest SHOULD have been true for this ACL!!");
-	return 0;
+        fatal ("requiresRequest SHOULD have been true for this ACL!!");
+        return 0;
     } else if (!request->flags.accelerated) {
-	/* Proxy authorization on proxy requests */
-	headertype = HDR_PROXY_AUTHORIZATION;
+        /* Proxy authorization on proxy requests */
+        headertype = HDR_PROXY_AUTHORIZATION;
     } else if (request->flags.internal) {
-	/* WWW authorization on accelerated internal requests */
-	headertype = HDR_AUTHORIZATION;
+        /* WWW authorization on accelerated internal requests */
+        headertype = HDR_AUTHORIZATION;
     } else {
 #if AUTH_ON_ACCELERATION
-	/* WWW authorization on accelerated requests */
-	headertype = HDR_AUTHORIZATION;
+        /* WWW authorization on accelerated requests */
+        headertype = HDR_AUTHORIZATION;
 #else
-	debug(28, 1) ("ACHChecklist::authenticated: authentication not applicable on accelerated requests.\n");
-	return -1;
+
+        debug(28, 1) ("ACHChecklist::authenticated: authentication not applicable on accelerated requests.\n");
+        return -1;
 #endif
+
     }
+
     /* get authed here */
     /* Note: this fills in auth_user_request when applicable */
     switch (authenticateTryToAuthenticateAndSetAuthUser(&auth_user_request, headertype, request, conn(), src_addr)) {
+
     case AUTH_ACL_CANNOT_AUTHENTICATE:
-	debug(28, 4) ("aclMatchAcl: returning  0 user authenticated but not authorised.\n");
-	return 0;
+        debug(28, 4) ("aclMatchAcl: returning  0 user authenticated but not authorised.\n");
+        return 0;
+
     case AUTH_AUTHENTICATED:
-	return 1;
-	break;
+        return 1;
+        break;
+
     case AUTH_ACL_HELPER:
-	debug(28, 4) ("aclMatchAcl: returning 0 sending credentials to helper.\n");
-	changeState (ProxyAuthLookup::Instance());
-	return 0;
+        debug(28, 4) ("aclMatchAcl: returning 0 sending credentials to helper.\n");
+        changeState (ProxyAuthLookup::Instance());
+        return 0;
+
     case AUTH_ACL_CHALLENGE:
-	debug(28, 4) ("aclMatchAcl: returning 0 sending authentication challenge.\n");
-	changeState (ProxyAuthNeeded::Instance());
-	return 0;
+        debug(28, 4) ("aclMatchAcl: returning 0 sending authentication challenge.\n");
+        changeState (ProxyAuthNeeded::Instance());
+        return 0;
+
     default:
-	fatal("unexpected authenticateAuthenticate reply\n");
-	return 0;
+        fatal("unexpected authenticateAuthenticate reply\n");
+        return 0;
     }
 }
 
