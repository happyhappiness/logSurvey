 const char *
 AuthBasicConfig::type() const
 {
-    return basicScheme::GetInstance().type();
+    return basicScheme::GetInstance()->type();
 }
 
-AuthBasicUserRequest::AuthBasicUserRequest() : _theUser(NULL)
-{}
+int32_t
+BasicUser::ttl() const
+{
+    if (credentials() != Ok && credentials() != Pending)
+        return -1; // TTL is obsolete NOW.
 
-AuthBasicUserRequest::~AuthBasicUserRequest()
-{}
+    int32_t basic_ttl = expiretime - squid_curtime + static_cast<AuthBasicConfig*>(config)->credentialsTTL;
+    int32_t global_ttl = static_cast<int32_t>(expiretime - squid_curtime + Config.authenticateTTL);
 
+    return min(basic_ttl, global_ttl);
+}
 
 bool
 BasicUser::authenticated() const
 {
-    if ((flags.credentials_ok == 1) && (credentials_checkedtime + basicConfig.credentialsTTL > squid_curtime))
+    if ((credentials() == Ok) && (expiretime + static_cast<AuthBasicConfig*>(config)->credentialsTTL > squid_curtime))
         return true;
 
     debugs(29, 4, "User not authenticated or credentials need rechecking.");
 
     return false;
 }
 
-int
-AuthBasicUserRequest::authenticated() const
-{
-    BasicUser const *basic_auth = dynamic_cast<BasicUser const *>(user());
-
-    if (basic_auth && basic_auth->authenticated())
-        return 1;
-
-    return 0;
-}
-
-/* log a basic user in
- */
 void
-AuthBasicUserRequest::authenticate(HttpRequest * request, ConnStateData * conn, http_hdr_type type)
+AuthBasicConfig::fixHeader(AuthUserRequest::Pointer auth_user_request, HttpReply *rep, http_hdr_type hdrType, HttpRequest * request)
 {
-    assert(user() != NULL);
-
-    basic_data *basic_auth = dynamic_cast<BasicUser *>(user());
-
-    /* if the password is not ok, do an identity */
-
-    if (!basic_auth || basic_auth->flags.credentials_ok != 1)
-        return;
-
-    /* are we about to recheck the credentials externally? */
-    if ((basic_auth->credentials_checkedtime + basicConfig.credentialsTTL) <= squid_curtime) {
-        debugs(29, 4, "authBasicAuthenticate: credentials expired - rechecking");
-        return;
+    if (authenticate) {
+        debugs(29, 9, HERE << "Sending type:" << hdrType << " header: 'Basic realm=\"" << basicAuthRealm << "\"'");
+        httpHeaderPutStrf(&rep->header, hdrType, "Basic realm=\"%s\"", basicAuthRealm);
     }
-
-    /* we have been through the external helper, and the credentials haven't expired */
-    debugs(29, 9, "authenticateBasicAuthenticateuser: user '" << basic_auth->username() << "' authenticated");
-
-    /* Decode now takes care of finding the AuthUser struct in the cache */
-    /* after external auth occurs anyway */
-    basic_auth->expiretime = current_time.tv_sec;
-
-    return;
 }
 
-int
-AuthBasicUserRequest::module_direction()
+void
+AuthBasicConfig::rotateHelpers()
 {
-    /* null auth_user is checked for by authenticateDirection */
-    basic_data *basic_auth = dynamic_cast<BasicUser *>(user());
-    assert (basic_auth);
-
-    switch (basic_auth->flags.credentials_ok) {
-
-    case 0:			/* not checked */
-        return -1;
-
-    case 1:			/* checked & ok */
-
-        if (basic_auth->credentials_checkedtime + basicConfig.credentialsTTL <= squid_curtime)
-            return -1;
-
-        return 0;
-
-    case 2:			/* paused while waiting for a username:password check on another request */
-        return -1;
-
-    case 3:			/* authentication process failed. */
-        return 0;
+    /* schedule closure of existing helpers */
+    if (basicauthenticators) {
+        helperShutdown(basicauthenticators);
     }
 
-    return -2;
+    /* NP: dynamic helper restart will ensure they start up again as needed. */
 }
 
+/** shutdown the auth helpers and free any allocated configuration details */
 void
-AuthBasicConfig::fixHeader(AuthUserRequest *auth_user_request, HttpReply *rep, http_hdr_type hdrType, HttpRequest * request)
+AuthBasicConfig::done()
 {
-    if (authenticate) {
-        debugs(29, 9, HERE << "Sending type:" << hdrType << " header: 'Basic realm=\"" << basicAuthRealm << "\"'");
-        httpHeaderPutStrf(&rep->header, hdrType, "Basic realm=\"%s\"", basicAuthRealm);
+    authbasic_initialised = 0;
+
+    if (basicauthenticators) {
+        helperShutdown(basicauthenticators);
     }
-}
 
-/* free any allocated configuration details */
-void
-AuthBasicConfig::done()
-{
+    delete basicauthenticators;
+    basicauthenticators = NULL;
+
     if (authenticate)
         wordlistDestroy(&authenticate);
 
