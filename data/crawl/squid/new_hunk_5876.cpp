
/*
 * $Id: auth_digest.cc,v 1.1 2001/01/31 22:16:41 hno Exp $
 *
 * DEBUG: section 29    Authenticator
 * AUTHOR: Robert Collins
 *
 * SQUID Internet Object Cache  http://squid.nlanr.net/Squid/
 * ----------------------------------------------------------
 *
 *  Squid is the result of efforts by numerous individuals from the
 *  Internet community.  Development is led by Duane Wessels of the
 *  National Laboratory for Applied Network Research and funded by the
 *  National Science Foundation.  Squid is Copyrighted (C) 1998 by
 *  the Regents of the University of California.  Please see the
 *  COPYRIGHT file for full details.  Squid incorporates software
 *  developed and/or copyrighted by other sources.  Please see the
 *  CREDITS file for full details.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
 *
 */

/* The functions in this file handle authentication.
 * They DO NOT perform access control or auditing.
 * See acl.c for access control and client_side.c for auditing */


#include "squid.h"
#include "rfc2617.h"
#include "auth_digest.h"

static void
authenticateStateFree(authenticateStateData * r)
{
    cbdataFree(r);
}

/* Digest Scheme */

static HLPCB authenticateDigestHandleReply;
static AUTHSACTIVE authenticateDigestActive;
static AUTHSADDHEADER authDigestAddHeader;
#if WAITING_FOR_TE
static AUTHSADDTRAILER authDigestAddTrailer;
#endif
static AUTHSAUTHED authDigestAuthenticated;
static AUTHSAUTHUSER authenticateDigestAuthenticateUser;
static AUTHSCONFIGURED authDigestConfigured;
static AUTHSDIRECTION authenticateDigestDirection;
static AUTHSDECODE authenticateDigestDecodeAuth;
static AUTHSDUMP authDigestCfgDump;
static AUTHSFIXERR authenticateDigestFixHeader;
static AUTHSFREE authenticateDigestUserFree;
static AUTHSFREECONFIG authDigestFreeConfig;
static AUTHSINIT authDigestInit;
static AUTHSPARSE authDigestParse;
static AUTHSREQFREE authDigestAURequestFree;
static AUTHSSTART authenticateDigestStart;
static AUTHSSTATS authenticateDigestStats;
static AUTHSUSERNAME authenticateDigestUsername;
static AUTHSSHUTDOWN authDigestDone;

static helper *digestauthenticators = NULL;

static hash_table *digest_nonce_cache;

static auth_digest_config *digestConfig = NULL;

static int authdigest_initialised = 0;
MemPool *digest_user_pool = NULL;
MemPool *digest_request_pool = NULL;
MemPool *digest_nonce_pool = NULL;

CBDATA_TYPE(authenticateStateData);

/*
 *
 * Nonce Functions
 *
 */

static void authenticateDigestNonceCacheCleanup(void *data);
static digest_nonce_h *authenticateDigestNonceFindNonce(const char *nonceb64);
digest_nonce_h *authenticateDigestNonceNew();
void authenticateDigestNonceDelete(digest_nonce_h * nonce);
void authenticateDigestNonceSetup();
void authenticateDigestNonceShutdown();
void authenticateDigestNonceReconfigure();
const char *authenticateDigestNonceNonceb64(digest_nonce_h * nonce);
int authDigestNonceIsValid(digest_nonce_h * nonce, char nc[9]);
int authDigestNonceIsStale(digest_nonce_h * nonce);
void authDigestNonceEncode(digest_nonce_h * nonce);
int authDigestNonceLastRequest(digest_nonce_h * nonce);
void authDigestNonceLink(digest_nonce_h * nonce);
void authDigestNonceUnlink(digest_nonce_h * nonce);
int authDigestNonceLinks(digest_nonce_h * nonce);
void authDigestNonceUserUnlink(digest_nonce_h * nonce);
void authDigestNoncePurge(digest_nonce_h * nonce);

void
authDigestNonceEncode(digest_nonce_h * nonce)
{
    if (!nonce)
	return;
    if (nonce->nonceb64)
	xfree(nonce->nonceb64);
    nonce->nonceb64 = xstrdup(base64_encode_bin((char *) &(nonce->noncedata), sizeof(digest_nonce_data)));
}

digest_nonce_h *
authenticateDigestNonceNew()
{
    digest_nonce_h *newnonce = memPoolAlloc(digest_nonce_pool);
    digest_nonce_h *temp;

/* NONCE CREATION - NOTES AND REASONING. RBC 20010108
 * === EXCERPT FROM RFC 2617 ===
 * The contents of the nonce are implementation dependent. The quality
 * of the implementation depends on a good choice. A nonce might, for
 * example, be constructed as the base 64 encoding of
 * 
 * time-stamp H(time-stamp ":" ETag ":" private-key)
 * 
 * where time-stamp is a server-generated time or other non-repeating
 * value, ETag is the value of the HTTP ETag header associated with
 * the requested entity, and private-key is data known only to the
 * server.  With a nonce of this form a server would recalculate the
 * hash portion after receiving the client authentication header and
 * reject the request if it did not match the nonce from that header
 * or if the time-stamp value is not recent enough. In this way the
 * server can limit the time of the nonce's validity. The inclusion of
 * the ETag prevents a replay request for an updated version of the
 * resource.  (Note: including the IP address of the client in the
 * nonce would appear to offer the server the ability to limit the
 * reuse of the nonce to the same client that originally got it.
 * However, that would break proxy farms, where requests from a single
 * user often go through different proxies in the farm. Also, IP
 * address spoofing is not that hard.)
 * ====
 * 
 * Now for my reasoning:
 * We will not accept a unrecognised nonce->we have all recognisable nonces stored
 * If we send out unique base64 encodings we guarantee that a given nonce applies
 * to only one user (barring attacks or really bad timing with expiry and creation).
 * Using a random component in the nonce allows us to loop to find a unique nonce.
 * We use H(nonce_data) so the nonce is meaningless to the reciever.
 * So our nonce looks like base64(H(timestamp,pointertohash,randomdata))
 * And even if our randomness is not very random (probably due to bad coding on my
 * part) we don't really care - the timestamp and memory pointer should provide
 * enough protection for the users authentication.
 */

    /* create a new nonce */
    newnonce->nc = 0;
    newnonce->flags.valid = 1;
    newnonce->noncedata.self = newnonce;
    newnonce->noncedata.creationtime = current_time.tv_sec;
    newnonce->noncedata.randomdata = random();

    authDigestNonceEncode(newnonce);
    /* loop until we get a unique nonce. The nonce creation must have a random factor */
    while ((temp = authenticateDigestNonceFindNonce(newnonce->nonceb64))) {
	/* create a new nonce */
	newnonce->noncedata.randomdata = random();
	authDigestNonceEncode(newnonce);
    }
    hash_join(digest_nonce_cache, (hash_link *) newnonce);
    /* the cache's link */
    authDigestNonceLink(newnonce);
    newnonce->flags.incache = 1;
    debug(29, 5) ("authenticateDigestNonceNew: created nonce %0p at %d\n", newnonce, newnonce->noncedata.creationtime);
    return newnonce;
}

