 	    auth_user->ipaddr = checklist->src_addr;
 	    /* copy username to request for logging on client-side */
 	    xstrncpy(checklist->request->user_ident, user, USER_IDENT_SZ);
-	    switch(acltype) {
+	    switch (acltype) {
 	    case ACL_PROXY_AUTH:
 		return aclMatchUser(data, user);
 	    case ACL_PROXY_AUTH_REGEX:
 		return aclMatchRegex(data, user);
 	    default:
 		fatal("aclMatchProxyAuth: unknown ACL type");
-		return 0; /* NOTREACHED */
+		return 0;	/* NOTREACHED */
 	    }
 	} else {
 	    if (Config.onoff.authenticateIpTTLStrict) {
