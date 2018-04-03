    return !splayLastResult;
}

static int
aclDecodeProxyAuth(const char *proxy_auth, char **user, char **password, char *buf, size_t bufsize)
{
    char *sent_auth;
    char *cleartext;
    if (proxy_auth == NULL)
	return 0;
    debug(28, 6) ("aclDecodeProxyAuth: header = '%s'\n", proxy_auth);
    if (strncasecmp(proxy_auth, "Basic ", 6) != 0) {
	debug(28, 1) ("aclDecodeProxyAuth: Unsupported proxy-auth sheme, '%s'\n", proxy_auth);
	return 0;
    }
    proxy_auth += 6;		/* "Basic " */
    /* Trim leading whitespace before decoding */
    while (xisspace(*proxy_auth))
	proxy_auth++;
    sent_auth = xstrdup(proxy_auth);	/* username and password */
    /* Trim trailing \n before decoding */
    strtok(sent_auth, "\n");
    cleartext = uudecode(sent_auth);
    xfree(sent_auth);
    /*
     * Don't allow NL or CR in the credentials.
     * Oezguer Kesim <oec@codeblau.de>
     */
    strtok(cleartext, "\r\n");
    debug(28, 6) ("aclDecodeProxyAuth: cleartext = '%s'\n", cleartext);
    xstrncpy(buf, cleartext, bufsize);
    xfree(cleartext);
    /* Trim leading whitespace after decoding */
    while (xisspace(*buf))
	buf++;
    *user = buf;
    if ((*password = strchr(*user, ':')) != NULL)
	*(*password)++ = '\0';
    if (*password == NULL) {
	debug(28, 1) ("aclDecodeProxyAuth: no password in proxy authorization header '%s'\n", proxy_auth);
	return 0;
    }
    if (**password == '\0') {
	debug(28, 1) ("aclDecodeProxyAuth: Disallowing empty password,"
	    "user is '%s'\n", *user);
	return 0;
    }
    return 1;
}

/* aclMatchProxyAuth can return three exit codes:
 * 0 : user denied access
 * 1 : user validated OK
 * -1 : check the password for this user via an external authenticator
 * -2 : invalid Proxy-authorization: header;
 * ask for Proxy-Authorization: header
 */

