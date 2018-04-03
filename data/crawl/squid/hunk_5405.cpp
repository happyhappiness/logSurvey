+/*
+ * $Id: ACLChecklist.cc,v 1.1 2003/02/13 08:07:46 robertc Exp $
+ *
+ * DEBUG: section 28    Access Control
+ * AUTHOR: Duane Wessels
+ *
+ * SQUID Web Proxy Cache          http://www.squid-cache.org/
+ * ----------------------------------------------------------
+ *
+ *  Squid is the result of efforts by numerous individuals from
+ *  the Internet community; see the CONTRIBUTORS file for full
+ *  details.   Many organizations have provided support for Squid's
+ *  development; see the SPONSORS file for full details.  Squid is
+ *  Copyrighted (C) 2001 by the Regents of the University of
+ *  California; see the COPYRIGHT file for full details.  Squid
+ *  incorporates software developed and/or copyrighted by other
+ *  sources; see the CREDITS file for full details.
+ *
+ *  This program is free software; you can redistribute it and/or modify
+ *  it under the terms of the GNU General Public License as published by
+ *  the Free Software Foundation; either version 2 of the License, or
+ *  (at your option) any later version.
+ *  
+ *  This program is distributed in the hope that it will be useful,
+ *  but WITHOUT ANY WARRANTY; without even the implied warranty of
+ *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ *  GNU General Public License for more details.
+ *  
+ *  You should have received a copy of the GNU General Public License
+ *  along with this program; if not, write to the Free Software
+ *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
+ *
+ * Copyright (c) 2003, Robert Collins <robertc@squid-cache.org>
+ */
+
+#include "squid.h"
+#include "ACLChecklist.h"
+/* TODO: trim this ! */
+#include "splay.h"
+#include "HttpRequest.h"
+#include "authenticate.h"
+#include "fde.h"
+#include "ACLProxyAuth.h"
+#if USE_IDENT
+#include "ACLIdent.h"
+#endif
+#include "ACLUserData.h"
+
+int
+ACLChecklist::authenticated()
+{
+    http_hdr_type headertype;
+    if (NULL == request) {
+	fatal ("requiresRequest SHOULD have been true for this ACL!!");
+    } else if (!request->flags.accelerated) {
+	/* Proxy authorization on proxy requests */
+	headertype = HDR_PROXY_AUTHORIZATION;
+    } else if (request->flags.internal) {
+	/* WWW authorization on accelerated internal requests */
+	headertype = HDR_AUTHORIZATION;
+    } else {
+#if AUTH_ON_ACCELERATION
+	/* WWW authorization on accelerated requests */
+	headertype = HDR_AUTHORIZATION;
+#else
+	debug(28, 1) ("ACHChecklist::authenticated: authentication not applicable on accelerated requests.\n");
+	return -1;
+#endif
+    }
+    /* get authed here */
+    /* Note: this fills in auth_user_request when applicable */
+    switch (authenticateTryToAuthenticateAndSetAuthUser(&auth_user_request, headertype, request, conn(), src_addr)) {
+    case AUTH_ACL_CANNOT_AUTHENTICATE:
+	debug(28, 4) ("aclMatchAcl: returning  0 user authenticated but not authorised.\n");
+	return 0;
+    case AUTH_AUTHENTICATED:
+	return 1;
+	break;
+    case AUTH_ACL_HELPER:
+	debug(28, 4) ("aclMatchAcl: returning 0 sending credentials to helper.\n");
+	changeState (ProxyAuthLookup::Instance());
+	return 0;
+    case AUTH_ACL_CHALLENGE:
+	debug(28, 4) ("aclMatchAcl: returning 0 sending authentication challenge.\n");
+	changeState (ProxyAuthNeeded::Instance());
+	return 0;
+    default:
+	fatal("unexpected authenticateAuthenticate reply\n");
+	return 0;
+    }
+}
+
+allow_t const &
+ACLChecklist::currentAnswer() const
+{
+    return allow_;
+}
+
+void
+ACLChecklist::currentAnswer(allow_t const newAnswer)
+{
+    allow_ = newAnswer;
+}
+    
+void
+ACLChecklist::check()
+{
+    /* deny if no rules present */
+    currentAnswer(ACCESS_DENIED);
+    /* NOTE: This holds a cbdata reference to the current access_list
+     * entry, not the whole list.
+     */
+    while (accessList != NULL) {
+	/*
+	 * If the _acl_access is no longer valid (i.e. its been
+	 * freed because of a reconfigure), then bail on this
+	 * access check.  For now, return ACCESS_DENIED.
+	 */
+	if (!cbdataReferenceValid(accessList)) {
+	    cbdataReferenceDone(accessList);
+	    break;
+	}
+
+	checkAccessList();
+	if (asyncInProgress())
+	    return;
+
+	if (finished()) {
+	    /*
+	     * We are done.  Either the request
+	     * is allowed, denied, requires authentication.
+	     */
+	    debug(28, 3) ("ACLChecklist::check: match found, returning %d\n", currentAnswer());
+	    cbdataReferenceDone(accessList); /* A */
+	    checkCallback(currentAnswer());
+	    /* From here on in, this may be invalid */
+	    return;
+	}
+	/*
+	 * Reference the next access entry
+	 */
+	const acl_access *A = accessList;
+	accessList = cbdataReference(accessList->next);
+	cbdataReferenceDone(A);
+    }
+    /* dropped off the end of the list */
+    debug(28, 3) ("ACLChecklist::check: NO match found, returning %d\n", 
+		  currentAnswer() != ACCESS_DENIED ? ACCESS_DENIED : ACCESS_ALLOWED);
+    checkCallback(currentAnswer() != ACCESS_DENIED ? ACCESS_DENIED : ACCESS_ALLOWED);
+}
+
+bool
+ACLChecklist::asyncInProgress() const
+{
+    return async_;
+}
+
+void
+ACLChecklist::asyncInProgress(bool const newAsync)
+{
+    assert (!finished());
+    async_ = newAsync;
+    debug (28,3)("ACLChecklist::asyncInProgress: async set to %d\n",async_);
+}
+
+bool
+ACLChecklist::finished() const
+{
+    return finished_;
+}
+
+void
+ACLChecklist::markFinished()
+{
+    assert (!finished());
+    finished_ = true;
+    debug (28,3)("checklist processing finished\n");
+}
+
+void
+ACLChecklist::checkAccessList()
+{
+    debug(28, 3) ("ACLChecklist::checkAccessList: checking '%s'\n", accessList->cfgline);
+    /* what is our result on a match? */
+    currentAnswer(accessList->allow);
+    /* does the current AND clause match */
+    bool match = matchAclList(accessList->aclList);
+    if (match)
+	markFinished();
+    /* Should be else, but keep the exact same flow as before */
+    checkForAsync();
+}
+
+void
+ACLChecklist::checkForAsync()
+{
+    /* check for async lookups needed. */
+    if (asyncState() != NullState::Instance()) {
+	/* If a state object is here, use it.
+	 * When all cases are converted, the if goes away and it
+	 * becomes unconditional.
+	 * RBC 02 2003
+	 */
+	asyncState()->checkForAsync(this);
+    } else if (state[ACL_DST_ASN] == ACL_LOOKUP_NEEDED) {
+	state[ACL_DST_ASN] = ACL_LOOKUP_PENDING;
+	ipcache_nbgethostbyname(request->host,
+				aclLookupDstIPforASNDone, this);
+    asyncInProgress(true);
+    } else if (state[ACL_SRC_DOMAIN] == ACL_LOOKUP_NEEDED) {
+	state[ACL_SRC_DOMAIN] = ACL_LOOKUP_PENDING;
+	fqdncache_nbgethostbyaddr(src_addr,
+				  aclLookupSrcFQDNDone, this);
+    asyncInProgress(true);
+    } else if (state[ACL_DST_DOMAIN] == ACL_LOOKUP_NEEDED) {
+	ipcache_addrs *ia;
+	ia = ipcacheCheckNumeric(request->host);
+	if (ia == NULL) {
+	    state[ACL_DST_DOMAIN] = ACL_LOOKUP_DONE;
+	} else {
+	    dst_addr = ia->in_addrs[0];
+	    state[ACL_DST_DOMAIN] = ACL_LOOKUP_PENDING;
+	    fqdncache_nbgethostbyaddr(dst_addr,
+				      aclLookupDstFQDNDone, this);
+	}
+    asyncInProgress(true);
+#if USE_IDENT
+    } else if (state[ACL_IDENT] == ACL_LOOKUP_NEEDED) {
+	debug(28, 3) ("ACLChecklist::checkForAsync: Doing ident lookup\n");
+	if (conn() && cbdataReferenceValid(conn())) {
+	    identStart(&conn()->me, &conn()->peer,
+		       aclLookupIdentDone, this);
+	    state[ACL_IDENT] = ACL_LOOKUP_PENDING;
+	} else {
+	    debug(28, 1) ("ACLChecklist::checkForAsync: Can't start ident lookup. No client connection\n");
+	    currentAnswer(ACCESS_DENIED);
+	    markFinished();
+	    return;
+	}
+    asyncInProgress(true);
+#endif
+    }
+}
+
+void
+ACLChecklist::checkCallback(allow_t answer)
+{
+    PF *callback_;
+    void *cbdata_;
+    debug(28, 3) ("ACLChecklist::checkCallback: answer=%d\n", answer);
+    /* During reconfigure, we can end up not finishing call
+     * sequences into the auth code */
+    if (auth_user_request) {
+	/* the checklist lock */
+	authenticateAuthUserRequestUnlock(auth_user_request);
+	/* it might have been connection based */
+	assert(conn());
+	conn()->auth_user_request = NULL;
+	conn()->auth_type = AUTH_BROKEN;
+	auth_user_request = NULL;
+    }
+    callback_ = callback;
+    callback = NULL;
+    if (cbdataReferenceValidDone(callback_data, &cbdata_))
+	callback_(answer, cbdata_);
+    delete this;
+}
+bool
+ACLChecklist::matchAclList(const acl_list * head)
+{
+    PROF_start(aclMatchAclList);
+    const acl_list *node = head;
+    while (node) {
+	if (!node->matches(this)) {
+	    debug(28, 3) ("aclmatchAclList: returning false (AND list entry failed to match)\n");
+	    PROF_stop(aclMatchAclList);
+	    return false;
+	}
+	node = node->next;
+    }
+    debug(28, 3) ("aclmatchAclList: returning true (AND list satisfied)\n");
+    PROF_stop(aclMatchAclList);
+    return true;
+}
+
+CBDATA_CLASS_INIT(ACLChecklist);
+
+void *
+ACLChecklist::operator new (size_t size)
+{
+    assert (size == sizeof(ACLChecklist));
+    CBDATA_INIT_TYPE(ACLChecklist);
+    ACLChecklist *result = cbdataAlloc(ACLChecklist);
+    /* Mark result as being owned - we want the refcounter to do the delete
+     * call */
+    cbdataReference(result);
+    return result;
+}
+ 
+void
+ACLChecklist::operator delete (void *address)
+{
+    ACLChecklist *t = static_cast<ACLChecklist *>(address);
+    cbdataFree(address);
+    /* And allow the memory to be freed */
+    cbdataReferenceDone (t);
+}
+
+void
+ACLChecklist::deleteSelf() const
+{
+    delete this;
+}
+
+ACLChecklist::ACLChecklist() : accessList (NULL), my_port (0), request (NULL),
+  reply (NULL),
+  auth_user_request (NULL)
+#if SQUID_SNMP
+    ,snmp_community(NULL)
+#endif
+  , callback (NULL),
+  callback_data (NULL),
+  extacl_entry (NULL),
+  conn_(NULL),
+  async_(false),
+  finished_(false),
+  allow_(ACCESS_DENIED),
+  state_(NullState::Instance())
+{
+    memset (&src_addr, '\0', sizeof (struct in_addr));
+    memset (&dst_addr, '\0', sizeof (struct in_addr));
+    memset (&my_addr, '\0', sizeof (struct in_addr));
+    rfc931[0] = '\0';
+    memset (&state, '\0', sizeof (state));
+}
+
+ACLChecklist::~ACLChecklist()
+{
+    assert (!asyncInProgress());
+    if (extacl_entry)
+	cbdataReferenceDone(extacl_entry);
+    if (request)
+	requestUnlink(request);
+    request = NULL;
+    cbdataReferenceDone(conn_);
+    cbdataReferenceDone(accessList);
+}
+
+
+ConnStateData *
+ACLChecklist::conn()
+{
+    return  conn_;
+}
+
+void
+ACLChecklist::conn(ConnStateData *aConn)
+{
+    assert (conn() == NULL);
+    conn_ = aConn;
+}
+
+void
+ACLChecklist::AsyncState::changeState (ACLChecklist *checklist, AsyncState *newState) const
+{
+    checklist->changeState(newState);
+}
+
+ACLChecklist::NullState *
+ACLChecklist::NullState::Instance()
+{
+    return &_instance;
+}
+
+void
+ACLChecklist::NullState::checkForAsync(ACLChecklist *) const
+{
+}
+
+ACLChecklist::NullState ACLChecklist::NullState::_instance;
+
+void
+ACLChecklist::changeState (AsyncState *newState)
+{
+    /* only change from null to active and back again,
+     * not active to active.
+     * relax this once conversion to states is complete
+     * RBC 02 2003
+     */
+    assert (state_ == NullState::Instance() || newState == NullState::Instance());
+    state_ = newState;
+}
+
+ACLChecklist::AsyncState *
+ACLChecklist::asyncState() const
+{
+    return state_;
+}
+
+void
+ACLChecklist::nonBlockingCheck(PF * callback_, void *callback_data_)
+{
+    callback = callback_;
+    callback_data = cbdataReference(callback_data_);
+    check();
+}
+
