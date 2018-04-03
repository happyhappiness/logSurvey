#include "authenticate.h"
#include "ACL.h"
#include "client_side.h"
#include "HttpReply.h"
#include "HttpRequest.h"

CBDATA_TYPE(auth_user_ip_t);

/*
 *
 * Private Data
 *
 */

MemPool *AuthUserRequest::pool = NULL;
MemPool *AuthUserHashPointer::pool = NULL;
MemPool *AuthUser::pool = NULL;
/*
 *     memDataInit(MEM_AUTH_USER_T, "auth_user_t",
 *             sizeof(auth_user_t), 0);
 */

/* Generic Functions */


static int
authenticateAuthSchemeConfigured(const char *proxy_auth)
{
    authScheme *scheme;
    int i;

    for (i = 0; i < Config.authConfiguration.n_configured; i++) {
        scheme = Config.authConfiguration.schemes + i;

        if ((strncasecmp(proxy_auth, scheme->typestr, strlen(scheme->typestr)) == 0) &&
                (authscheme_list[scheme->Id].Active()))
            return 1;
    }

    return 0;
}

int
authenticateAuthSchemeId(const char *typestr)
{
    int i = 0;

    for (i = 0; authscheme_list && authscheme_list[i].typestr; i++) {
        if (strncasecmp(typestr, authscheme_list[i].typestr, strlen(authscheme_list[i].typestr)) == 0) {
            return i;
        }
    }

    return -1;
}

void
AuthUserRequest::decodeAuth(const char *proxy_auth)
{
    int i = 0;
    assert(proxy_auth != NULL);
    debug(29, 9) ("authenticateDecodeAuth: header = '%s'\n", proxy_auth);

    if (!authenticateAuthSchemeConfigured(proxy_auth) ||
            (i = authenticateAuthSchemeId(proxy_auth)) == -1) {
        debug(29, 1) ("AuthUserRequest::decodeAuth: Unsupported or unconfigured proxy-auth scheme, '%s'\n", proxy_auth);
        return;
    }

    assert (i >= 0);
    authscheme_list[i].decodeauth(this, proxy_auth);
    auth_user->auth_module = i + 1;
}

size_t
AuthUserRequest::refCount () const
{
    return references;
}

char const *
AuthUserRequest::username() const
{
    if (auth_user)
        return auth_user->username();
    else
        return NULL;
}

size_t
authenticateRequestRefCount (auth_user_request_t *aRequest)
{
    return aRequest->refCount();
}

/* clear any connection related authentication details */
void
authenticateOnCloseConnection(ConnStateData * conn)
{
    auth_user_request_t *auth_user_request;
    assert(conn != NULL);

    if (conn->auth_user_request != NULL) {
        auth_user_request = conn->auth_user_request;
        /* if the auth type gets reset, the connection shouldn't
         * remain linked to it - the next type might not be conn based
         */
        assert(auth_user_request->auth_user->auth_module);

        if (authscheme_list[auth_user_request->auth_user->auth_module - 1].oncloseconnection) {
            authscheme_list[auth_user_request->auth_user->auth_module - 1].oncloseconnection(conn);
        }
    }
}

/**** PUBLIC FUNCTIONS (ALL GENERIC!)  ****/

/* send the initial data to an authenticator module */
void
AuthUserRequest::start(RH * handler, void *data)
{
    assert(handler);
    debug(29, 9) ("authenticateStart: auth_user_request '%p'\n", this);

    if (auth_user->auth_module > 0)
        authscheme_list[auth_user->auth_module - 1].authStart(this, handler, data);
    else
        handler(data, NULL);
}

void
authenticateStart(auth_user_request_t * auth_user_request, RH * handler, void *data)
{
    assert(auth_user_request);
    auth_user_request->start (handler, data);
}

/*
 * Check a auth_user pointer for validity. Does not check passwords, just data
 * sensability. Broken or Unknown auth_types are not valid for use...
 */

