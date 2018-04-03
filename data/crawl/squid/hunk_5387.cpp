     assert(data);
     assert(auth_user->auth_type = AUTH_NTLM);
     debug(29, 9) ("authenticateNTLMStart: auth state '%d'\n", ntlm_request->auth_state);
+
     switch (ntlm_request->auth_state) {
+
     case AUTHENTICATE_STATE_NEGOTIATE:
-	sent_string = ntlm_request->ntlmnegotiate;
-	break;
+        sent_string = ntlm_request->ntlmnegotiate;
+        break;
+
     case AUTHENTICATE_STATE_RESPONSE:
-	sent_string = ntlm_request->ntlmauthenticate;
-	assert(ntlm_request->authserver);
-	debug(29, 9) ("authenticateNTLMStart: Asking NTLMauthenticator '%p'.\n", ntlm_request->authserver);
-	break;
+        sent_string = ntlm_request->ntlmauthenticate;
+        assert(ntlm_request->authserver);
+        debug(29, 9) ("authenticateNTLMStart: Asking NTLMauthenticator '%p'.\n", ntlm_request->authserver);
+        break;
+
     default:
-	fatal("Invalid authenticate state for NTLMStart");
+        fatal("Invalid authenticate state for NTLMStart");
     }
 
     while (!xisspace(*sent_string))	/*trim NTLM */
-	sent_string++;
+        sent_string++;
 
     while (xisspace(*sent_string))	/*trim leading spaces */
-	sent_string++;
+        sent_string++;
 
     debug(29, 9) ("authenticateNTLMStart: state '%d'\n", ntlm_request->auth_state);
+
     debug(29, 9) ("authenticateNTLMStart: '%s'\n", sent_string);
+
     if (ntlmConfig->authenticate == NULL) {
-	debug(29, 0) ("authenticateNTLMStart: no NTLM program specified:'%s'\n", sent_string);
-	handler(data, NULL);
-	return;
+        debug(29, 0) ("authenticateNTLMStart: no NTLM program specified:'%s'\n", sent_string);
+        handler(data, NULL);
+        return;
     }