static int
aclMatchProxyAuth(void *data, const char *proxy_auth, acl_proxy_auth_user * auth_user, aclCheck_t * checklist, squid_acl acltype)
{
    /* checklist is used to register user name when identified, nothing else */
    LOCAL_ARRAY(char, login_buf, USER_IDENT_SZ);
    char *user, *password;

    if (!aclDecodeProxyAuth(proxy_auth, &user, &password, login_buf, sizeof(login_buf)))
	/* No or invalid Proxy-Auth header */
	return -2;

    debug(28, 5) ("aclMatchProxyAuth: checking user '%s'\n", user);

    if (auth_user) {
	/*
	 * This should be optimized to a boolean argument indicating that the
	 * password is invalid, instead of passing full acl_proxy_auth_user
	 * structures, and all messing with checklist->proxy_auth should
	 * be restricted the functions that deal with the authenticator.
	 */
	assert(auth_user == checklist->auth_user);
	checklist->auth_user = NULL;	/* get rid of that special reference */
	/* Check result from external validation */
	if (auth_user->passwd_ok != 1) {
	    /* password was checked but did not match */
	    assert(auth_user->passwd_ok == 0);
	    debug(28, 4) ("aclMatchProxyAuth: authentication failed for user '%s'\n",
		user);
	    aclFreeProxyAuthUser(auth_user);
	    /*
	     * copy username to request for logging on client-side
	     * unless ident is known (do not override ident with
	     * false proxy auth names)
	     */
	    if (!*checklist->request->user_ident)
		xstrncpy(checklist->request->user_ident, user, USER_IDENT_SZ);
	    return -2;
	} else {
	    /* password was checked and did match */
	    debug(28, 4) ("aclMatchProxyAuth: user '%s' validated OK\n", user);
	    /* store validated user in hash, after filling in expiretime */
	    xstrncpy(checklist->request->user_ident, user, USER_IDENT_SZ);
	    auth_user->expiretime = current_time.tv_sec + Config.authenticateTTL;
	    auth_user->ip_expiretime = squid_curtime + Config.authenticateIpTTL;
	    auth_user->ipaddr = checklist->src_addr;
	    hash_join(proxy_auth_cache, &auth_user->hash);
	    /* Continue checking below, as normal */
	}
    }
    /* see if we already know this user */
    auth_user = hash_lookup(proxy_auth_cache, user);

    if (!auth_user) {
	/* user not yet known, ask external authenticator */
	debug(28, 4) ("aclMatchProxyAuth: user '%s' not yet known\n", user);
	return -1;
    } else if ((0 == strcmp(auth_user->passwd, password)) &&
	(auth_user->expiretime > current_time.tv_sec)) {
	if (checklist->src_addr.s_addr == auth_user->ipaddr.s_addr
	    || auth_user->ip_expiretime <= squid_curtime) {
	    /* user already known and valid */
	    debug(28, 5) ("aclMatchProxyAuth: user '%s' previously validated\n",
		user);
	    /* Update IP ttl */
	    auth_user->ip_expiretime = squid_curtime + Config.authenticateIpTTL;
	    auth_user->ipaddr = checklist->src_addr;
	    /* copy username to request for logging on client-side */
	    xstrncpy(checklist->request->user_ident, user, USER_IDENT_SZ);
	    switch (acltype) {
	    case ACL_PROXY_AUTH:
		return aclMatchUser(data, user);
	    case ACL_PROXY_AUTH_REGEX:
		return aclMatchRegex(data, user);
	    default:
		fatal("aclMatchProxyAuth: unknown ACL type");
		return 0;	/* NOTREACHED */
	    }
	} else {
	    if (Config.onoff.authenticateIpTTLStrict) {
		/* Access from some other IP address than the one owning
		 * this user ID. Deny access
		 */
		debug(28, 1) ("aclMatchProxyAuth: user '%s' tries to use multple IP addresses!\n", user);
		return 0;
	    } else {
		/* user has switched to another IP addr */
		debug(28, 1) ("aclMatchProxyAuth: user '%s' has changed IP address\n", user);
		/* remove this user from the hash, making him unknown */
		hash_remove_link(proxy_auth_cache, (hash_link *) auth_user);
		aclFreeProxyAuthUser(auth_user);
		/* require the user to reauthenticate */
		return -2;
	    }
	}
    } else {
	/* password mismatch/timeout */
	debug(28, 4) ("aclMatchProxyAuth: user '%s' password mismatch/timeout\n",
	    user);
	/* remove this user from the hash, making him unknown */
	hash_remove_link(proxy_auth_cache, (hash_link *) auth_user);
	aclFreeProxyAuthUser(auth_user);
	/* ask the external authenticator in case the password is changed */
	/* wrong password will be trapped above so this does not loop */
	return -1;
    }
    /* NOTREACHED */

}

static void
aclLookupProxyAuthStart(aclCheck_t * checklist)
{
    LOCAL_ARRAY(char, login_buf, USER_IDENT_SZ);
    const char *proxy_auth;
    char *user, *password;
    int ok;
    acl_proxy_auth_user *auth_user;
    assert(!checklist->auth_user);
    if (!checklist->request->flags.accelerated) {
	/* Proxy auth on proxy requests */
	proxy_auth = httpHeaderGetStr(&checklist->request->header,
	    HDR_PROXY_AUTHORIZATION);
    } else {
	/* WWW auth on accelerated requests */
	proxy_auth = httpHeaderGetStr(&checklist->request->header,
	    HDR_AUTHORIZATION);
    }
    ok = aclDecodeProxyAuth(proxy_auth, &user, &password, login_buf,
	sizeof(login_buf));
    /*
     * if aclDecodeProxyAuth() fails, the same call should have failed
     * in aclMatchProxyAuth, and we should never get this far.
     */
    assert(ok);
    debug(28, 4) ("aclLookupProxyAuthStart: going to ask authenticator on %s\n", user);
    /* we must still check this user's password */
    auth_user = memAllocate(MEM_ACL_PROXY_AUTH_USER);
    auth_user->hash.key = xstrdup(user);
    auth_user->passwd = xstrdup(password);
    auth_user->passwd_ok = -1;
    auth_user->expiretime = -1;
    checklist->auth_user = auth_user;
    authenticateStart(checklist->auth_user, aclLookupProxyAuthDone,
	checklist);
}

static int