void
authenticateDigestNonceDelete(digest_nonce_h * nonce)
{
    if (nonce) {
	assert(nonce->references == 0);
#if UNREACHABLECODE
	if (nonce->flags.incache)
	    hash_remove_link(digest_nonce_cache, (hash_link *) nonce);
#endif
	assert(nonce->flags.incache == 0);
	safe_free(nonce->nonceb64);
	memPoolFree(digest_nonce_pool, nonce);
    }
}

void 
authenticateDigestNonceSetup()
{
    if (!digest_nonce_pool)
	digest_nonce_pool = memPoolCreate("Digest Scheme nonce's", sizeof(digest_nonce_h));
    if (!digest_nonce_cache) {
	digest_nonce_cache = hash_create((HASHCMP *) strcmp, 7921, hash_string);
	assert(digest_nonce_cache);
	eventAdd("Digest none cache maintenance", authenticateDigestNonceCacheCleanup, NULL, digestConfig->nonceGCInterval, 1);
    }
}

void 
authenticateDigestNonceShutdown()
{
    /* 
     * We empty the cache of any nonces left in there.
     */
    digest_nonce_h *nonce;
    if (digest_nonce_cache) {
	debug(29, 2) ("authenticateDigestNonceShutdown: Shutting down nonce cache \n");
	hash_first(digest_nonce_cache);
	while ((nonce = ((digest_nonce_h *) hash_next(digest_nonce_cache)))) {
	    assert(nonce->flags.incache);
	    authDigestNoncePurge(nonce);
	}
    }
    if (digest_nonce_pool) {
	assert(memPoolInUseCount(digest_nonce_pool) == 0);
	memPoolDestroy(digest_nonce_pool);
	digest_nonce_pool = NULL;
    }
    debug(29, 2) ("authenticateDigestNonceShutdown: Nonce cache shutdown\n");
}

void 
authenticateDigestNonceReconfigure()
{
}

void
authenticateDigestNonceCacheCleanup(void *data)
{
    /*
     * We walk the hash by nonceb64 as that is the unique key we use.
     * For big hashs tables we could consider stepping through the cache, 100/200
     * entries at a time. Lets see how it flys first.
     */
    digest_nonce_h *nonce;
    debug(29, 3) ("authenticateDigestNonceCacheCleanup: Cleaning the nonce cache now\n");
    debug(29, 3) ("authenticateDigestNonceCacheCleanup: Current time: %d\n",
	current_time.tv_sec);
    hash_first(digest_nonce_cache);
    while ((nonce = ((digest_nonce_h *) hash_next(digest_nonce_cache)))) {
	debug(29, 3) ("authenticateDigestNonceCacheCleanup: nonce entry  : '%s'\n", nonce->nonceb64);
	debug(29, 4) ("authenticateDigestNonceCacheCleanup: Creation time: %d\n", nonce->noncedata.creationtime);
	if (authDigestNonceIsStale(nonce)) {
	    debug(29, 4) ("authenticateDigestNonceCacheCleanup: Removing nonce %s from cache due to timeout.\n", nonce->nonceb64);
	    assert(nonce->flags.incache);
	    /* invalidate nonce so future requests fail */
	    nonce->flags.valid = 0;
	    /* if it is tied to a auth_user, remove the tie */
	    authDigestNonceUserUnlink(nonce);
	    authDigestNoncePurge(nonce);
	}
    }
    debug(29, 3) ("authenticateDigestNonceCacheCleanup: Finished cleaning the nonce cache.\n");
    if (authenticateDigestActive())
	eventAdd("Digest none cache maintenance", authenticateDigestNonceCacheCleanup, NULL, digestConfig->nonceGCInterval, 1);
}

void
authDigestNonceLink(digest_nonce_h * nonce)
{
    assert(nonce != NULL);
    nonce->references++;
    debug(29, 9) ("authDigestNonceLink: nonce '%d' now at '%d'.\n", nonce, nonce->references);
}

int
authDigestNonceLinks(digest_nonce_h * nonce)
{
    if (!nonce)
	return -1;
    return nonce->references;
}

void
authDigestNonceUnlink(digest_nonce_h * nonce)
{
    assert(nonce != NULL);
    if (nonce->references > 0) {
	nonce->references--;
    } else {
	debug(29, 1) ("authDigestNonceUnlink; Attempt to lower nonce %d refcount below 0!\n", nonce);
    }
    debug(29, 9) ("authDigestNonceUnlink: nonce '%d' now at '%d'.\n", nonce, nonce->references);
    if (nonce->references == 0)
	authenticateDigestNonceDelete(nonce);
}

const char *
authenticateDigestNonceNonceb64(digest_nonce_h * nonce)
{
    if (!nonce)
	return NULL;
    return nonce->nonceb64;
}

digest_nonce_h *
authenticateDigestNonceFindNonce(const char *nonceb64)
{
    digest_nonce_h *nonce = NULL;
    if (nonceb64 == NULL)
	return NULL;
    debug(29, 9) ("authDigestNonceFindNonce:looking for nonceb64 '%s' in the nonce cache.\n", nonceb64);
    if ((nonce = hash_lookup(digest_nonce_cache, nonceb64)))
	while ((strcmp(nonce->nonceb64, nonceb64)) && (nonce->next))
	    nonce = nonce->next;
    if ((nonce == NULL) || (strcmp(nonce->nonceb64, nonceb64)))
	return NULL;
    debug(29, 9) ("authDigestNonceFindNonce: Found nonce '%d'\n", nonce);
    return nonce;
}