int
authenticateValidateUser(auth_user_request_t * auth_user_request)
{
    debug(29, 9) ("authenticateValidateUser: Validating Auth_user request '%p'.\n", auth_user_request);

    if (auth_user_request == NULL) {
        debug(29, 4) ("authenticateValidateUser: Auth_user_request was NULL!\n");
        return 0;
    }

    if (auth_user_request->auth_user == NULL) {
        debug(29, 4) ("authenticateValidateUser: No associated auth_user structure\n");
        return 0;
    }

    if (auth_user_request->auth_user->auth_type == AUTH_UNKNOWN) {
        debug(29, 4) ("authenticateValidateUser: Auth_user '%p' uses unknown scheme.\n", auth_user_request->auth_user);
        return 0;
    }

    if (auth_user_request->auth_user->auth_type == AUTH_BROKEN) {
        debug(29, 4) ("authenticateValidateUser: Auth_user '%p' is broken for it's scheme.\n", auth_user_request->auth_user);
        return 0;
    }

    if (!auth_user_request->auth_user->scheme_data) {
        debug(29, 4) ("authenticateValidateUser: auth_user '%p' has no scheme data\n", auth_user_request->auth_user);
        return 0;
    }

    /* any other sanity checks that we need in the future */

    /* Thus should a module call to something like authValidate */

    /* finally return ok */
    debug(29, 5) ("authenticateValidateUser: Validated Auth_user request '%p'.\n", auth_user_request);

    return 1;

}

void *
AuthUser::operator new (size_t byteCount)
{
    /* derived classes with different sizes must implement their own new */
    assert (byteCount == sizeof (AuthUser));

    if (!pool)
        pool = memPoolCreate("Authenticate User Data", sizeof (auth_user_t));

    return memPoolAlloc(pool);
}

AuthUser::AuthUser (const char *scheme) :
        auth_type (AUTH_UNKNOWN), auth_module (authenticateAuthSchemeId(scheme) + 1),
        usernamehash (NULL), ipcount (0), expiretime (0), references (0), scheme_data (NULL)
{
    proxy_auth_list.head = proxy_auth_list.tail = NULL;
    proxy_match_cache.head = proxy_match_cache.tail = NULL;
    ip_list.head = ip_list.tail = NULL;
    requests.head = requests.tail = NULL;
}

char const *
AuthUser::username () const
{
    if (auth_module <= 0)
        return NULL;

    return authscheme_list[auth_module - 1].authUserUsername(this);
}

auth_user_t *
authenticateAuthUserNew(const char *scheme)
{
    return new AuthUser (scheme);
}

void *
AuthUserRequest::operator new (size_t byteCount)
{
    /* derived classes with different sizes must implement their own new */
    assert (byteCount == sizeof (AuthUserRequest));

    if (!pool)
        pool = memPoolCreate("Authenticate Request Data", sizeof(auth_user_request_t));

    return static_cast<auth_user_request_t *>(memPoolAlloc(pool));
}

void
AuthUserRequest::operator delete (void *address)
{
    memPoolFree(pool, address);
}

AuthUserRequest::AuthUserRequest():auth_user(NULL), message(NULL),
        references (0), lastReply (AUTH_ACL_CANNOT_AUTHENTICATE), state_ (NULL)
{}

AuthUserRequest::~AuthUserRequest()
{
    dlink_node *link;
    debug(29, 5) ("AuthUserRequest::~AuthUserRequest: freeing request %p\n", this);
    assert(references == 0);

    if (auth_user) {
        if (state() != NULL) {
            /* we MUST know the module */
            assert(auth_user->auth_module > 0);

            if (authscheme_list[auth_user->auth_module - 1].requestFree != NULL)
                authscheme_list[auth_user->auth_module - 1].requestFree(this);
            else {
                delete state();
                state(NULL);
            }
        }

        /* unlink from the auth_user struct */
        link = auth_user->requests.head;

        while (link && (link->data != this))
            link = link->next;

        assert(link != NULL);

        dlinkDelete(link, &auth_user->requests);

        dlinkNodeDelete(link);

        /* unlock the request structure's lock */
        authenticateAuthUserUnlock(auth_user);

        auth_user = NULL;
    } else
        assert(state() == NULL);

    safe_free (message);
}

void
AuthUserRequest::setDenyMessage (char const *aString)
{
    safe_free (message);
    message = xstrdup (aString);
}

char const *
AuthUserRequest::getDenyMessage ()
{
    return message;
}

char const *
authenticateAuthUserRequestMessage(auth_user_request_t * auth_user_request)
{
    if (auth_user_request)
        return auth_user_request->getDenyMessage();

    return NULL;
}

