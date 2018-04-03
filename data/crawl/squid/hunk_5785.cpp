     ntlm_request_t *ntlm_request;
     debug(29, 9) ("authenticateNTLMHandleReply: Helper: '%d' {%s}\n", lastserver, reply ? reply : "<NULL>");
     valid = cbdataValid(r->data);
-    if (valid) {
-	if (reply) {
-	    /* seperate out the useful data */
-	    if (strncasecmp(reply, "TT ", 3) == 0) {
-		reply += 3;
-		/* we have been given a Challenge */
-		/* we should check we weren't given an empty challenge */
-		/* copy the challenge to the state data */
-		helperstate = helperStatefulServerGetData(lastserver);
-		if (helperstate == NULL)
-		    fatal("lost NTLM helper state! quitting\n");
-		helperstate->challenge = xstrndup(reply, NTLM_CHALLENGE_SZ + 5);
-		helperstate->challengeuses = 0;
-		helperstate->renewed = squid_curtime;
-		/* and we satisfy the request that happended on the refresh boundary */
-		/* note this code is now in two places FIXME */
-		assert(r->auth_user_request != NULL);
-		assert(r->auth_user_request->auth_user->auth_type == AUTH_NTLM);
-		auth_user_request = r->auth_user_request;
-		ntlm_request = auth_user_request->scheme_data;
-		assert(ntlm_request != NULL);
-		result = S_HELPER_DEFER;
-		/* reserve the server for future authentication */
-		ntlm_request->authserver_deferred = 1;
-		debug(29, 9) ("authenticateNTLMHandleReply: helper '%d'\n", lastserver);
-		assert(ntlm_request->auth_state == AUTHENTICATE_STATE_NEGOTIATE);
-		ntlm_request->authserver = lastserver;
-		ntlm_request->authchallenge = xstrndup(reply, NTLM_CHALLENGE_SZ + 5);
-	    } else if (strncasecmp(reply, "AF ", 3) == 0) {
-		/* we're finished, release the helper */
-		reply += 3;
-		assert(r->auth_user_request != NULL);
-		assert(r->auth_user_request->auth_user->auth_type == AUTH_NTLM);
-		auth_user_request = r->auth_user_request;
-		assert(auth_user_request->scheme_data != NULL);
-		ntlm_request = auth_user_request->scheme_data;
-		auth_user = auth_user_request->auth_user;
-		ntlm_user = auth_user_request->auth_user->scheme_data;
-		assert(ntlm_user != NULL);
-		result = S_HELPER_RELEASE;
-		/* we only expect OK when finishing the handshake */
-		assert(ntlm_request->auth_state == AUTHENTICATE_STATE_RESPONSE);
-		ntlm_user->username = xstrndup(reply, MAX_LOGIN_SZ);
-		ntlm_request->authserver = NULL;
-		auth_user->flags.credentials_ok = 1;	/* login ok */
+    if (!valid) {
+	debug(29, 1) ("AuthenticateNTLMHandleReply: invalid callback data. Releasing helper '%d'.\n", lastserver);
+	cbdataUnlock(r->data);
+	authenticateStateFree(r);
+	debug(29, 9) ("NTLM HandleReply, telling stateful helper : %d\n", S_HELPER_RELEASE);
+	return S_HELPER_RELEASE;
+    } 
+    
+    if (!reply) {
+	fatal("authenticateNTLMHandleReply: called with no result string\n");
+    } 
+
+    /* seperate out the useful data */
+    if (strncasecmp(reply, "TT ", 3) == 0) {
+	reply += 3;
+	/* we have been given a Challenge */
+	/* we should check we weren't given an empty challenge */
+	/* copy the challenge to the state data */
+	helperstate = helperStatefulServerGetData(lastserver);
+	if (helperstate == NULL)
+	    fatal("lost NTLM helper state! quitting\n");
+	helperstate->challenge = xstrndup(reply, NTLM_CHALLENGE_SZ + 5);
+	helperstate->challengeuses = 0;
+	helperstate->renewed = squid_curtime;
+	/* and we satisfy the request that happended on the refresh boundary */
+	/* note this code is now in two places FIXME */
+	assert(r->auth_user_request != NULL);
+	assert(r->auth_user_request->auth_user->auth_type == AUTH_NTLM);
+	auth_user_request = r->auth_user_request;
+	ntlm_request = auth_user_request->scheme_data;
+	assert(ntlm_request != NULL);
+	result = S_HELPER_DEFER;
+	/* reserve the server for future authentication */
+	ntlm_request->authserver_deferred = 1;
+	debug(29, 9) ("authenticateNTLMHandleReply: helper '%d'\n", lastserver);
+	assert(ntlm_request->auth_state == AUTHENTICATE_STATE_NEGOTIATE);
+	ntlm_request->authserver = lastserver;
+	ntlm_request->authchallenge = xstrndup(reply, NTLM_CHALLENGE_SZ + 5);
+    } else if (strncasecmp(reply, "AF ", 3) == 0) {
+	/* we're finished, release the helper */
+	reply += 3;
+	assert(r->auth_user_request != NULL);
+	assert(r->auth_user_request->auth_user->auth_type == AUTH_NTLM);
+	auth_user_request = r->auth_user_request;
+	assert(auth_user_request->scheme_data != NULL);
+	ntlm_request = auth_user_request->scheme_data;
+	auth_user = auth_user_request->auth_user;
+	ntlm_user = auth_user_request->auth_user->scheme_data;
+	assert(ntlm_user != NULL);
+	result = S_HELPER_RELEASE;
+	/* we only expect OK when finishing the handshake */
+	assert(ntlm_request->auth_state == AUTHENTICATE_STATE_RESPONSE);
+	ntlm_user->username = xstrndup(reply, MAX_LOGIN_SZ);
+	ntlm_request->authserver = NULL;
+	auth_user->flags.credentials_ok = 1;	/* login ok */
 #ifdef NTLM_FAIL_OPEN
-	    } else if (strncasecmp(reply, "LD ", 3) == 0) {
-		/* This is a variant of BH, which rather than deny access
-		 * allows the user through. The helper is starved and then refreshed
-		 * via YR, all pending authentications are likely to fail also.
-		 * It is meant for those helpers which occasionally fail for
-		 * no reason at all (casus belli, NTLMSSP helper on NT domain,
-		 * failing about 1 auth out of 1k.
-		 * The code is a merge from the BH case with snippets of the AF
-		 * case */
-		/* AF code: mark user as authenticated */
-		reply += 3;
-		assert(r->auth_user_request != NULL);
-		assert(r->auth_user_request->auth_user->auth_type == AUTH_NTLM);
-		auth_user_request = r->auth_user_request;
-		assert(auth_user_request->scheme_data != NULL);
-		ntlm_request = auth_user_request->scheme_data;
-		auth_user = auth_user_request->auth_user;
-		ntlm_user = auth_user_request->auth_user->scheme_data;
-		assert(ntlm_user != NULL);
-		result = S_HELPER_RELEASE;
-		/* we only expect OK when finishing the handshake */
-		assert(ntlm_request->auth_state == AUTHENTICATE_STATE_RESPONSE);
-		ntlm_user->username = xstrndup(reply, MAX_LOGIN_SZ);
-		helperstate = helperStatefulServerGetData(ntlm_request->authserver);
-		ntlm_request->authserver = NULL;
-		auth_user->flags.credentials_ok = 1;	/* login ok */
-		/* BH code: mark helper as broken */
-		/* Not a valid helper response to a YR request. Assert so the helper
-		 * programmer will fix their bugs! */
-		assert(ntlm_request->auth_state != AUTHENTICATE_STATE_NEGOTIATE);
-		/* mark it for starving */
-		helperstate->starve = 1;
+    } else if (strncasecmp(reply, "LD ", 3) == 0) {
+	/* This is a variant of BH, which rather than deny access
+	 * allows the user through. The helper is starved and then refreshed
+	 * via YR, all pending authentications are likely to fail also.
+	 * It is meant for those helpers which occasionally fail for
+	 * no reason at all (casus belli, NTLMSSP helper on NT domain,
+	 * failing about 1 auth out of 1k.
+	 * The code is a merge from the BH case with snippets of the AF
+	 * case */
+	/* AF code: mark user as authenticated */
+	reply += 3;
+	assert(r->auth_user_request != NULL);
+	assert(r->auth_user_request->auth_user->auth_type == AUTH_NTLM);
+	auth_user_request = r->auth_user_request;
+	assert(auth_user_request->scheme_data != NULL);
+	ntlm_request = auth_user_request->scheme_data;
+	auth_user = auth_user_request->auth_user;
+	ntlm_user = auth_user_request->auth_user->scheme_data;
+	assert(ntlm_user != NULL);
+	result = S_HELPER_RELEASE;
+	/* we only expect OK when finishing the handshake */
+	assert(ntlm_request->auth_state == AUTHENTICATE_STATE_RESPONSE);
+	ntlm_user->username = xstrndup(reply, MAX_LOGIN_SZ);
+	helperstate = helperStatefulServerGetData(ntlm_request->authserver);
+	ntlm_request->authserver = NULL;
+	auth_user->flags.credentials_ok = 1;	/* login ok */
+	/* BH code: mark helper as broken */
+	/* Not a valid helper response to a YR request. Assert so the helper
+	 * programmer will fix their bugs! */
+	assert(ntlm_request->auth_state != AUTHENTICATE_STATE_NEGOTIATE);
+	/* mark it for starving */
+	helperstate->starve = 1;
 #endif
-	    } else if (strncasecmp(reply, "NA ", 3) == 0) {
-		/* TODO: only work with auth_user here if it exists */
-		assert(r->auth_user_request != NULL);
-		assert(r->auth_user_request->auth_user->auth_type == AUTH_NTLM);
-		auth_user_request = r->auth_user_request;
-		auth_user = auth_user_request->auth_user;
-		assert(auth_user != NULL);
-		ntlm_user = auth_user->scheme_data;
-		ntlm_request = auth_user_request->scheme_data;
-		assert((ntlm_user != NULL) && (ntlm_request != NULL));
-		/* todo: action of Negotiate state on error */
-		result = S_HELPER_RELEASE;	/*some error has occured. no more requests */
-		ntlm_request->authserver = NULL;
-		auth_user->flags.credentials_ok = 2;	/* Login/Usercode failed */
-		debug(29, 4) ("authenticateNTLMHandleReply: Error validating user via NTLM. Error returned '%s'\n", reply);
-		ntlm_request->auth_state = AUTHENTICATE_STATE_NONE;
-		if ((t = strchr(reply, ' ')))	/* strip after a space */
-		    *t = '\0';
-	    } else if (strncasecmp(reply, "BH ", 3) == 0) {
-		/* TODO kick off a refresh process. This can occur after a YR or after
-		 * a KK. If after a YR release the helper and resubmit the request via 
-		 * Authenticate NTLM start. 
-		 * If after a KK deny the user's request w/ 407 and mark the helper as 
-		 * Needing YR. */
-		assert(r->auth_user_request != NULL);
-		assert(r->auth_user_request->auth_user->auth_type == AUTH_NTLM);
-		auth_user_request = r->auth_user_request;
-		auth_user = auth_user_request->auth_user;
-		assert(auth_user != NULL);
-		ntlm_user = auth_user->scheme_data;
-		ntlm_request = auth_user_request->scheme_data;
-		assert((ntlm_user != NULL) && (ntlm_request != NULL));
-		result = S_HELPER_RELEASE;	/*some error has occured. no more requests for 
-						 * this helper */
-		helperstate = helperStatefulServerGetData(ntlm_request->authserver);
-		ntlm_request->authserver = NULL;
-		if (ntlm_request->auth_state == AUTHENTICATE_STATE_NEGOTIATE) {
-		    /* The helper broke on YR. It automatically
-		     * resets */
-		    auth_user->flags.credentials_ok = 3;	/* cannot process */
-		    debug(29, 1) ("authenticateNTLMHandleReply: Error obtaining challenge from helper: %d. Error returned '%s'\n", lastserver, reply);
-		    /* mark it for starving */
-		    helperstate->starve = 1;
-		    /* resubmit the request. This helper is currently busy, so we will get
-		     * a different one. */
-		    authenticateNTLMStart(auth_user_request, r->handler, r->data);
-		} else {
-		    /* the helper broke on a KK */
-		    /* first the standard KK stuff */
-		    auth_user->flags.credentials_ok = 2;	/* Login/Usercode failed */
-		    debug(29, 4) ("authenticateNTLMHandleReply: Error validating user via NTLM. Error returned '%s'\n", reply);
-		    ntlm_request->auth_state = AUTHENTICATE_STATE_NONE;
-		    if ((t = strchr(reply, ' ')))	/* strip after a space */
-			*t = '\0';
-		    /* now we mark the helper for resetting. */
-		    helperstate->starve = 1;
-		}
-		ntlm_request->auth_state = AUTHENTICATE_STATE_NONE;
-	    } else {
-		/* TODO: only work with auth_user here if it exists */
-		assert(r->auth_user_request != NULL);
-		assert(r->auth_user_request->auth_user->auth_type == AUTH_NTLM);
-		auth_user_request = r->auth_user_request;
-		auth_user = auth_user_request->auth_user;
-		assert(auth_user != NULL);
-		ntlm_user = auth_user->scheme_data;
-		ntlm_request = auth_user_request->scheme_data;
-		assert((ntlm_user != NULL) && (ntlm_request != NULL));
-		debug(29, 1) ("authenticateNTLMHandleReply: Unsupported helper response, '%s'\n", reply);
-		/* restart the authentication process */
-		ntlm_request->auth_state = AUTHENTICATE_STATE_NONE;
-		auth_user->flags.credentials_ok = 3;	/* cannot process */
-		ntlm_request->authserver = NULL;
-	    }
+    } else if (strncasecmp(reply, "NA ", 3) == 0) {
+	/* TODO: only work with auth_user here if it exists */
+	assert(r->auth_user_request != NULL);
+	assert(r->auth_user_request->auth_user->auth_type == AUTH_NTLM);
+	auth_user_request = r->auth_user_request;
+	auth_user = auth_user_request->auth_user;
+	assert(auth_user != NULL);
+	ntlm_user = auth_user->scheme_data;
+	ntlm_request = auth_user_request->scheme_data;
+	assert((ntlm_user != NULL) && (ntlm_request != NULL));
+	/* todo: action of Negotiate state on error */
+	result = S_HELPER_RELEASE;	/*some error has occured. no more requests */
+	ntlm_request->authserver = NULL;
+	auth_user->flags.credentials_ok = 2;	/* Login/Usercode failed */
+	debug(29, 4) ("authenticateNTLMHandleReply: Error validating user via NTLM. Error returned '%s'\n", reply);
+	ntlm_request->auth_state = AUTHENTICATE_STATE_NONE;
+	if ((t = strchr(reply, ' ')))	/* strip after a space */
+	    *t = '\0';
+    } else if (strncasecmp(reply, "NA", 2) == 0) {
+	/* NTLM Helper protocol violation! */
+	fatal ("NTLM Helper returned invalid response \"NA\" - a error message MUST be attached\n");
+    } else if (strncasecmp(reply, "BH ", 3) == 0) {
+	/* TODO kick off a refresh process. This can occur after a YR or after
+	 * a KK. If after a YR release the helper and resubmit the request via 
+	 * Authenticate NTLM start. 
+	 * If after a KK deny the user's request w/ 407 and mark the helper as 
+	 * Needing YR. */
+	assert(r->auth_user_request != NULL);
+	assert(r->auth_user_request->auth_user->auth_type == AUTH_NTLM);
+	auth_user_request = r->auth_user_request;
+	auth_user = auth_user_request->auth_user;
+	assert(auth_user != NULL);
+	ntlm_user = auth_user->scheme_data;
+	ntlm_request = auth_user_request->scheme_data;
+	assert((ntlm_user != NULL) && (ntlm_request != NULL));
+	result = S_HELPER_RELEASE;	/*some error has occured. no more requests for 
+					 * this helper */
+	assert (ntlm_request->authserver ? ntlm_request->authserver == lastserver : 1);
+	helperstate = helperStatefulServerGetData(ntlm_request->authserver);
+	ntlm_request->authserver = NULL;
+	if (ntlm_request->auth_state == AUTHENTICATE_STATE_NEGOTIATE) {
+	    /* The helper broke on YR. It automatically
+	     * resets */
+	    auth_user->flags.credentials_ok = 3;	/* cannot process */
+	    debug(29, 1) ("authenticateNTLMHandleReply: Error obtaining challenge from helper: %d. Error returned '%s'\n", lastserver, reply);
+	    /* mark it for starving */
+	    helperstate->starve = 1;
+	    /* resubmit the request. This helper is currently busy, so we will get
+	     * a different one. */
+	    authenticateNTLMStart(auth_user_request, r->handler, r->data);
+	    /* don't call the callback */
+	    cbdataUnlock(r->data);
+	    authenticateStateFree(r);
+	    debug(29, 9) ("NTLM HandleReply, telling stateful helper : %d\n", result);
+	    return result;
 	} else {
-	    fatal("authenticateNTLMHandleReply: called with no result string\n");
+	    /* the helper broke on a KK */
+	    /* first the standard KK stuff */
+	    auth_user->flags.credentials_ok = 2;	/* Login/Usercode failed */
+	    debug(29, 4) ("authenticateNTLMHandleReply: Error validating user via NTLM. Error returned '%s'\n", reply);
+	    if ((t = strchr(reply, ' ')))	/* strip after a space */
+		*t = '\0';
+	    /* now we mark the helper for resetting. */
+	    helperstate->starve = 1;
 	}
-	r->handler(r->data, NULL);
+	ntlm_request->auth_state = AUTHENTICATE_STATE_NONE;
     } else {
-	debug(29, 1) ("AuthenticateNTLMHandleReply: invalid callback data. Releasing helper '%d'.\n", lastserver);
-	result = S_HELPER_RELEASE;
+	/* TODO: only work with auth_user here if it exists */
+	assert(r->auth_user_request != NULL);
+	assert(r->auth_user_request->auth_user->auth_type == AUTH_NTLM);
+	auth_user_request = r->auth_user_request;
+	auth_user = auth_user_request->auth_user;
+	assert(auth_user != NULL);
+	ntlm_user = auth_user->scheme_data;
+	ntlm_request = auth_user_request->scheme_data;
+	assert((ntlm_user != NULL) && (ntlm_request != NULL));
+	debug(29, 1) ("authenticateNTLMHandleReply: *** Unsupported helper response ***, '%s'\n", reply);
+	/* restart the authentication process */
+	ntlm_request->auth_state = AUTHENTICATE_STATE_NONE;
+	auth_user->flags.credentials_ok = 3;	/* cannot process */
+	assert (ntlm_request->authserver ? ntlm_request->authserver == lastserver : 1);
+	ntlm_request->authserver = NULL;
     }
+    r->handler(r->data, NULL);
     cbdataUnlock(r->data);
     authenticateStateFree(r);
     debug(29, 9) ("NTLM HandleReply, telling stateful helper : %d\n", result);