int
authDigestNonceIsValid(digest_nonce_h * nonce, char nc[9])
{
    int intnc;
    /* do we have a nonce ? */
    if (!nonce)
	return 0;
    intnc = atoi(nc);
    if (intnc != nonce->nc + 1) {
	debug(29, 4) ("authDigestNonceIsValid: Nonce count doesn't match\n");
	nonce->flags.valid = 0;
	return 0;
    }
    /* has it already been invalidated ? */
    if (!nonce->flags.valid) {
	debug(29, 4) ("authDigestNonceIsValid: Nonce already invalidated\n");
	return 0;
    }
    /* seems ok */
    return -1;
}

int
authDigestNonceIsStale(digest_nonce_h * nonce)
{
    /* do we have a nonce ? */
    if (!nonce)
	return -1;
    /* has it's max duration expired? */
    if (nonce->noncedata.creationtime + digestConfig->noncemaxduration < current_time.tv_sec) {
	debug(29, 4) ("authDigestNonceIsStale: Nonce is too old. %d %d %d\n", nonce->noncedata.creationtime, digestConfig->noncemaxduration, current_time.tv_sec);
	nonce->flags.valid = 0;
	return -1;
    }
    if (nonce->nc > 99999998) {
	debug(29, 4) ("authDigestNonceIsStale: Nonce count overflow\n");
	nonce->flags.valid = 0;
	return -1;
    }
    if (nonce->nc > digestConfig->noncemaxuses) {
	debug(29, 4) ("authDigestNoncelastRequest: Nonce count over user limit\n");
	nonce->flags.valid = 0;
	return -1;
    }
    /* seems ok */
    return 0;
}

/* return -1 if the digest will be stale on the next request */
int
authDigestNonceLastRequest(digest_nonce_h * nonce)
{
    if (!nonce)
	return -1;
    if (nonce->nc == 99999997) {
	debug(29, 4) ("authDigestNoncelastRequest: Nonce count about to overflow\n");
	return -1;
    }
    if (nonce->nc == digestConfig->noncemaxuses - 1) {
	debug(29, 4) ("authDigestNoncelastRequest: Nonce count about to hit user limit\n");
	return -1;
    }
    /* and other tests are possible. */
    return 0;
}

void
authDigestNoncePurge(digest_nonce_h * nonce)
{
    if (!nonce)
	return;
    if (!nonce->flags.incache)
	return;
    hash_remove_link(digest_nonce_cache, (hash_link *) nonce);
    nonce->flags.incache = 0;
    /* the cache's link */
    authDigestNonceUnlink(nonce);
}

/* USER related functions */


int
authDigestUsercmpname(digest_user_h * u1, digest_user_h * u2)
{
    return strcmp(u1->username, u2->username);
}

auth_user_t *
authDigestUserFindUsername(const char *username)
{
    auth_user_hash_pointer *usernamehash;
    auth_user_t *auth_user;
    debug(29, 9) ("authDigestUserFindUsername: Looking for user '%s'\n", username);
    if (username && (usernamehash = hash_lookup(proxy_auth_username_cache, username))) {
	while ((usernamehash->auth_user->auth_type != AUTH_DIGEST) &&
	    (usernamehash->next))
	    usernamehash = usernamehash->next;
	auth_user = NULL;
	if (usernamehash->auth_user->auth_type == AUTH_DIGEST) {
	    auth_user = usernamehash->auth_user;
	}
	return auth_user;
    }
    return NULL;
}

digest_user_h *
authDigestUserNew()
{
    return memPoolAlloc(digest_user_pool);
}

void
authDigestUserSetup()
{
    if (!digest_user_pool)
	digest_user_pool = memPoolCreate("Digest Scheme User Data", sizeof(digest_user_h));
}

void
authDigestUserShutdown()
{
    /*
     * Future work: the auth framework could flush it's cache 
     */
    auth_user_hash_pointer *usernamehash;
    auth_user_t *auth_user;
    hash_first(proxy_auth_username_cache);
    while ((usernamehash = ((auth_user_hash_pointer *) hash_next(proxy_auth_username_cache)))) {
	auth_user = usernamehash->auth_user;
	if (strcmp(authscheme_list[auth_user->auth_module - 1].typestr, "digest") == 0)
	    /* it's digest */
	    authenticateAuthUserUnlock(auth_user);
    }
    if (digest_user_pool) {
	assert(memPoolInUseCount(digest_user_pool) == 0);
	memPoolDestroy(digest_user_pool);
	digest_user_pool = NULL;
    }
}


/* request related functions */

/* delete the digest reuqest structure. Does NOT delete related structures */
void
authDigestRequestDelete(digest_request_h * digest_request)
{
    if (digest_request->nonceb64)
	xfree(digest_request->nonceb64);
    if (digest_request->cnonce)
	xfree(digest_request->cnonce);
    if (digest_request->realm)
	xfree(digest_request->realm);
    if (digest_request->pszPass)
	xfree(digest_request->pszPass);
    if (digest_request->algorithm)
	xfree(digest_request->algorithm);
    if (digest_request->pszMethod)
	xfree(digest_request->pszMethod);
    if (digest_request->qop)
	xfree(digest_request->qop);
    if (digest_request->uri)
	xfree(digest_request->uri);
    if (digest_request->response)
	xfree(digest_request->response);
    if (digest_request->nonce)
	authDigestNonceUnlink(digest_request->nonce);
    memPoolFree(digest_request_pool, digest_request);
}

void
authDigestAURequestFree(auth_user_request_t * auth_user_request)
{
    if (auth_user_request->scheme_data != NULL)
	authDigestRequestDelete((digest_request_h *) auth_user_request->scheme_data);
}

digest_request_h *
authDigestRequestNew()
{
    digest_request_h *tmp;
    tmp = memPoolAlloc(digest_request_pool);
    assert(tmp != NULL);
    return tmp;
}

void
authDigestRequestSetup()
{
    if (!digest_request_pool)
	digest_request_pool = memPoolCreate("Digest Scheme Request Data", sizeof(digest_request_h));
}