void
authenticateSetDenyMessage (auth_user_request_t * auth_user_request, char const *message)
{
    auth_user_request->setDenyMessage (message);
}

static void

authenticateAuthUserRequestSetIp(auth_user_request_t * auth_user_request, struct in_addr ipaddr)
{
    auth_user_ip_t *ipdata, *tempnode;
    auth_user_t *auth_user;
    char *ip1;
    int found = 0;
    CBDATA_INIT_TYPE(auth_user_ip_t);

    if (!auth_user_request->auth_user)
        return;

    auth_user = auth_user_request->auth_user;

    ipdata = (auth_user_ip_t *) auth_user->ip_list.head;

    /*
     * we walk the entire list to prevent the first item in the list
     * preventing old entries being flushed and locking a user out after
     * a timeout+reconfigure
     */
    while (ipdata)
    {
        tempnode = (auth_user_ip_t *) ipdata->node.next;
        /* walk the ip list */

        if (ipdata->ipaddr.s_addr == ipaddr.s_addr) {
            /* This ip has alreadu been seen. */
            found = 1;
            /* update IP ttl */
            ipdata->ip_expiretime = squid_curtime;
        } else if (ipdata->ip_expiretime + Config.authenticateIpTTL < squid_curtime) {
            /* This IP has expired - remove from the seen list */
            dlinkDelete(&ipdata->node, &auth_user->ip_list);
            cbdataFree(ipdata);
            /* catch incipient underflow */
            assert(auth_user->ipcount);
            auth_user->ipcount--;
        }

        ipdata = tempnode;
    }

    if (found)
        return;

    /* This ip is not in the seen list */
    ipdata = cbdataAlloc(auth_user_ip_t);

    ipdata->ip_expiretime = squid_curtime;

    ipdata->ipaddr = ipaddr;

    dlinkAddTail(ipdata, &ipdata->node, &auth_user->ip_list);

    auth_user->ipcount++;

    ip1 = xstrdup(inet_ntoa(ipaddr));

    debug(29, 2) ("authenticateAuthUserRequestSetIp: user '%s' has been seen at a new IP address (%s)\n", auth_user->username(), ip1);

    safe_free(ip1);
}

void

authenticateAuthUserRequestRemoveIp(auth_user_request_t * auth_user_request, struct in_addr ipaddr)
{
    auth_user_ip_t *ipdata;
    auth_user_t *auth_user;

    if (!auth_user_request->auth_user)
        return;

    auth_user = auth_user_request->auth_user;

    ipdata = (auth_user_ip_t *) auth_user->ip_list.head;

    while (ipdata)
    {
        /* walk the ip list */

        if (ipdata->ipaddr.s_addr == ipaddr.s_addr) {
            /* remove the node */
            dlinkDelete(&ipdata->node, &auth_user->ip_list);
            cbdataFree(ipdata);
            /* catch incipient underflow */
            assert(auth_user->ipcount);
            auth_user->ipcount--;
            return;
        }

        ipdata = (auth_user_ip_t *) ipdata->node.next;
    }

}

static void
authenticateAuthUserClearIp(auth_user_t * auth_user)
{
    auth_user_ip_t *ipdata, *tempnode;

    if (!auth_user)
        return;

    ipdata = (auth_user_ip_t *) auth_user->ip_list.head;

    while (ipdata) {
        tempnode = (auth_user_ip_t *) ipdata->node.next;
        /* walk the ip list */
        dlinkDelete(&ipdata->node, &auth_user->ip_list);
        cbdataFree(ipdata);
        /* catch incipient underflow */
        assert(auth_user->ipcount);
        auth_user->ipcount--;
        ipdata = tempnode;
    }

    /* integrity check */
    assert(auth_user->ipcount == 0);
}


void
authenticateAuthUserRequestClearIp(auth_user_request_t * auth_user_request)
{
    if (auth_user_request)
        authenticateAuthUserClearIp(auth_user_request->auth_user);
}

size_t
authenticateAuthUserRequestIPCount(auth_user_request_t * auth_user_request)
{
    assert(auth_user_request);
    assert(auth_user_request->auth_user);
    return auth_user_request->auth_user->ipcount;
}


