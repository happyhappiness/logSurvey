    auth_user_request->user()->addRequest(auth_user_request);

    /* all we have to do is identify that it's NTLM - the helper does the rest */
    debug(29, 9) ("authenticateDecodeNTLMAuth: NTLM authentication\n");
    return auth_user_request;
}

static int
authenticateNTLMcmpUsername(ntlm_user_t * u1, ntlm_user_t * u2)
{
    return strcmp(u1->username(), u2->username());
}


/* there is a known race where a single client recieves the same challenge
 * and sends the same response to squid on a single select cycle.
 * Check for this and if found ignore the new link 
 */
static void
authenticateProxyAuthCacheAddLink(const char *key, auth_user_t * auth_user)
{

    struct ProxyAuthCachePointer *proxy_auth_hash;
    dlink_node *node;
    ntlm_user_t *ntlm_user;
    ntlm_user = dynamic_cast<ntlm_user_t *>(auth_user);
    node = ntlm_user->proxy_auth_list.head;
    /* prevent duplicates */

    while (node) {

        if (!strcmp(key, (char const *)((struct ProxyAuthCachePointer *) node->data)->key))
            return;

        node = node->next;
    }

    proxy_auth_hash = static_cast<ProxyAuthCachePointer *>(ntlm_user_hash_pool->alloc());
    proxy_auth_hash->key = xstrdup(key);
    proxy_auth_hash->auth_user = auth_user;
    dlinkAddTail(proxy_auth_hash, &proxy_auth_hash->link, &ntlm_user->proxy_auth_list);
    hash_join(proxy_auth_cache, (hash_link *) proxy_auth_hash);
}

int
AuthNTLMUserRequest::authenticated() const
{
    if (auth_state == AUTHENTICATE_STATE_DONE)
        return 1;

    debug(29, 9) ("User not fully authenticated.\n");

    return 0;
}