void
authDigestRequestShutdown()
{
    /* No requests should be in progress when we get here */
    if (digest_request_pool) {
	assert(memPoolInUseCount(digest_request_pool) == 0);
	memPoolDestroy(digest_request_pool);
	digest_request_pool = NULL;
    }
}


void
authDigestDone(void)
{
    if (digestauthenticators)
	helperShutdown(digestauthenticators);
    authdigest_initialised = 0;
    if (!shutting_down) {
	authenticateDigestNonceReconfigure();
	return;
    }
    if (digestauthenticators) {
	helperFree(digestauthenticators);
	digestauthenticators = NULL;
    }
    authDigestRequestShutdown();
    authDigestUserShutdown();
    authenticateDigestNonceShutdown();
    debug(29, 2) ("authenticateDigestDone: Digest authentication shut down.\n");
}

static void
authDigestCfgDump(StoreEntry * entry, const char *name, authScheme * scheme)
{
    auth_digest_config *config = scheme->scheme_data;
    wordlist *list = config->authenticate;
    debug(29, 9) ("authDigestCfgDump: Dumping configuration\n");
    storeAppendPrintf(entry, "%s %s", name, "digest");
    while (list != NULL) {
	storeAppendPrintf(entry, " %s", list->key);
	list = list->next;
    }
    storeAppendPrintf(entry, "\n%s %s realm %s\n%s %s children %d\n%s %s nonce_max_count %d\n%s %s nonce_max_duration %d seconds\n%s %s nonce_garbage_interval %d seconds\n",
	name, "digest", config->digestAuthRealm,
	name, "digest", config->authenticateChildren,
	name, "digest", config->noncemaxuses,
	name, "digest", config->noncemaxduration,
	name, "digest", config->nonceGCInterval);
}

void
authSchemeSetup_digest(authscheme_entry_t * authscheme)
{
    assert(!authdigest_initialised);
    authscheme->Active = authenticateDigestActive;
    authscheme->configured = authDigestConfigured;
    authscheme->parse = authDigestParse;
    authscheme->freeconfig = authDigestFreeConfig;
    authscheme->dump = authDigestCfgDump;
    authscheme->init = authDigestInit;
    authscheme->authAuthenticate = authenticateDigestAuthenticateUser;
    authscheme->authenticated = authDigestAuthenticated;
    authscheme->authFixHeader = authenticateDigestFixHeader;
    authscheme->FreeUser = authenticateDigestUserFree;
    authscheme->AddHeader = authDigestAddHeader;
#if WAITING_FOR_TE
    authscheme->AddTrailer = authDigestAddTrailer;
#endif
    authscheme->authStart = authenticateDigestStart;
    authscheme->authStats = authenticateDigestStats;
    authscheme->authUserUsername = authenticateDigestUsername;
    authscheme->getdirection = authenticateDigestDirection;
    authscheme->oncloseconnection = NULL;
    authscheme->decodeauth = authenticateDigestDecodeAuth;
    authscheme->donefunc = authDigestDone;
    authscheme->requestFree = authDigestAURequestFree;
}

int
authenticateDigestActive()
{
    return (authdigest_initialised == 1) ? 1 : 0;
}
int
authDigestConfigured()
{
    if ((digestConfig != NULL) && (digestConfig->authenticate != NULL) &&
	(digestConfig->authenticateChildren != 0) &&
	(digestConfig->digestAuthRealm != NULL) && (digestConfig->noncemaxduration > -1))
	return 1;
    return 0;
}

int
authDigestAuthenticated(auth_user_request_t * auth_user_request)
{
    if (auth_user_request->auth_user->flags.credentials_ok == 1)
	return 1;
    else
	return 0;
}

/* log a digest user in
 */
static void
authenticateDigestAuthenticateUser(auth_user_request_t * auth_user_request, request_t * request, ConnStateData * conn, http_hdr_type type)
{
    auth_user_t *auth_user;
    digest_request_h *digest_request;
    digest_user_h *digest_user;

    HASHHEX SESSIONKEY;
    HASHHEX HA2 = "";
    HASHHEX Response;

    assert(auth_user_request->auth_user != NULL);
    auth_user = auth_user_request->auth_user;

    /* if the check has corrupted the user, just return */
    if (auth_user_request->auth_user->flags.credentials_ok == 3) {
	return;
    }
    assert(auth_user->scheme_data != NULL);
    digest_user = auth_user->scheme_data;

    assert(auth_user_request->scheme_data != NULL);
    digest_request = auth_user_request->scheme_data;

    /* do we have the HA1 */
    if (!digest_user->HA1created) {
	auth_user_request->auth_user->flags.credentials_ok = 2;
	return;
    }
    if (digest_request->nonce == NULL) {
	/* this isn't a nonce we issued */
	/* TODO: record breaks in authentication at the request level 
	 * This is probably best done with support changes at the auth_rewrite level -RBC
	 * and can wait for auth_rewrite V2.
	 */
	auth_user->flags.credentials_ok = 3;
	return;
    }
    DigestCalcHA1(digest_request->algorithm, NULL, NULL, NULL,
	authenticateDigestNonceNonceb64(digest_request->nonce),
	digest_request->cnonce,
	digest_user->HA1, SESSIONKEY);
    DigestCalcResponse(SESSIONKEY, authenticateDigestNonceNonceb64(digest_request->nonce),
	digest_request->nc, digest_request->cnonce, digest_request->qop,
	RequestMethodStr[request->method], digest_request->uri, HA2, Response);

    debug(29, 9) ("\nResponse = '%s'\n"
	"squid is = '%s'\n", digest_request->response, Response);

    if (strcasecmp(digest_request->response, Response)) {
	auth_user->flags.credentials_ok = 3;
	return;
    }
    auth_user->flags.credentials_ok = 1;
    /* password was checked and did match */
    debug(29, 4) ("authenticateDigestAuthenticateuser: user '%s' validated OK\n",
	digest_user->username);

    /* auth_user is now linked, we reset these values
     * after external auth occurs anyway */
    auth_user->expiretime = current_time.tv_sec;
    auth_user->ip_expiretime = squid_curtime;
    return;
}