+
     /* this is ugly TODO: move the challenge generation routines to their own function and
      * tidy the logic up to make use of the efficiency we now have */
     switch (ntlm_request->auth_state) {
+
     case AUTHENTICATE_STATE_NEGOTIATE:
-	/*  
-	 * 1: get a helper server
-	 * 2: does it have a challenge?
-	 * 3: tell it to get a challenge, or give ntlmauthdone the challenge
-	 */
-	server = helperStatefulDefer(ntlmauthenticators);
-	helperstate = server ? static_cast<ntlm_helper_state_t *>(helperStatefulServerGetData(server)) : NULL;
-	while ((server != NULL) && authenticateNTLMChangeChallenge_p(helperstate)) {
-	    /* flag this helper for challenge changing */
-	    helperstate->starve = 1;
-	    /* and release the deferred request */
-	    helperStatefulReleaseServer(server);
-	    /* Get another deferrable server */
-	    server = helperStatefulDefer(ntlmauthenticators);
-	    helperstate = server ? static_cast<ntlm_helper_state_t *>(helperStatefulServerGetData(server)) : NULL;
-	}
-	if (server == NULL)
-	    debug(29, 9) ("unable to get a deferred ntlm helper... all helpers are refreshing challenges. Queuing as a placeholder request.\n");
-
-	ntlm_request->authserver = server;
-	/* tell the log what helper we have been given */
-	debug(29, 9) ("authenticateNTLMStart: helper '%p' assigned\n", server);
-	/* server and valid challenge? */
-	if ((server == NULL) || !authenticateNTLMValidChallenge(helperstate)) {
-	    /* No server, or server with invalid challenge */
-	    r = cbdataAlloc(authenticateStateData);
-	    r->handler = handler;
-	    r->data = cbdataReference(data);
-	    r->auth_user_request = auth_user_request;
-	    if (server == NULL) {
-		helperStatefulSubmit(ntlmauthenticators, NULL, authenticateNTLMHandleplaceholder, r, NULL);
-	    } else {
-		/* Server with invalid challenge */
-		snprintf(buf, 8192, "YR\n");
-		helperStatefulSubmit(ntlmauthenticators, buf, authenticateNTLMHandleReply, r, ntlm_request->authserver);
-	    }
-	} else {
-	    /* (server != NULL and we have a valid challenge) */
-	    /* TODO: turn the below into a function and call from here and handlereply */
-	    /* increment the challenge uses */
-	    helperstate->challengeuses++;
-	    /* assign the challenge */
-	    ntlm_request->authchallenge = xstrndup(helperstate->challenge, NTLM_CHALLENGE_SZ + 5);
-	    /* we're not actually submitting a request, so we need to release the helper 
-	     * should the connection close unexpectedly
-	     */
-	    ntlm_request->authserver_deferred = 1;
-	    handler(data, NULL);
-	}
-
-	break;
+        /*
+         * 1: get a helper server
+         * 2: does it have a challenge?
+         * 3: tell it to get a challenge, or give ntlmauthdone the challenge
+         */
+        server = helperStatefulDefer(ntlmauthenticators);
+        helperstate = server ? static_cast<ntlm_helper_state_t *>(helperStatefulServerGetData(server)) : NULL;
+
+        while ((server != NULL) && authenticateNTLMChangeChallenge_p(helperstate)) {
+            /* flag this helper for challenge changing */
+            helperstate->starve = 1;
+            /* and release the deferred request */
+            helperStatefulReleaseServer(server);
+            /* Get another deferrable server */
+            server = helperStatefulDefer(ntlmauthenticators);
+            helperstate = server ? static_cast<ntlm_helper_state_t *>(helperStatefulServerGetData(server)) : NULL;
+        }
+
+        if (server == NULL)
+            debug(29, 9) ("unable to get a deferred ntlm helper... all helpers are refreshing challenges. Queuing as a placeholder request.\n");
+
+        ntlm_request->authserver = server;
+
+        /* tell the log what helper we have been given */
+        debug(29, 9) ("authenticateNTLMStart: helper '%p' assigned\n", server);
+
+        /* server and valid challenge? */
+        if ((server == NULL) || !authenticateNTLMValidChallenge(helperstate)) {
+            /* No server, or server with invalid challenge */
+            r = cbdataAlloc(authenticateStateData);
+            r->handler = handler;
+            r->data = cbdataReference(data);
+            r->auth_user_request = auth_user_request;
+
+            if (server == NULL) {
+                helperStatefulSubmit(ntlmauthenticators, NULL, authenticateNTLMHandleplaceholder, r, NULL);
+            } else {
+                /* Server with invalid challenge */
+                snprintf(buf, 8192, "YR\n");
+                helperStatefulSubmit(ntlmauthenticators, buf, authenticateNTLMHandleReply, r, ntlm_request->authserver);
+            }
+        } else {
+            /* (server != NULL and we have a valid challenge) */
+            /* TODO: turn the below into a function and call from here and handlereply */
+            /* increment the challenge uses */
+            helperstate->challengeuses++;
+            /* assign the challenge */
+            ntlm_request->authchallenge = xstrndup(helperstate->challenge, NTLM_CHALLENGE_SZ + 5);
+            /* we're not actually submitting a request, so we need to release the helper
+             * should the connection close unexpectedly
+             */
+            ntlm_request->authserver_deferred = 1;
+            handler(data, NULL);
+        }
+
+        break;
+
     case AUTHENTICATE_STATE_RESPONSE:
-	r = cbdataAlloc(authenticateStateData);
-	r->handler = handler;
-	r->data = cbdataReference(data);
-	r->auth_user_request = auth_user_request;
-	snprintf(buf, 8192, "KK %s\n", sent_string);
-	/* getting rid of deferred request status */
-	ntlm_request->authserver_deferred = 0;
-	helperStatefulSubmit(ntlmauthenticators, buf, authenticateNTLMHandleReply, r, ntlm_request->authserver);
-	debug(29, 9) ("authenticateNTLMstart: finished\n");
-	break;
+        r = cbdataAlloc(authenticateStateData);
+        r->handler = handler;
+        r->data = cbdataReference(data);
+        r->auth_user_request = auth_user_request;
+        snprintf(buf, 8192, "KK %s\n", sent_string);
+        /* getting rid of deferred request status */
+        ntlm_request->authserver_deferred = 0;
+        helperStatefulSubmit(ntlmauthenticators, buf, authenticateNTLMHandleReply, r, ntlm_request->authserver);
+        debug(29, 9) ("authenticateNTLMstart: finished\n");
+        break;
+
     default:
-	fatal("Invalid authenticate state for NTLMStart");
+        fatal("Invalid authenticate state for NTLMStart");
     }
 }
 