/* Get Auth User: Return a filled out auth_user structure for the given
 * Proxy Auth (or Auth) header. It may be a cached Auth User or a new
 * Unauthenticated structure. The structure is given an inital lock here.
 */
auth_user_request_t *
AuthUserRequest::createAuthUser(const char *proxy_auth)
{
    auth_user_request_t *result = new auth_user_request_t;
    /* and lock for the callers instance */

    result->lock()

    ;
    /* The scheme is allowed to provide a cached auth_user or a new one */
    result->decodeAuth(proxy_auth);

    return result;
}

/*
 * authenticateUserAuthenticated: is this auth_user structure logged in ?
 */
int
authenticateUserAuthenticated(auth_user_request_t * auth_user_request)
{
    if (!authenticateValidateUser(auth_user_request))
        return 0;

    if (auth_user_request->auth_user->auth_module > 0) {
        /* legacy interface */

        if (authscheme_list[auth_user_request->auth_user->auth_module - 1].authenticated)
            return authscheme_list[auth_user_request->auth_user->auth_module - 1].authenticated(auth_user_request);
        else {
            /* state interface */
            assert (auth_user_request->state());
            return auth_user_request->state()->authenticated();
        }
    } else
        return 0;
}

/*
 * authenticateAuthenticateUser: call the module specific code to 
 * log this user request in.
 * Cache hits may change the auth_user pointer in the structure if needed.
 * This is basically a handle approach.
 */
static void
authenticateAuthenticateUser(auth_user_request_t * auth_user_request, HttpRequest * request, ConnStateData::Pointer &conn, http_hdr_type type)
{
    assert(auth_user_request != NULL);

    if (auth_user_request->auth_user->auth_module > 0) {
        if (authscheme_list[auth_user_request->auth_user->auth_module - 1].authAuthenticate)
            authscheme_list[auth_user_request->auth_user->auth_module - 1].authAuthenticate(auth_user_request, request, conn, type);
        else {
            assert (auth_user_request->state());
            auth_user_request->state()->authenticate(request, conn, type);
        }
    }
}

static auth_user_request_t *
authTryGetUser (auth_user_request_t **auth_user_request, ConnStateData::Pointer & conn, HttpRequest * request)
{
    if (*auth_user_request)
        return *auth_user_request;
    else if (request != NULL && request->auth_user_request)
        return request->auth_user_request;
    else if (conn.getRaw() != NULL)
        return conn->auth_user_request;
    else
        return NULL;
}

/* returns one of
 * AUTH_ACL_CHALLENGE,
 * AUTH_ACL_HELPER,
 * AUTH_ACL_CANNOT_AUTHENTICATE,
 * AUTH_AUTHENTICATED
 *
 * How to use: In your proxy-auth dependent acl code, use the following 
 * construct:
 * int rv;
 * if ((rv = AuthenticateAuthenticate()) != AUTH_AUTHENTICATED)
 *   return rv;
 * 
 * when this code is reached, the request/connection is authenticated.
 *
 * if you have non-acl code, but want to force authentication, you need a 
 * callback mechanism like the acl testing routines that will send a 40[1|7] to
 * the client when rv==AUTH_ACL_CHALLENGE, and will communicate with 
 * the authenticateStart routine for rv==AUTH_ACL_HELPER
 */
auth_acl_t