int 
authenticateDigestDirection(auth_user_request_t * auth_user_request)
{
    digest_request_h *digest_request;
/* null auth_user is checked for by authenticateDirection */
    switch (auth_user_request->auth_user->flags.credentials_ok) {
    case 0:			/* not checked */
	return -1;
    case 1:			/* checked & ok */
	digest_request = auth_user_request->scheme_data;
	if (authDigestNonceIsStale(digest_request->nonce))
	    /* send stale response to the client agent */
	    return -2;
	return 0;
    case 2:			/* partway through checking. */
	return -1;
    case 3:			/* authentication process failed. */
	return -2;
    }
    return -2;
}

/* add the [proxy]authorisation header */
void
authDigestAddHeader(auth_user_request_t * auth_user_request, HttpReply * rep, int accel)
{
    int type;
    digest_request_h *digest_request;
    if (!auth_user_request)
	return;
    digest_request = auth_user_request->scheme_data;
    /* don't add to authentication error pages */
    if ((!accel && rep->sline.status == HTTP_PROXY_AUTHENTICATION_REQUIRED)
	|| (accel && rep->sline.status == HTTP_UNAUTHORIZED))
	return;
    type = accel ? HDR_AUTHENTICATION_INFO : HDR_PROXY_AUTHENTICATION_INFO;

#if WAITING_FOR_TE
    /* test for http/1.1 transfer chunked encoding */
    if (chunkedtest)
	return;
#endif

    if ((digestConfig->authenticate) && authDigestNonceLastRequest(digest_request->nonce)) {
	digest_request->flags.authinfo_sent = 1;
	debug(29, 9) ("authDigestAddHead: Sending type:%d header: 'nextnonce=\"%s\"", type, authenticateDigestNonceNonceb64(digest_request->nonce));
	httpHeaderPutStrf(&rep->header, type, "nextnonce=\"%s\"", authenticateDigestNonceNonceb64(digest_request->nonce));
    }
}

#if WAITING_FOR_TE
/* add the [proxy]authorisation header */
void
authDigestAddTrailer(auth_user_request_t * auth_user_request, HttpReply * rep, int accel)
{
    int type;
    digest_request_h *digest_request;
    if (!auth_user_request)
	return;
    digest_request = auth_user_request->scheme_data;
    /* has the header already been send? */
    if (digest_request->flags.authinfo_sent)
	return;
    /* don't add to authentication error pages */
    if ((!accel && rep->sline.status == HTTP_PROXY_AUTHENTICATION_REQUIRED)
	|| (accel && rep->sline.status == HTTP_UNAUTHORIZED))
	return;
    type = accel ? HDR_AUTHENTICATION_INFO : HDR_PROXY_AUTHENTICATION_INFO;

    if ((digestConfig->authenticate) && authDigestNonceLastRequest(digest_request->nonce)) {
	debug(29, 9) ("authDigestAddTrailer: Sending type:%d header: 'nextnonce=\"%s\"", type, authenticateDigestNonceNonceb64(digest_request->nonce));
	httpTrailerPutStrf(&rep->header, type, "nextnonce=\"%s\"", authenticateDigestNonceNonceb64(digest_request->nonce));
    }
}
#endif

/* add the [www-|Proxy-]authenticate header on a 407 or 401 reply */
void
authenticateDigestFixHeader(auth_user_request_t * auth_user_request, HttpReply * rep, http_hdr_type type, request_t * request)
{
    digest_request_h *digest_request;
    int stale = 0;
    digest_nonce_h *nonce = authenticateDigestNonceNew();
    if (auth_user_request && authDigestAuthenticated(auth_user_request) && auth_user_request->scheme_data) {
	digest_request = auth_user_request->scheme_data;
	stale = authDigestNonceIsStale(digest_request->nonce);
    }
    if (digestConfig->authenticate) {
	debug(29, 9) ("authenticateFixHeader: Sending type:%d header: 'Digest realm=\"%s\", nonce=\"%s\", qop=\"%s\", stale=%s\n", type, digestConfig->digestAuthRealm, authenticateDigestNonceNonceb64(nonce), QOP_AUTH, stale ? "true" : "false");
	/* in the future, for WWW auth we may want to support the domain entry */
	httpHeaderPutStrf(&rep->header, type, "Digest realm=\"%s\", nonce=\"%s\", qop=\"%s\", stale=%s", digestConfig->digestAuthRealm, authenticateDigestNonceNonceb64(nonce), QOP_AUTH, stale ? "true" : "false");
    }
}

void
authenticateDigestUserFree(auth_user_t * auth_user)
{
    digest_user_h *digest_user = auth_user->scheme_data;
    dlink_node *link, *tmplink;
    debug(29, 9) ("authenticateDigestFreeUser: Clearing Digest scheme data\n");
    if (!digest_user)
	return;
    safe_free(digest_user->username);

    link = digest_user->nonces.head;
    while (link) {
	tmplink = link;
	link = link->next;
	dlinkDelete(tmplink, &digest_user->nonces);
	authDigestNoncePurge(tmplink->data);
	authDigestNonceUnlink(tmplink->data);
	dlinkNodeDelete(tmplink);
    }

    memPoolFree(digest_user_pool, auth_user->scheme_data);
    auth_user->scheme_data = NULL;
}

static void
authenticateDigestHandleReply(void *data, char *reply)
{
    authenticateStateData *r = data;
    auth_user_request_t *auth_user_request;
    digest_request_h *digest_request;
    digest_user_h *digest_user;
    int valid;
    char *t = NULL;
    debug(29, 9) ("authenticateDigestHandleReply: {%s}\n", reply ? reply : "<NULL>");
    if (reply) {
	if ((t = strchr(reply, ' ')))
	    *t = '\0';
	if (*reply == '\0')
	    reply = NULL;
    }
    assert(r->auth_user_request != NULL);
    auth_user_request = r->auth_user_request;
    assert(auth_user_request->scheme_data != NULL);
    digest_request = auth_user_request->scheme_data;
    digest_user = auth_user_request->auth_user->scheme_data;
    if (reply && (strncasecmp(reply, "ERR", 3) == 0))
	auth_user_request->auth_user->flags.credentials_ok = 3;
    else {
	CvtBin(reply, digest_user->HA1);
	digest_user->HA1created = 1;
    }
    valid = cbdataValid(r->data);
    if (valid)
	r->handler(r->data, NULL);
    cbdataUnlock(r->data);
    authenticateStateFree(r);
}