void
AuthNTLMUserRequest::authenticate(HttpRequest * request, ConnStateData::Pointer conn, http_hdr_type type)
{
    const char *proxy_auth;

    struct ProxyAuthCachePointer *proxy_auth_hash = NULL;
    auth_user_hash_pointer *usernamehash;
    /* TODO: rename this!! */
    auth_user_t *auth_user;
    AuthNTLMUserRequest *ntlm_request;
    ntlm_user_t *ntlm_user;
    LOCAL_ARRAY(char, ntlmhash, NTLM_CHALLENGE_SZ * 2);
    /* get header */
    proxy_auth = httpHeaderGetStr(&request->header, type);

    auth_user = user();
    assert(auth_user);
    assert(auth_user->auth_type == AUTH_NTLM);
    ntlm_user = dynamic_cast<ntlm_user_t *>(auth_user);
    ntlm_request = this;
    assert (ntlm_request);
    /* Check that we are in the client side, where we can generate
     * auth challenges */

    if (conn.getRaw() == NULL) {
        ntlm_request->auth_state = AUTHENTICATE_STATE_FAILED;
        debug(29, 1) ("authenticateNTLMAuthenticateUser: attempt to perform authentication without a connection!\n");
        return;
    }

    switch (ntlm_request->auth_state) {

    case AUTHENTICATE_STATE_NONE:
        /* we've recieved a negotiate request. pass to a helper */
        debug(29, 9) ("authenticateNTLMAuthenticateUser: auth state ntlm none. %s\n", proxy_auth);
        ntlm_request->auth_state = AUTHENTICATE_STATE_NEGOTIATE;
        ntlm_request->ntlmnegotiate = xstrdup(proxy_auth);
        conn->auth_type = AUTH_NTLM;
        conn->auth_user_request = this;
        ntlm_request->conn = conn;
        /* and lock for the connection duration */
        debug(29, 9) ("authenticateNTLMAuthenticateUser: Locking auth_user from the connection.\n");

        this->lock()

        ;
        return;

        break;

    case AUTHENTICATE_STATE_NEGOTIATE:
        ntlm_request->auth_state = AUTHENTICATE_STATE_CHALLENGE;

        /* We _MUST_ have the auth challenge by now */
        assert(ntlm_request->authchallenge);

        return;

        break;

    case AUTHENTICATE_STATE_CHALLENGE:
        /* we should have recieved a NTLM challenge. pass it to the same
         * helper process */
        debug(29, 9) ("authenticateNTLMAuthenticateUser: auth state challenge with header %s.\n", proxy_auth);

        /* do a cache lookup here. If it matches it's a successful ntlm
         * challenge - release the helper and use the existing auth_user 
         * details. */

        ntlm_request->ntlmauthenticate = xstrdup(proxy_auth);

        /* cache entries have authenticateauthheaderchallengestring */
        snprintf(ntlmhash, sizeof(ntlmhash) - 1, "%s%s",
                 ntlm_request->ntlmauthenticate,
                 ntlm_request->authchallenge);

        /* see if we already know this user's authenticate */
        debug(29, 9) ("aclMatchProxyAuth: cache lookup with key '%s'\n", ntlmhash);

        assert(proxy_auth_cache != NULL);

        proxy_auth_hash = static_cast<ProxyAuthCachePointer *>(hash_lookup(proxy_auth_cache, ntlmhash));

        if (!proxy_auth_hash) {	/* not in the hash table */
            debug(29, 4) ("authenticateNTLMAuthenticateUser: proxy-auth cache miss.\n");
            ntlm_request->auth_state = AUTHENTICATE_STATE_RESPONSE;
            /* verify with the ntlm helper */
        } else {
            debug(29, 4) ("authenticateNTLMAuthenticateUser: ntlm proxy-auth cache hit\n");
            /* throw away the temporary entry */
            ntlm_request->authserver_deferred = 0;
            authenticateNTLMReleaseServer(this);
            authenticateAuthUserMerge(auth_user, proxy_auth_hash->auth_user);
            auth_user = proxy_auth_hash->auth_user;
            this->user(auth_user);
            ntlm_request->auth_state = AUTHENTICATE_STATE_DONE;
            /* we found one */
            debug(29, 9) ("found matching cache entry\n");
            assert(auth_user->auth_type == AUTH_NTLM);
            /* get the existing entries details */
            ntlm_user = dynamic_cast<ntlm_user_t *>(auth_user);
            debug(29, 9) ("Username to be used is %s\n", ntlm_user->username());
            /* on ntlm auth we do not unlock the auth_user until the
             * connection is dropped. Thank MS for this quirk */
            auth_user->expiretime = current_time.tv_sec;
        }

        return;
        break;

    case AUTHENTICATE_STATE_RESPONSE:
        /* auth-challenge pair cache miss. We've just got the response from the helper */
        /*add to cache and let them through */
        ntlm_request->auth_state = AUTHENTICATE_STATE_DONE;
        /* this connection is authenticated */
        debug(29, 4) ("authenticated\nch    %s\nauth     %s\nauthuser %s\n",
                      ntlm_request->authchallenge,
                      ntlm_request->ntlmauthenticate,
                      ntlm_user->username());
        /* cache entries have authenticateauthheaderchallengestring */
        snprintf(ntlmhash, sizeof(ntlmhash) - 1, "%s%s",
                 ntlm_request->ntlmauthenticate,
                 ntlm_request->authchallenge);
        /* see if this is an existing user with a different proxy_auth
         * string */

        if ((usernamehash = static_cast<AuthUserHashPointer *>(hash_lookup(proxy_auth_username_cache, ntlm_user->username())))
           ) {
            while ((usernamehash->user()->auth_type != auth_user->auth_type) && (usernamehash->next) && !authenticateNTLMcmpUsername(dynamic_cast<ntlm_user_t *>(usernamehash->user()), ntlm_user)
                  )
                usernamehash = static_cast<AuthUserHashPointer*>(usernamehash->next);
            if (usernamehash->user()->auth_type == auth_user->auth_type) {
                /*
                 * add another link from the new proxy_auth to the
                 * auth_user structure and update the information */
                assert(proxy_auth_hash == NULL);
                authenticateProxyAuthCacheAddLink(ntlmhash, usernamehash->user());
                /* we can't seamlessly recheck the username due to the
                 * challenge nature of the protocol. Just free the 
                 * temporary auth_user */
                authenticateAuthUserMerge(auth_user, usernamehash->user());
                auth_user = usernamehash->user();
                this->user(auth_user);
            }
        } else {
            /* store user in hash's */
            auth_user->addToNameCache();
            authenticateProxyAuthCacheAddLink(ntlmhash, auth_user);
        }

        /* set these to now because this is either a new login from an
         * existing user or a new user */
        auth_user->expiretime = current_time.tv_sec;
        return;
        break;

    case AUTHENTICATE_STATE_DONE:
        fatal("authenticateNTLMAuthenticateUser: unexpect auth state DONE! Report a bug to the squid developers.\n");
        break;

    case AUTHENTICATE_STATE_FAILED:
        /* we've failed somewhere in authentication */
        debug(29, 9) ("authenticateNTLMAuthenticateUser: auth state ntlm failed. %s\n", proxy_auth);
        return;
    }

    return;
}

AuthNTLMUserRequest::AuthNTLMUserRequest() : ntlmnegotiate(NULL), authchallenge(NULL), ntlmauthenticate(NULL),
        authserver(NULL), auth_state(AUTHENTICATE_STATE_NONE),
        authserver_deferred(0), conn(NULL), _theUser(NULL)
{}

AuthNTLMUserRequest::~AuthNTLMUserRequest()
{
    if (ntlmnegotiate)
        xfree(ntlmnegotiate);

    if (authchallenge)
        xfree(authchallenge);

    if (ntlmauthenticate)
        xfree(ntlmauthenticate);

    if (authserver != NULL && authserver_deferred) {
        debug(29, 9) ("authenticateNTLMRequestFree: releasing server '%p'\n", authserver);
        helperStatefulReleaseServer(authserver);
        authserver = NULL;
    }