AuthUserRequest::authenticate(auth_user_request_t ** auth_user_request, http_hdr_type headertype, HttpRequest * request, ConnStateData::Pointer conn, struct in_addr src_addr)
{
    const char *proxy_auth;
    assert(headertype != 0);

    proxy_auth = httpHeaderGetStr(&request->header, headertype);

    /*
     * a note on proxy_auth logix here:
     * proxy_auth==NULL -> unauthenticated request || already
     * authenticated connection so we test for an authenticated
     * connection when we recieve no authentication header.
     */

    if (((proxy_auth == NULL) && (!authenticateUserAuthenticated(authTryGetUser(auth_user_request,conn,request))))
            || (conn.getRaw() != NULL  && conn->auth_type == AUTH_BROKEN))
    {
        /* no header or authentication failed/got corrupted - restart */
        debug(28, 4) ("authenticateAuthenticate: broken auth or no proxy_auth header. Requesting auth header.\n");
        /* something wrong with the AUTH credentials. Force a new attempt */

        if (conn.getRaw() != NULL) {
            conn->auth_type = AUTH_UNKNOWN;

            if (conn->auth_user_request)
                conn->auth_user_request->unlock();

            conn->auth_user_request = NULL;
        }

        if (*auth_user_request) {
            /* unlock the ACL lock */
            (*auth_user_request)->unlock();
            auth_user_request = NULL;
        }

        return AUTH_ACL_CHALLENGE;
    }

    /*
     * Is this an already authenticated connection with a new auth header?
     * No check for function required in the if: its compulsory for conn based 
     * auth modules
     */
    if (proxy_auth && conn.getRaw() != NULL && conn->auth_user_request &&
            authenticateUserAuthenticated(conn->auth_user_request) &&
            strcmp(proxy_auth, authscheme_list[conn->auth_user_request->auth_user->auth_module - 1].authConnLastHeader(conn->auth_user_request)))
    {
        debug(28, 2) ("authenticateAuthenticate: DUPLICATE AUTH - authentication header on already authenticated connection!. AU %p, Current user '%s' proxy_auth %s\n", conn->auth_user_request, conn->auth_user_request->username(), proxy_auth);
        /* remove this request struct - the link is already authed and it can't be to
         * reauth.
         */

        /* This should _only_ ever occur on the first pass through
         * authenticateAuthenticate 
         */
        assert(*auth_user_request == NULL);
        /* unlock the conn lock on the auth_user_request */
        conn->auth_user_request->unlock();
        /* mark the conn as non-authed. */
        conn->auth_user_request = NULL;
        /* Set the connection auth type */
        conn->auth_type = AUTH_UNKNOWN;
    }

    /* we have a proxy auth header and as far as we know this connection has
     * not had bungled connection oriented authentication happen on it. */
    debug(28, 9) ("authenticateAuthenticate: header %s.\n", proxy_auth ? proxy_auth : "-");

    if (*auth_user_request == NULL)
    {
        debug(28, 9) ("authenticateAuthenticate: This is a new checklist test on FD:%d\n",
                      conn.getRaw() != NULL ? conn->fd : -1);

        if ((!request->auth_user_request)
                && (conn.getRaw() == NULL || conn->auth_type == AUTH_UNKNOWN)) {
            /* beginning of a new request check */
            debug(28, 4) ("authenticateAuthenticate: no connection authentication type\n");

            if (!authenticateValidateUser(*auth_user_request =
                                              createAuthUser(proxy_auth))) {
                /* the decode might have left a username for logging, or a message to
                 * the user */

                if ((*auth_user_request)->username()) {
                    /* lock the user for the request structure link */

                    (*auth_user_request)->lock()

                    ;
                    request->auth_user_request = *auth_user_request;
                }

                /* unlock the ACL reference granted by ...createAuthUser. */
                (*auth_user_request)->unlock();

                *auth_user_request = NULL;

                return AUTH_ACL_CHALLENGE;
            }

            /* the user_request comes prelocked for the caller to createAuthUser (us) */
        } else if (request->auth_user_request) {
            *auth_user_request = request->auth_user_request;
            /* lock the user request for this ACL processing */

            (*auth_user_request)->lock()

            ;
        } else {
            assert (conn.getRaw() != NULL);

            if (conn->auth_user_request != NULL) {
                *auth_user_request = conn->auth_user_request;
                /* lock the user request for this ACL processing */

                (*auth_user_request)->lock()

                ;
            } else {
                /* failed connection based authentication */
                debug(28, 4) ("authenticateAuthenticate: Auth user request %p conn-auth user request %p conn type %d authentication failed.\n",
                              *auth_user_request, conn->auth_user_request, conn->auth_type);
                (*auth_user_request)->unlock();
                *auth_user_request = NULL;
                return AUTH_ACL_CHALLENGE;
            }
        }
    }

    if (!authenticateUserAuthenticated(*auth_user_request))
    {
        /* User not logged in. Log them in */
        authenticateAuthenticateUser(*auth_user_request, request,
                                     conn, headertype);

        switch (authenticateDirection(*auth_user_request)) {

        case 1:

            if (!request->auth_user_request) {

                (*auth_user_request)->lock()

                ;
                request->auth_user_request = *auth_user_request;
            }

            /* fallthrough to -2 */

        case -2:
            /* this ACL check is finished. Unlock. */
            (*auth_user_request)->unlock();

            *auth_user_request = NULL;

            return AUTH_ACL_CHALLENGE;

        case -1:
            /* we are partway through authentication within squid,
             * the *auth_user_request variables stores the auth_user_request
             * for the callback to here - Do not Unlock */
            return AUTH_ACL_HELPER;
        }

        /* on 0 the authentication is finished - fallthrough */
        /* See if user authentication failed for some reason */
        if (!authenticateUserAuthenticated(*auth_user_request)) {
            if ((*auth_user_request)->username()) {
                if (!request->auth_user_request) {
                    /* lock the user for the request structure link */

                    (*auth_user_request)->lock()

                    ;
                    request->auth_user_request = *auth_user_request;
                }
            }

            /* this ACL check is finished. Unlock. */
            (*auth_user_request)->unlock();

            *auth_user_request = NULL;

            return AUTH_ACL_CHALLENGE;
        }
    }

    /* copy username to request for logging on client-side */
    /* the credentials are correct at this point */
    if (!request->auth_user_request)
    {
        /* lock the user for the request structure link */

        (*auth_user_request)->lock()

        ;
        request->auth_user_request = *auth_user_request;

        authenticateAuthUserRequestSetIp(*auth_user_request, src_addr);
    }

    /* Unlock the request - we've authenticated it */
    (*auth_user_request)->unlock();

    return AUTH_AUTHENTICATED;
}

