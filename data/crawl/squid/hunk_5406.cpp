 {
     return data != NULL;
 }
+
+ProxyAuthNeeded ProxyAuthNeeded::instance_;
+
+ProxyAuthNeeded *
+ProxyAuthNeeded::Instance()
+{
+    return &instance_;
+}
+
+ProxyAuthLookup ProxyAuthLookup::instance_;
+
+ProxyAuthLookup *
+ProxyAuthLookup::Instance()
+{
+    return &instance_;
+}
+
+void
+ProxyAuthLookup::checkForAsync(ACLChecklist *checklist)const
+{
+    checklist->asyncInProgress(true);
+    debug(28, 3)
+      ("ACLChecklist::checkForAsync: checking password via authenticator\n");
+
+    auth_user_request_t *auth_user_request;
+    /* make sure someone created auth_user_request for us */
+    assert(checklist->auth_user_request != NULL);
+    auth_user_request = checklist->auth_user_request;
+
+    assert(authenticateValidateUser(auth_user_request));
+    authenticateStart(auth_user_request, LookupDone, checklist);
+}
+
+void
+ProxyAuthLookup::LookupDone(void *data, char *result)
+{
+    ACLChecklist *checklist = (ACLChecklist *)data;
+    assert (checklist->asyncState() == ProxyAuthLookup::Instance());
+
+    if (result != NULL)
+	fatal("AclLookupProxyAuthDone: Old code floating around somewhere.\nMake clean and if that doesn't work, report a bug to the squid developers.\n");
+    if (!authenticateValidateUser(checklist->auth_user_request) || checklist->conn() == NULL) {
+	/* credentials could not be checked either way
+	 * restart the whole process */
+	/* OR the connection was closed, there's no way to continue */
+	authenticateAuthUserRequestUnlock(checklist->auth_user_request);
+	if (checklist->conn()) {
+	    checklist->conn()->auth_user_request = NULL;
+	    checklist->conn()->auth_type = AUTH_BROKEN;
+	}
+	checklist->auth_user_request = NULL;
+    }
+    checklist->asyncInProgress(false);
+    checklist->changeState (ACLChecklist::NullState::Instance());
+    checklist->check();
+}
+
+void
+ProxyAuthNeeded::checkForAsync(ACLChecklist *checklist) const
+{
+    /* Client is required to resend the request with correct authentication
+     * credentials. (This may be part of a stateful auth protocol.)
+     * The request is denied.
+     */
+    debug(28, 6) ("ACLChecklist::checkForAsync: requiring Proxy Auth header.\n");
+    checklist->currentAnswer(ACCESS_REQ_PROXY_AUTH);
+    checklist->markFinished();
+}
+
+ACL::Prototype ACLProxyAuth::UserRegistryProtoype(&ACLProxyAuth::UserRegistryEntry_, "proxy_auth");
+ACLProxyAuth ACLProxyAuth::UserRegistryEntry_(new ACLUserData);
+ACL::Prototype ACLProxyAuth::RegexRegistryProtoype(&ACLProxyAuth::RegexRegistryEntry_, "proxy_auth_regex");
+ACLProxyAuth ACLProxyAuth::RegexRegistryEntry_(new ACLRegexData);
+
+ACL *
+ACLProxyAuth::clone() const
+{
+    return new ACLProxyAuth(*this);
+}
+
+int
+ACLProxyAuth::matchForCache(ACLChecklist *checklist)
+{
+    return data->match(authenticateUserRequestUsername(checklist->auth_user_request));
+}
+
+/* aclMatchProxyAuth can return two exit codes:
+ * 0 : Authorisation for this ACL failed. (Did not match)
+ * 1 : Authorisation OK. (Matched)
+ */
+int
+ACLProxyAuth::matchProxyAuth(ACLChecklist *checklist)
+{
+    checkAuthForCaching(checklist);
+    /* check to see if we have matched the user-acl before */
+    int result = cacheMatchAcl(&checklist->auth_user_request->auth_user->
+	proxy_match_cache, checklist);
+    checklist->auth_user_request = NULL;
+    return result;
+}
+
+void
+ACLProxyAuth::checkAuthForCaching(ACLChecklist *checklist)const
+{
+    /* for completeness */
+    authenticateAuthUserRequestLock(checklist->auth_user_request);
+    /* consistent parameters ? */
+    assert(authenticateUserAuthenticated(checklist->auth_user_request));
+    /* this check completed */
+    authenticateAuthUserRequestUnlock(checklist->auth_user_request);
+}
+