/* Initialize helpers and the like for this auth scheme. Called AFTER parsing the
 * config file */
static void
authDigestInit(authScheme * scheme)
{
    static int init = 0;
    if (digestConfig->authenticate) {
	authDigestUserSetup();
	authDigestRequestSetup();
	authenticateDigestNonceSetup();
	authdigest_initialised = 1;
	if (digestauthenticators == NULL)
	    digestauthenticators = helperCreate("digestauthenticator");
	digestauthenticators->cmdline = digestConfig->authenticate;
	digestauthenticators->n_to_start = digestConfig->authenticateChildren;
	digestauthenticators->ipc_type = IPC_TCP_SOCKET;
	helperOpenServers(digestauthenticators);
	if (!init) {
	    cachemgrRegister("digestauthenticator", "User Authenticator Stats",
		authenticateDigestStats, 0, 1);
	    init++;
	}
	CBDATA_INIT_TYPE(authenticateStateData);
    }
}


/* free any allocated configuration details */
void
authDigestFreeConfig(authScheme * scheme)
{
    if (digestConfig == NULL)
	return;
    assert(digestConfig == scheme->scheme_data);
    if (digestConfig->authenticate)
	wordlistDestroy(&digestConfig->authenticate);
    if (digestConfig->digestAuthRealm)
	safe_free(digestConfig->digestAuthRealm);
    xfree(digestConfig);
    digestConfig = NULL;
}

static void
authDigestParse(authScheme * scheme, int n_configured, char *param_str)
{
    if (scheme->scheme_data == NULL) {
	assert(digestConfig == NULL);
	/* this is the first param to be found */
	scheme->scheme_data = xmalloc(sizeof(auth_digest_config));
	memset(scheme->scheme_data, 0, sizeof(auth_digest_config));
	digestConfig = scheme->scheme_data;
	digestConfig->authenticateChildren = 5;
	/* 5 minutes */
	digestConfig->nonceGCInterval = 5 * 60;
	/* 30 minutes */
	digestConfig->noncemaxduration = 30 * 60;
	/* 50 requests */
	digestConfig->noncemaxuses = 50;
    }
    digestConfig = scheme->scheme_data;
    if (strcasecmp(param_str, "program") == 0) {
	if (digestConfig->authenticate)
	    wordlistDestroy(&digestConfig->authenticate);
	parse_wordlist(&digestConfig->authenticate);
	requirePathnameExists("authparam digest program", digestConfig->authenticate->key);
    } else if (strcasecmp(param_str, "children") == 0) {
	parse_int(&digestConfig->authenticateChildren);
    } else if (strcasecmp(param_str, "realm") == 0) {
	parse_eol(&digestConfig->digestAuthRealm);
    } else if (strcasecmp(param_str, "nonce_garbage_interval") == 0) {
	parse_time_t(&digestConfig->nonceGCInterval);
    } else if (strcasecmp(param_str, "nonce_max_duration") == 0) {
	parse_time_t(&digestConfig->noncemaxduration);
    } else if (strcasecmp(param_str, "nonce_max_count") == 0) {
	parse_int(&digestConfig->noncemaxuses);
    } else {
	debug(28, 0) ("unrecognised digest auth scheme parameter '%s'\n", param_str);
    }
}


static void
authenticateDigestStats(StoreEntry * sentry)
{
    storeAppendPrintf(sentry, "Digest Authenticator Statistics:\n");
    helperStats(sentry, digestauthenticators);
}

/* NonceUserUnlink: remove the reference to auth_user and unlink the node from the list */

void
authDigestNonceUserUnlink(digest_nonce_h * nonce)
{
    digest_user_h *digest_user;
    dlink_node *link, *tmplink;
    if (!nonce)
	return;
    if (!nonce->auth_user)
	return;
    digest_user = nonce->auth_user->scheme_data;
    /* unlink from the user list. Yes we're crossing structures but this is the only 
     * time this code is needed
     */
    link = digest_user->nonces.head;
    while (link) {
	tmplink = link;
	link = link->next;
	if (tmplink->data == nonce) {
	    dlinkDelete(tmplink, &digest_user->nonces);
	    authDigestNonceUnlink(tmplink->data);
	    dlinkNodeDelete(tmplink);
	    link = NULL;
	}
    }
    /* this reference to auth_user was not locked because freeeing the auth_user frees
     * the nonce too. 
     */
    nonce->auth_user = NULL;
}

/* authDigestUserLinkNonce: add a nonce to a given user's struct */

void
authDigestUserLinkNonce(auth_user_t * auth_user, digest_nonce_h * nonce)
{
    dlink_node *node;
    digest_user_h *digest_user;
    if (!auth_user || !nonce)
	return;
    if (!auth_user->scheme_data)
	return;
    digest_user = auth_user->scheme_data;
    node = digest_user->nonces.head;
    while (node && (node->data != nonce))
	node = node->next;
    if (node)
	return;
    node = dlinkNodeNew();
    dlinkAddTail(nonce, node, &digest_user->nonces);
    authDigestNonceLink(nonce);
    /* ping this nonce to this auth user */
    assert((nonce->auth_user == NULL) || (nonce->auth_user = auth_user));
    /* we don't lock this reference because removing the auth_user removes the 
     * hash too. Of course if that changes we're stuffed so read the code huh?
     */
    nonce->auth_user = auth_user;
}

/* authenticateDigestUsername: return a pointer to the username in the */
char *
authenticateDigestUsername(auth_user_t * auth_user)
{
    digest_user_h *digest_user = auth_user->scheme_data;
    if (digest_user)
	return digest_user->username;
    return NULL;
}

/* setup the necessary info to log the username */
void
authDigestLogUsername(auth_user_request_t * auth_user_request, char *username)
{
    auth_user_t *auth_user;
    digest_user_h *digest_user;
    dlink_node *node;

    /* log the username */
    debug(29, 9) ("authBasicDecodeAuth: Creating new user for logging '%s'\n", username);
    /* new auth_user */
    auth_user = authenticateAuthUserNew("digest");
    /* new scheme data */
    digest_user = authDigestUserNew();
    /* save the credentials */
    digest_user->username = username;
    /* link the scheme data in */
    auth_user->scheme_data = digest_user;
    /* set the auth_user type */
    auth_user->auth_type = AUTH_BROKEN;
    /* link the request to the user */
    auth_user_request->auth_user = auth_user;
    /* lock for the auth_user_request link */
    authenticateAuthUserLock(auth_user);
    node = dlinkNodeNew();
    dlinkAdd(auth_user_request, node, &auth_user->requests);
}

