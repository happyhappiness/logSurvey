      *     username
      */
 
-    assert(headertype != 0);
-    proxy_auth = httpHeaderGetStr(&checklist->request->header, headertype);
+    /* for completeness */
+    authenticateAuthUserRequestLock(auth_user_request);
 
-    if (checklist->conn == NULL) {
-	debug(28, 1) ("aclMatchProxyAuth: no connection data, cannot process authentication\n");
-	/*
-	 * deny access: clientreadrequest requires conn data, and it is always
-	 * compiled in so we should have it too.
-	 */
-	return 0;
+    /* consistent parameters ? */
+    assert(authenticateUserAuthenticated(auth_user_request));
+    /* this ACL check completed */
+    authenticateAuthUserRequestUnlock(auth_user_request);
+    /* check to see if we have matched the user-acl before */
+    return aclCacheMatchAcl(&auth_user_request->auth_user->
+	proxy_match_cache, acltype, data,
+	authenticateUserRequestUsername(auth_user_request));
+}
+
+CBDATA_TYPE(acl_user_ip_data);
+
+void
+aclParseUserMaxIP(void *data)
+{
+    acl_user_ip_data **acldata = data;
+    char *t = NULL;
+    CBDATA_INIT_TYPE(acl_user_ip_data);
+    if (*acldata) {
+	debug(28, 1) ("Attempting to alter already set User max IP acl\n");
+	return;
     }
-    /*
-     * a note on proxy_auth logix here:
-     * proxy_auth==NULL -> unauthenticated request || already authenticated connection
-     * so we test for an authenticated connection when we recieve no authentication
-     * header.
-     */
-    if (((proxy_auth == NULL) && (!authenticateUserAuthenticated(auth_user_request ? auth_user_request : checklist->conn->auth_user_request)))
-	|| (checklist->conn->auth_type == AUTH_BROKEN)) {
-	/* no header or authentication failed/got corrupted - restart */
-	checklist->conn->auth_type = AUTH_UNKNOWN;
-	debug(28, 4) ("aclMatchProxyAuth: broken auth or no proxy_auth header. Requesting auth header.\n");
-	/* something wrong with the AUTH credentials. Force a new attempt */
-	checklist->auth_user_request = NULL;
-	checklist->conn->auth_user_request = NULL;
-	if (auth_user_request) {
-	    /* unlock the ACL lock */
-	    authenticateAuthUserRequestUnlock(auth_user_request);
-	}
-	return -2;
-    }
-    /* we have a proxy auth header and as far as we know this connection has
-     * not had bungled connection oriented authentication happen on it. */
-    debug(28, 9) ("aclMatchProxyAuth: header %s.\n", proxy_auth);
-    if (auth_user_request == NULL) {
-	debug(28, 9) ("aclMatchProxyAuth: This is a new request on FD:%d\n",
-	    checklist->conn->fd);
-	if ((!checklist->request->auth_user_request)
-	    && (checklist->conn->auth_type == AUTH_UNKNOWN)) {
-	    /* beginning of a new request check */
-	    debug(28, 4) ("aclMatchProxyAuth: no connection authentication type\n");
-	    if (!authenticateValidateUser(auth_user_request =
-		    authenticateGetAuthUser(proxy_auth))) {
-		/* the decode might have left a username for logging, or a message to
-		 * the user */
-		if (authenticateUserRequestUsername(auth_user_request)) {
-		    /* lock the user for the request structure link */
-		    authenticateAuthUserRequestLock(auth_user_request);
-		    checklist->request->auth_user_request = auth_user_request;
-		    /* unlock the ACL reference. */
-		    authenticateAuthUserRequestUnlock(auth_user_request);
-		}
-		return -2;
-	    }
-	    /* the user_request comes prelocked for the caller to GetAuthUser (us) */
-	} else if (checklist->request->auth_user_request) {
-	    auth_user_request = checklist->request->auth_user_request;
-	    /* lock the user request for this ACL processing */
-	    authenticateAuthUserRequestLock(auth_user_request);
+    *acldata = cbdataAlloc(acl_user_ip_data);
+    if ((t = strtokFile())) {
+	debug(28, 5) ("aclParseUserMaxIP: First token is %s\n", t);
+	if (strcmp("-s", t) == 0) {
+	    debug(28, 5) ("aclParseUserMaxIP: Going strict\n");
+	    (*acldata)->flags.strict = 1;
 	} else {
-	    if (checklist->conn->auth_user_request != NULL) {
-		auth_user_request = checklist->conn->auth_user_request;
-		/* lock the user request for this ACL processing */
-		authenticateAuthUserRequestLock(auth_user_request);
-	    } else {
-		/* failed connection based authentication */
-		debug(28, 4) ("aclMatchProxyAuth: Auth user request %d conn-auth user request %d conn type %d authentication failed.\n",
-		    auth_user_request, checklist->conn->auth_user_request,
-		    checklist->conn->auth_type);
-		return -2;
-	    }
+	    (*acldata)->max = atoi(t);
+	    debug(28, 5) ("aclParseUserMaxIP: Max IP address's %d\n", (*acldata)->max);
 	}
-    }
-    /* Clear the reference in the checklist */
-    checklist->auth_user_request = NULL;
-    if (!authenticateUserAuthenticated(auth_user_request)) {
-	/* User not logged in. Log them in */
-	authenticateAuthUserRequestSetIp(auth_user_request,
-	    checklist->src_addr);
-	authenticateAuthenticateUser(auth_user_request, checklist->request,
-	    checklist->conn, headertype);
-	switch (authenticateDirection(auth_user_request)) {
-	case 1:
-	    /* this ACL check is finished. Unlock. */
-	    authenticateAuthUserRequestUnlock(auth_user_request);
-	    return -2;
-	case -1:
-	    /* we are partway through authentication within squid
-	     * store the auth_user for the callback to here */
-	    checklist->auth_user_request = auth_user_request;
-	    /* we will be called back here. Do not Unlock */
-	    return -1;
-	case -2:
-	    /* this ACL check is finished. Unlock. */
-	    authenticateAuthUserRequestUnlock(auth_user_request);
-	    return -2;
-	}			/* on 0 the authentication is finished - fallthrough */
-	/* See of user authentication failed for some reason */
-	if (!authenticateUserAuthenticated(auth_user_request)) {
-	    if ((!checklist->rfc931[0]) &&
-		(authenticateUserRequestUsername(auth_user_request))) {
-		if (!checklist->request->auth_user_request) {
-		    /* lock the user for the request structure link */
-		    authenticateAuthUserRequestLock(auth_user_request);
-		    checklist->request->auth_user_request = auth_user_request;
-		}
-	    }
-	    /* this ACL check is finished. Unlock. */
-	    authenticateAuthUserRequestUnlock(auth_user_request);
-	    return -2;
+    } else
+	fatal("aclParseUserMaxIP: Malformed ACL %d\n");
+}
 
-	}
-    }
-    /* User authenticated ok */
-    assert(authenticateUserAuthenticated(auth_user_request));
+void
+aclDestroyUserMaxIP(void *data)
+{
+    acl_user_ip_data **acldata = data;
+    if (*acldata)
+	cbdataFree(*acldata);
+    *acldata = NULL;
+}
 
-    /* copy username to request for logging on client-side */
-    /* the credentials are correct at this point */
-    if (!checklist->request->auth_user_request) {
-	/* lock the user for the request structure link */
-	authenticateAuthUserRequestLock(auth_user_request);
-	checklist->request->auth_user_request = auth_user_request;
-    }
-    if (authenticateCheckAuthUserIP(checklist->src_addr, auth_user_request)) {
-	/* Once the match is completed we have finished with the
-	 * auth_user structure */
-	/* this ACL check completed */
-	authenticateAuthUserRequestUnlock(auth_user_request);
-	/* check to see if we have matched the user-acl before */
-	return aclCacheMatchAcl(&auth_user_request->auth_user->
-	    proxy_match_cache, acltype, data,
-	    authenticateUserRequestUsername(auth_user_request));
+wordlist *
+aclDumpUserMaxIP(void *data)
+{
+    acl_user_ip_data *acldata = data;
+    wordlist *W = NULL;
+    char buf[128];
+    if (acldata->flags.strict)
+	wordlistAdd(&W, "-s");
+    snprintf(buf, sizeof(buf), "%d", acldata->max);
+    wordlistAdd(&W, buf);
+    return W;
+}
+
+/* aclMatchUserMaxIP - check for users logging in from multiple IP's 
+ * 0 : No match
+ * 1 : Match 
+ */
+int
+aclMatchUserMaxIP(void *data, auth_user_request_t * auth_user_request,
+    struct in_addr src_addr)
+{
+/*
+ * > the logic for flush the ip list when the limit is hit vs keep it sorted in most recent access order and just drop the oldest one off is currently undecided
+ */
+    acl_user_ip_data *acldata = data;
+
+    if (authenticateAuthUserRequestIPCount(auth_user_request) <= acldata->max)
+	return 0;
+
+    /* this is a match */
+    if (acldata->flags.strict) {
+	/* simply deny access - the user name is already associated with
+	 * the request 
+	 */
+	/* remove _this_ ip, as it is the culprit for going over the limit */
+	authenticateAuthUserRequestRemoveIp(auth_user_request, src_addr);
+	debug(28, 4) ("aclMatchUserMaxIP: Denying access in strict mode\n");
     } else {
-	debug(28, 1) ("XXX authenticateCheckAuthUserIP returned 0, somebody "
-	    "make sure the username gets logged to access.log.\n");
-	debug(28, 1) ("XXX if it works, tell developers to remove this "
-	    "message\n");
+	/* non-strict - remove some/all of the cached entries 
+	 * ie to allow the user to move machines easily
+	 */
+	authenticateAuthUserRequestClearIp(auth_user_request);
+	debug(28, 4) ("aclMatchUserMaxIP: Denying access in non-strict mode - flushing the user ip cache\n");
     }
-    /* this acl check completed */
-    authenticateAuthUserRequestUnlock(auth_user_request);
-    return 0;
+    /* We had reports about the username being lost when denying due to 
+     * IP limits. That should be fixed in the new lazy-proxy code, but
+     * This note note is a reminder!
+     */
+    debug(28, 1) ("XXX aclMatchUserMaxIP returned 0, somebody "
+	"make sure the username gets logged to access.log.\n");
+    debug(28, 1) ("XXX if it works, tell developers to remove this "
+	"message\n");
+
+    return 1;
 }
 
 static void