auth_acl_t

AuthUserRequest::tryToAuthenticateAndSetAuthUser(auth_user_request_t ** auth_user_request, http_hdr_type headertype, HttpRequest * request, ConnStateData::Pointer conn, struct in_addr src_addr)
{
    /* If we have already been called, return the cached value */
    auth_user_request_t *t = authTryGetUser (auth_user_request, conn, request);

    if (t && t->lastReply != AUTH_ACL_CANNOT_AUTHENTICATE
            && t->lastReply != AUTH_ACL_HELPER)
    {
        if (!*auth_user_request)
            *auth_user_request = t;

        return t->lastReply;
    }

    /* ok, call the actual authenticator routine. */
    auth_acl_t result = authenticate(auth_user_request, headertype, request, conn, src_addr);

    t = authTryGetUser (auth_user_request, conn, request);

    if (t && result != AUTH_ACL_CANNOT_AUTHENTICATE &&
            result != AUTH_ACL_HELPER)
        t->lastReply = result;

    return result;
}

auth_acl_t

authenticateTryToAuthenticateAndSetAuthUser(auth_user_request_t ** auth_user_request, http_hdr_type headertype, HttpRequest * request, ConnStateData::Pointer conn, struct in_addr src_addr)
{
    return AuthUserRequest::tryToAuthenticateAndSetAuthUser (auth_user_request, headertype,request, conn, src_addr);
}

/* authenticateUserRequestUsername: return a pointer to the username in the */
char const *
authenticateUserRequestUsername(auth_user_request_t * auth_user_request)
{
    assert(auth_user_request != NULL);
    return auth_user_request->username();
}

/* returns
 * 0: no output needed
 * 1: send to client
 * -1: send to helper
 * -2: authenticate broken in some fashion
 */
int
authenticateDirection(auth_user_request_t * auth_user_request)
{
    if (!auth_user_request)
        return -2;

    if (authenticateUserAuthenticated(auth_user_request))
        return 0;

    if (auth_user_request->auth_user->auth_module > 0) {
        if (authscheme_list[auth_user_request->auth_user->auth_module - 1].getdirection)
            return authscheme_list[auth_user_request->auth_user->auth_module - 1].getdirection(auth_user_request);
        else {
            assert (auth_user_request->state());
            return auth_user_request->state()->direction();
        }
    }

    return -2;
}

int
authenticateActiveSchemeCount(void)
{
    int i = 0, rv = 0;

    for (i = 0; authscheme_list && authscheme_list[i].typestr; i++)
        if (authscheme_list[i].configured())
            rv++;

    debug(29, 9) ("authenticateActiveSchemeCount: %d active.\n", rv);