/*
 * Decode a Digest [Proxy-]Auth string, placing the results in the passed
 * Auth_user structure.
 */

static void
authenticateDigestDecodeAuth(auth_user_request_t * auth_user_request, const char *proxy_auth)
{
    String temp;
    const char *item;
    const char *p;
    const char *pos = NULL;
    char *username = NULL;
    digest_nonce_h *nonce;
    int ilen;
    digest_request_h *digest_request;
    digest_user_h *digest_user;
    auth_user_t *auth_user;
    dlink_node *node;

    debug(29, 9) ("authenticateDigestDecodeAuth: beginning\n");
    assert(auth_user_request != NULL);

    digest_request = authDigestRequestNew();

    /* trim DIGEST from string */
    while (!xisspace(*proxy_auth))
	proxy_auth++;

    /* Trim leading whitespace before decoding */
    while (xisspace(*proxy_auth))
	proxy_auth++;

    stringInit(&temp, proxy_auth);
    while (strListGetItem(&temp, ',', &item, &ilen, &pos)) {
	if ((p = strchr(item, '=')) && (p - item < ilen))
	    ilen = p++ - item;
	if (!strncmp(item, "username", ilen)) {
	    /* white space */
	    while (xisspace(*p))
		p++;
	    /* quote mark */
	    p++;
	    username = xstrndup(p, strchr(p, '"') + 1 - p);
	    debug(29, 9) ("authDigestDecodeAuth: Found Username '%s'\n", username);
	} else if (!strncmp(item, "realm", ilen)) {
	    /* white space */
	    while (xisspace(*p))
		p++;
	    /* quote mark */
	    p++;
	    digest_request->realm = xstrndup(p, strchr(p, '"') + 1 - p);
	    debug(29, 9) ("authDigestDecodeAuth: Found realm '%s'\n", digest_request->realm);
	} else if (!strncmp(item, "qop", ilen)) {
	    /* white space */
	    while (xisspace(*p))
		p++;
	    /* quote mark */
	    p++;
	    digest_request->qop = xstrndup(p, strchr(p, '"') + 1 - p);
	    debug(29, 9) ("authDigestDecodeAuth: Found qop '%s'\n", digest_request->qop);
	} else if (!strncmp(item, "algorithm", ilen)) {
	    /* white space */
	    while (xisspace(*p))
		p++;
	    /* quote mark */
	    p++;
	    digest_request->algorithm = xstrndup(p, strchr(p, '"') + 1 - p);
	    debug(29, 9) ("authDigestDecodeAuth: Found algorithm '%s'\n", digest_request->algorithm);
	} else if (!strncmp(item, "uri", ilen)) {
	    /* white space */
	    while (xisspace(*p))
		p++;
	    /* quote mark */
	    p++;
	    digest_request->uri = xstrndup(p, strchr(p, '"') + 1 - p);
	    debug(29, 9) ("authDigestDecodeAuth: Found uri '%s'\n", digest_request->uri);
	} else if (!strncmp(item, "nonce", ilen)) {
	    /* white space */
	    while (xisspace(*p))
		p++;
	    /* quote mark */
	    p++;
	    digest_request->nonceb64 = xstrndup(p, strchr(p, '"') + 1 - p);
	    debug(29, 9) ("authDigestDecodeAuth: Found nonce '%s'\n", digest_request->nonceb64);
	} else if (!strncmp(item, "nc", ilen)) {
	    /* white space */
	    while (xisspace(*p))
		p++;
	    xstrncpy(digest_request->nc, p, 9);
	    debug(29, 9) ("authDigestDecodeAuth: Found noncecount '%s'\n", digest_request->nc);
	} else if (!strncmp(item, "cnonce", ilen)) {
	    /* white space */
	    while (xisspace(*p))
		p++;
	    /* quote mark */
	    p++;
	    digest_request->cnonce = xstrndup(p, strchr(p, '"') + 1 - p);
	    debug(29, 9) ("authDigestDecodeAuth: Found cnonce '%s'\n", digest_request->cnonce);
	} else if (!strncmp(item, "response", ilen)) {
	    /* white space */
	    while (xisspace(*p))
		p++;
	    /* quote mark */
	    p++;
	    digest_request->response = xstrndup(p, strchr(p, '"') + 1 - p);
	    debug(29, 9) ("authDigestDecodeAuth: Found response '%s'\n", digest_request->response);
	}
    }
    stringClean(&temp);


    /* now we validate the data given to us */

    /* TODO: on invalid parameters we should return 400, not 407. Find some clean way 
     * of doing this. perhaps return a valid struct, and set the direction to clientwards
     * combined with a change to the clientwards handling code (ie let the clientwards
     * call set the error type (but limited to known correct values - 400/401/407 */

    /* first the NONCE count */
    if (digest_request->cnonce && strlen(digest_request->nc) != 8) {
	debug(29, 4) ("authenticateDigestDecode: nonce count length invalid\n");
	authDigestLogUsername(auth_user_request, username);

	/* we don't need the scheme specific data anymore */
	authDigestRequestDelete(digest_request);
	auth_user_request->scheme_data = NULL;
	return;
    }
    /* now the nonce */
    nonce = authenticateDigestNonceFindNonce(digest_request->nonceb64);
    if ((nonce == NULL) || !(authDigestNonceIsValid(nonce, digest_request->nc))) {
	/* we couldn't find a matching nonce! */
	debug(29, 4) ("authenticateDigestDecode: Unexpected or invalid nonce recieved\n");
	authDigestLogUsername(auth_user_request, username);

	/* we don't need the scheme specific data anymore */
	authDigestRequestDelete(digest_request);
	auth_user_request->scheme_data = NULL;
	return;
    }
    digest_request->nonce = nonce;
    /* increment the nonce count */
    nonce->nc++;
    authDigestNonceLink(nonce);

    /* check the qop is what we expected */
    if (digest_request->qop && strcmp(digest_request->qop, QOP_AUTH)) {
	/* we recieved a qop option we didn't send */
	debug(29, 4) ("authenticateDigestDecode: Invalid qop option recieved\n");
	authDigestLogUsername(auth_user_request, username);

	/* we don't need the scheme specific data anymore */
	authDigestRequestDelete(digest_request);
	auth_user_request->scheme_data = NULL;
	return;
    }
    /* we can't check the URI just yet. We'll check it in the authenticate phase */

    /* is the response the correct length? */

    if (!digest_request->response || strlen(digest_request->response) != 32) {
	debug(29, 4) ("authenticateDigestDecode: Response length invalid\n");
	authDigestLogUsername(auth_user_request, username);

	/* we don't need the scheme specific data anymore */
	authDigestRequestDelete(digest_request);
	auth_user_request->scheme_data = NULL;
	return;
    }
    /* do we have a username ? */
    if (!username || username[0] == '\0') {
	debug(29, 4) ("authenticateDigestDecode: Empty or not present username\n");
	authDigestLogUsername(auth_user_request, username);

	/* we don't need the scheme specific data anymore */
	authDigestRequestDelete(digest_request);
	auth_user_request->scheme_data = NULL;
	return;
    }
    /* check that we're not being hacked / the username hasn't changed */
    if (nonce->auth_user && strcmp(username, authenticateUserUsername(nonce->auth_user))) {
	debug(29, 4) ("authenticateDigestDecode: Username for the nonce does not equal the username for the request\n");
	authDigestLogUsername(auth_user_request, username);

	/* we don't need the scheme specific data anymore */
	authDigestRequestDelete(digest_request);
	auth_user_request->scheme_data = NULL;
	return;
    }
    /* if we got a qop, did we get a cnonce or did we get a cnonce wihtout a qop? */
    if ((digest_request->qop && !digest_request->cnonce)
	|| (!digest_request->qop && digest_request->cnonce)) {
	debug(29, 4) ("authenticateDigestDecode: qop without cnonce, or vice versa!\n");
	authDigestLogUsername(auth_user_request, username);

	/* we don't need the scheme specific data anymore */
	authDigestRequestDelete(digest_request);
	auth_user_request->scheme_data = NULL;
	return;
    }
    /* check the algorithm is present and supported */
    if (digest_request->algorithm
	&& strcmp(digest_request->algorithm, "MD5")
	&& strcmp(digest_request->algorithm, "MD5-sess")) {
	debug(29, 4) ("authenticateDigestDecode: invalid algorithm specified!\n");
	authDigestLogUsername(auth_user_request, username);

	/* we don't need the scheme specific data anymore */
	authDigestRequestDelete(digest_request);
	auth_user_request->scheme_data = NULL;
	return;
    }
    /* the method we'll check at the authenticate step as well */


    /* we don't send or parse opaques. Ok so we're flexable ... */

    /* find the user */

    if ((auth_user = authDigestUserFindUsername(username)) == NULL) {
	/* the user doesn't exist in the username cache yet */
	debug(29, 9) ("authDigestDecodeAuth: Creating new digest user '%s'\n", username);
	/* new auth_user */
	auth_user = authenticateAuthUserNew("digest");
	/* new scheme user data */
	digest_user = authDigestUserNew();
	/* save the username */
	digest_user->username = username;
	/* link the primary struct in */
	auth_user->scheme_data = digest_user;
	/* set the user type */
	auth_user->auth_type = AUTH_DIGEST;
	/* this auth_user struct is the one to get added to the username cache */
	/* store user in hash's */
	authenticateUserNameCacheAdd(auth_user);
	/* 
	 * Add the digest to the user so we can tell if a hacking or spoofing attack
	 * is taking place. We do this by assuming the user agent won't change user
	 * name without warning.
	 */
	authDigestUserLinkNonce(auth_user, nonce);
    } else {
	debug(29, 9) ("authDigestDecodeAuth: Found user '%s' in the user cache as '%d'\n", username, auth_user);
	digest_user = auth_user->scheme_data;
	xfree(username);
    }
    /*link the request and the user */
    auth_user_request->auth_user = auth_user;
    auth_user_request->scheme_data = digest_request;
    /* lock for the request link */
    authenticateAuthUserLock(auth_user);
    node = dlinkNodeNew();
    dlinkAdd(auth_user_request, node, &auth_user->requests);

    debug(29, 9) ("username = '%s'\nrealm = '%s'\nqop = '%s'\nalgorithm = '%s'\nuri = '%s'\nnonce = '%s'\nnc = '%s'\ncnonce = '%s'\nresponse = '%s'\ndigestnonce = '%d'\n",
	digest_user->username, digest_request->realm,
	digest_request->qop, digest_request->algorithm,
	digest_request->uri, digest_request->nonceb64,
	digest_request->nc, digest_request->cnonce, digest_request->response, nonce);

    return;
}

/* send the initial data to a digest authenticator module */
static void
authenticateDigestStart(auth_user_request_t * auth_user_request, RH * handler, void *data)
{
    authenticateStateData *r = NULL;
    char buf[8192];
    digest_request_h *digest_request;
    digest_user_h *digest_user;
    assert(auth_user_request);
    assert(handler);
    assert(auth_user_request->auth_user->auth_type == AUTH_DIGEST);
    assert(auth_user_request->auth_user->scheme_data != NULL);
    assert(auth_user_request->scheme_data != NULL);
    digest_request = auth_user_request->scheme_data;
    digest_user = auth_user_request->auth_user->scheme_data;
    debug(29, 9) ("authenticateStart: '\"%s\":\"%s\"'\n", digest_user->username,
	digest_request->realm);
    if (digestConfig->authenticate == NULL) {
	handler(data, NULL);
	return;
    }
    r = CBDATA_ALLOC(authenticateStateData, NULL);
    r->handler = handler;
    cbdataLock(data);
    r->data = data;
    r->auth_user_request = auth_user_request;
    snprintf(buf, 8192, "\"%s\":\"%s\"\n", digest_user->username, digest_request->realm);
    helperSubmit(digestauthenticators, buf, authenticateDigestHandleReply, r);
}
