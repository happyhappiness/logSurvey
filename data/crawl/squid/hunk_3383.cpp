 
 CBDATA_CLASS_INIT(ACLFilledChecklist);
 
-#if MOVED
-int
-ACLFilledChecklist::authenticated()
-{
-    http_hdr_type headertype;
-
-    if (NULL == request) {
-        fatal ("requiresRequest SHOULD have been true for this ACL!!");
-        return 0;
-    } else if (request->flags.accelerated) {
-        /* WWW authorization on accelerated requests */
-        headertype = HDR_AUTHORIZATION;
-    } else if (request->flags.intercepted || request->flags.spoof_client_ip) {
-        debugs(28, DBG_IMPORTANT, HERE << " authentication not applicable on intercepted requests.");
-        return -1;
-    } else {
-        /* Proxy authorization on proxy requests */
-        headertype = HDR_PROXY_AUTHORIZATION;
-    }
-
-    /* get authed here */
-    /* Note: this fills in auth_user_request when applicable */
-    AuthAclState result = AuthUserRequest::tryToAuthenticateAndSetAuthUser(&auth_user_request, headertype, request, conn(), src_addr);
-    switch (result) {
-
-    case AUTH_ACL_CANNOT_AUTHENTICATE:
-        debugs(28, 4, "aclMatchAcl: returning  0 user authenticated but not authorised.");
-        return 0;
-
-    case AUTH_AUTHENTICATED:
-
-        return 1;
-        break;
-
-    case AUTH_ACL_HELPER:
-        debugs(28, 4, "aclMatchAcl: returning 0 sending credentials to helper.");
-        changeState (ProxyAuthLookup::Instance());
-        return 0;
-
-    case AUTH_ACL_CHALLENGE:
-        debugs(28, 4, "aclMatchAcl: returning 0 sending authentication challenge.");
-        changeState (ProxyAuthNeeded::Instance());
-        return 0;
-
-    default:
-        fatal("unexpected authenticateAuthenticate reply\n");
-        return 0;
-    }
-}
-#endif
-
 void
 ACLFilledChecklist::checkCallback(allow_t answer)
 {