+/*
+ * DEBUG: section 17    Request Forwarding
+ *
+ */
+
+#include "squid.h"
+#include "acl/FilledChecklist.h"
+#include "base/AsyncCbdataCalls.h"
+#include "CachePeer.h"
+#include "client_side.h"
+#include "comm/Loops.h"
+#include "errorpage.h"
+#include "fde.h"
+#include "globals.h"
+#include "HttpRequest.h"
+#include "neighbors.h"
+#include "ssl/cert_validate_message.h"
+#include "ssl/Config.h"
+#include "ssl/ErrorDetail.h"
+#include "ssl/helper.h"
+#include "ssl/PeerConnector.h"
+#include "ssl/ServerBump.h"
+#include "ssl/support.h"
+#include "SquidConfig.h"
+
+CBDATA_NAMESPACED_CLASS_INIT(Ssl, PeerConnector);
+
+Ssl::PeerConnector::PeerConnector(
+    HttpRequestPointer &aRequest,
+    const Comm::ConnectionPointer &aServerConn,
+    AsyncCall::Pointer &aCallback):
+    AsyncJob("Ssl::PeerConnector"),
+    request(aRequest),
+    serverConn(aServerConn),
+    callback(aCallback)
+{
+    // if this throws, the caller's cb dialer is not our CbDialer
+    Must(dynamic_cast<CbDialer*>(callback->getDialer()));
+}
+
+Ssl::PeerConnector::~PeerConnector()
+{
+    debugs(83, 5, "Peer connector " << this << " gone");
+}
+
+bool Ssl::PeerConnector::doneAll() const
+{
+    return (!callback || callback->canceled()) && AsyncJob::doneAll();
+}
+
+/// Preps connection and SSL state. Calls negotiate().
+void
+Ssl::PeerConnector::start()
+{
+    AsyncJob::start();
+
+    if (prepareSocket()) {
+        initializeSsl();
+        negotiateSsl();
+    }
+}
+
+void
+Ssl::PeerConnector::commCloseHandler(const CommCloseCbParams &params)
+{
+    debugs(83, 5, "FD " << params.fd << ", Ssl::PeerConnector=" << params.data);
+    connectionClosed("Ssl::PeerConnector::commCloseHandler");
+}
+
+void
+Ssl::PeerConnector::connectionClosed(const char *reason)
+{
+    mustStop(reason);
+    callback = NULL;
+}
+
+bool
+Ssl::PeerConnector::prepareSocket()
+{
+    const int fd = serverConnection()->fd;
+    if (!Comm::IsConnOpen(serverConn) || fd_table[serverConn->fd].closing()) {
+        connectionClosed("Ssl::PeerConnector::prepareSocket");
+        return false;
+    }
+
+    // watch for external connection closures
+    typedef CommCbMemFunT<Ssl::PeerConnector, CommCloseCbParams> Dialer;
+    closeHandler = JobCallback(9, 5, Dialer, this, Ssl::PeerConnector::commCloseHandler);
+    comm_add_close_handler(fd, closeHandler);
+    return true;
+}
+
+void
+Ssl::PeerConnector::initializeSsl()
+{
+    SSL *ssl;
+    SSL_CTX *sslContext = NULL;
+    const CachePeer *peer = serverConnection()->getPeer();
+    const int fd = serverConnection()->fd;
+
+    if (peer) {
+        assert(peer->use_ssl);
+        sslContext = peer->sslContext;
+    } else {
+        sslContext = ::Config.ssl_client.sslContext;
+    }
+
+    assert(sslContext);
+
+    if ((ssl = SSL_new(sslContext)) == NULL) {
+        ErrorState *anErr = new ErrorState(ERR_SOCKET_FAILURE, Http::scInternalServerError, request.getRaw());
+        anErr->xerrno = errno;
+        debugs(83, DBG_IMPORTANT, "Error allocating SSL handle: " << ERR_error_string(ERR_get_error(), NULL));
+        bail(anErr);
+        return;
+    }
+
+    SSL_set_fd(ssl, fd);
+
+    if (peer) {
+        if (peer->ssldomain)
+            SSL_set_ex_data(ssl, ssl_ex_index_server, peer->ssldomain);
+
+#if NOT_YET
+
+        else if (peer->name)
+            SSL_set_ex_data(ssl, ssl_ex_index_server, peer->name);
+
+#endif
+
+        else
+            SSL_set_ex_data(ssl, ssl_ex_index_server, peer->host);
+
+        if (peer->sslSession)
+            SSL_set_session(ssl, peer->sslSession);
+
+    } else {
+        // While we are peeking at the certificate, we may not know the server
+        // name that the client will request (after interception or CONNECT)
+        // unless it was the CONNECT request with a user-typed address.
+        const char *hostname = request->GetHost();
+        const bool hostnameIsIp = request->GetHostIsNumeric();
+        const bool isConnectRequest = request->clientConnectionManager.valid() &&
+                                      !request->clientConnectionManager->port->flags.isIntercepted();
+        if (!request->flags.sslPeek || isConnectRequest)
+            SSL_set_ex_data(ssl, ssl_ex_index_server, (void*)hostname);
+
+        // Use SNI TLS extension only when we connect directly
+        // to the origin server and we know the server host name.
+        if (!hostnameIsIp)
+            Ssl::setClientSNI(ssl, hostname);
+    }
+
+    // If CertValidation Helper used do not lookup checklist for errors,
+    // but keep a list of errors to send it to CertValidator
+    if (!Ssl::TheConfig.ssl_crt_validator) {
+        // Create the ACL check list now, while we have access to more info.
+        // The list is used in ssl_verify_cb() and is freed in ssl_free().
+        if (acl_access *acl = ::Config.ssl_client.cert_error) {
+            ACLFilledChecklist *check = new ACLFilledChecklist(acl, request.getRaw(), dash_str);
+            // check->fd(fd); XXX: need client FD here
+            SSL_set_ex_data(ssl, ssl_ex_index_cert_error_check, check);
+        }
+    }
+
+    // store peeked cert to check SQUID_X509_V_ERR_CERT_CHANGE
+    X509 *peeked_cert;
+    if (request->clientConnectionManager.valid() &&
+            request->clientConnectionManager->serverBump() &&
+            (peeked_cert = request->clientConnectionManager->serverBump()->serverCert.get())) {
+        CRYPTO_add(&(peeked_cert->references),1,CRYPTO_LOCK_X509);
+        SSL_set_ex_data(ssl, ssl_ex_index_ssl_peeked_cert, peeked_cert);
+    }
+
+    fd_table[fd].ssl = ssl;
+    fd_table[fd].read_method = &ssl_read_method;
+    fd_table[fd].write_method = &ssl_write_method;
+}
+
+void
+Ssl::PeerConnector::negotiateSsl()
+{
+    if (!Comm::IsConnOpen(serverConnection()) || fd_table[serverConnection()->fd].closing())
+        return;
+
+    const int fd = serverConnection()->fd;
+    SSL *ssl = fd_table[fd].ssl;
+    const int result = SSL_connect(ssl);
+    if (result <= 0) {
+        handleNegotiateError(result);
+        return; // we might be gone by now
+    }
+
+    if (request->clientConnectionManager.valid()) {
+        // remember the server certificate from the ErrorDetail object
+        if (Ssl::ServerBump *serverBump = request->clientConnectionManager->serverBump()) {
+            serverBump->serverCert.reset(SSL_get_peer_certificate(ssl));
+
+            // remember validation errors, if any
+            if (Ssl::CertErrors *errs = static_cast<Ssl::CertErrors *>(SSL_get_ex_data(ssl, ssl_ex_index_ssl_errors)))
+                serverBump->sslErrors = cbdataReference(errs);
+        }
+    }
+
+    if (serverConnection()->getPeer() && !SSL_session_reused(ssl)) {
+        if (serverConnection()->getPeer()->sslSession)
+            SSL_SESSION_free(serverConnection()->getPeer()->sslSession);
+
+        serverConnection()->getPeer()->sslSession = SSL_get1_session(ssl);
+    }
+
+    if (Ssl::TheConfig.ssl_crt_validator) {
+        Ssl::CertValidationRequest validationRequest;
+        // WARNING: Currently we do not use any locking for any of the
+        // members of the Ssl::CertValidationRequest class. In this code the
+        // Ssl::CertValidationRequest object used only to pass data to
+        // Ssl::CertValidationHelper::submit method.
+        validationRequest.ssl = ssl;
+        validationRequest.domainName = request->GetHost();
+        if (Ssl::CertErrors *errs = static_cast<Ssl::CertErrors *>(SSL_get_ex_data(ssl, ssl_ex_index_ssl_errors)))
+            // validationRequest disappears on return so no need to cbdataReference
+            validationRequest.errors = errs;
+        else
+            validationRequest.errors = NULL;
+        try {
+            debugs(83, 5, "Sending SSL certificate for validation to ssl_crtvd.");
+            Ssl::CertValidationHelper::GetInstance()->sslSubmit(validationRequest, sslCrtvdHandleReplyWrapper, this);
+            return;
+        } catch (const std::exception &e) {
+            debugs(83, DBG_IMPORTANT, "ERROR: Failed to compose ssl_crtvd " <<
+                   "request for " << validationRequest.domainName <<
+                   " certificate: " << e.what() << "; will now block to " <<
+                   "validate that certificate.");
+            // fall through to do blocking in-process generation.
+            ErrorState *anErr = new ErrorState(ERR_GATEWAY_FAILURE, Http::scInternalServerError, request.getRaw());
+            bail(anErr);
+            if (serverConnection()->getPeer()) {
+                peerConnectFailed(serverConnection()->getPeer());
+            }
+            serverConn->close();
+            return;
+        }
+    }
+
+    callBack();
+}
+
+void
+Ssl::PeerConnector::sslCrtvdHandleReplyWrapper(void *data, Ssl::CertValidationResponse const &validationResponse)
+{
+    Ssl::PeerConnector *connector = (Ssl::PeerConnector *)(data);
+    connector->sslCrtvdHandleReply(validationResponse);
+}
+
+void
+Ssl::PeerConnector::sslCrtvdHandleReply(Ssl::CertValidationResponse const &validationResponse)
+{
+    Ssl::CertErrors *errs = NULL;
+    Ssl::ErrorDetail *errDetails = NULL;
+    bool validatorFailed = false;
+    if (!Comm::IsConnOpen(serverConnection())) {
+        return;
+    }
+
+    debugs(83,5, request->GetHost() << " cert validation result: " << validationResponse.resultCode);
+
+    if (validationResponse.resultCode == HelperReply::Error)
+        errs = sslCrtvdCheckForErrors(validationResponse, errDetails);
+    else if (validationResponse.resultCode != HelperReply::Okay)
+        validatorFailed = true;
+
+    if (!errDetails && !validatorFailed) {
+        callBack();
+        return;
+    }
+
+    ErrorState *anErr = NULL;
+    if (validatorFailed) {
+        anErr = new ErrorState(ERR_GATEWAY_FAILURE, Http::scInternalServerError, request.getRaw());
+    }  else {
+
+        // Check the list error with
+        if (errDetails && request->clientConnectionManager.valid()) {
+            // remember the server certificate from the ErrorDetail object
+            if (Ssl::ServerBump *serverBump = request->clientConnectionManager->serverBump()) {
+                // remember validation errors, if any
+                if (errs) {
+                    if (serverBump->sslErrors)
+                        cbdataReferenceDone(serverBump->sslErrors);
+                    serverBump->sslErrors = cbdataReference(errs);
+                }
+            }
+        }
+
+        anErr =  new ErrorState(ERR_SECURE_CONNECT_FAIL, Http::scServiceUnavailable, request.getRaw());
+        anErr->detail = errDetails;
+        /*anErr->xerrno= Should preserved*/
+    }
+
+    bail(anErr);
+    if (serverConnection()->getPeer()) {
+        peerConnectFailed(serverConnection()->getPeer());
+    }
+    serverConn->close();
+    return;
+}
+
+/// Checks errors in the cert. validator response against sslproxy_cert_error.
+/// The first honored error, if any, is returned via errDetails parameter.
+/// The method returns all seen errors except SSL_ERROR_NONE as Ssl::CertErrors.
+Ssl::CertErrors *
+Ssl::PeerConnector::sslCrtvdCheckForErrors(Ssl::CertValidationResponse const &resp, Ssl::ErrorDetail *& errDetails)
+{
+    Ssl::CertErrors *errs = NULL;
+
+    ACLFilledChecklist *check = NULL;
+    if (acl_access *acl = ::Config.ssl_client.cert_error)
+        check = new ACLFilledChecklist(acl, request.getRaw(), dash_str);
+
+    SSL *ssl = fd_table[serverConnection()->fd].ssl;
+    typedef Ssl::CertValidationResponse::RecvdErrors::const_iterator SVCRECI;
+    for (SVCRECI i = resp.errors.begin(); i != resp.errors.end(); ++i) {
+        debugs(83, 7, "Error item: " << i->error_no << " " << i->error_reason);
+
+        assert(i->error_no != SSL_ERROR_NONE);
+
+        if (!errDetails) {
+            bool allowed = false;
+            if (check) {
+                check->sslErrors = new Ssl::CertErrors(Ssl::CertError(i->error_no, i->cert.get()));
+                if (check->fastCheck() == ACCESS_ALLOWED)
+                    allowed = true;
+            }
+            // else the Config.ssl_client.cert_error access list is not defined
+            // and the first error will cause the error page
+
+            if (allowed) {
+                debugs(83, 3, "bypassing SSL error " << i->error_no << " in " << "buffer");
+            } else {
+                debugs(83, 5, "confirming SSL error " << i->error_no);
+                X509 *brokenCert = i->cert.get();
+                Ssl::X509_Pointer peerCert(SSL_get_peer_certificate(ssl));
+                const char *aReason = i->error_reason.empty() ? NULL : i->error_reason.c_str();
+                errDetails = new Ssl::ErrorDetail(i->error_no, peerCert.get(), brokenCert, aReason);
+            }
+            if (check) {
+                delete check->sslErrors;
+                check->sslErrors = NULL;
+            }
+        }
+
+        if (!errs)
+            errs = new Ssl::CertErrors(Ssl::CertError(i->error_no, i->cert.get()));
+        else
+            errs->push_back_unique(Ssl::CertError(i->error_no, i->cert.get()));
+    }
+    if (check)
+        delete check;
+
+    return errs;
+}
+
+/// A wrapper for Comm::SetSelect() notifications.
+void
+Ssl::PeerConnector::NegotiateSsl(int, void *data)
+{
+    PeerConnector *pc = static_cast<PeerConnector*>(data);
+    // Use job calls to add done() checks and other job logic/protections.
+    CallJobHere(83, 7, pc, Ssl::PeerConnector, negotiateSsl);
+}
+
+void
+Ssl::PeerConnector::handleNegotiateError(const int ret)
+{
+    const int fd = serverConnection()->fd;
+    unsigned long ssl_lib_error = SSL_ERROR_NONE;
+    SSL *ssl = fd_table[fd].ssl;
+    int ssl_error = SSL_get_error(ssl, ret);
+
+#ifdef EPROTO
+        int sysErrNo = EPROTO;
+#else
+        int sysErrNo = EACCES;
+#endif
+
+        switch (ssl_error) {
+
+        case SSL_ERROR_WANT_READ:
+            Comm::SetSelect(fd, COMM_SELECT_READ, &NegotiateSsl, this, 0);
+            return;
+
+        case SSL_ERROR_WANT_WRITE:
+            Comm::SetSelect(fd, COMM_SELECT_WRITE, &NegotiateSsl, this, 0);
+            return;
+
+        case SSL_ERROR_SSL:
+        case SSL_ERROR_SYSCALL:
+            ssl_lib_error = ERR_get_error();
+
+            // store/report errno when ssl_error is SSL_ERROR_SYSCALL, ssl_lib_error is 0, and ret is -1
+            if (ssl_error == SSL_ERROR_SYSCALL && ret == -1 && ssl_lib_error == 0)
+                sysErrNo = errno;
+
+            debugs(83, DBG_IMPORTANT, "Error negotiating SSL on FD " << fd <<
+                   ": " << ERR_error_string(ssl_lib_error, NULL) << " (" <<
+                   ssl_error << "/" << ret << "/" << errno << ")");
+
+            break; // proceed to the general error handling code
+
+        default:
+            break; // no special error handling for all other errors
+        }
+
+    ErrorState *const anErr = ErrorState::NewForwarding(ERR_SECURE_CONNECT_FAIL, request.getRaw());
+    anErr->xerrno = sysErrNo;
+
+    Ssl::ErrorDetail *errFromFailure = (Ssl::ErrorDetail *)SSL_get_ex_data(ssl, ssl_ex_index_ssl_error_detail);
+    if (errFromFailure != NULL) {
+        // The errFromFailure is attached to the ssl object
+        // and will be released when ssl object destroyed.
+        // Copy errFromFailure to a new Ssl::ErrorDetail object
+        anErr->detail = new Ssl::ErrorDetail(*errFromFailure);
+    } else {
+        // server_cert can be NULL here
+        X509 *server_cert = SSL_get_peer_certificate(ssl);
+        anErr->detail = new Ssl::ErrorDetail(SQUID_ERR_SSL_HANDSHAKE, server_cert, NULL);
+        X509_free(server_cert);
+    }
+
+    if (ssl_lib_error != SSL_ERROR_NONE)
+        anErr->detail->setLibError(ssl_lib_error);
+
+    if (request->clientConnectionManager.valid()) {
+        // remember the server certificate from the ErrorDetail object
+        if (Ssl::ServerBump *serverBump = request->clientConnectionManager->serverBump()) {
+            serverBump->serverCert.resetAndLock(anErr->detail->peerCert());
+
+            // remember validation errors, if any
+            if (Ssl::CertErrors *errs = static_cast<Ssl::CertErrors*>(SSL_get_ex_data(ssl, ssl_ex_index_ssl_errors)))
+                serverBump->sslErrors = cbdataReference(errs);
+        }
+
+        // For intercepted connections, set the host name to the server
+        // certificate CN. Otherwise, we just hope that CONNECT is using
+        // a user-entered address (a host name or a user-entered IP).
+        const bool isConnectRequest = !request->clientConnectionManager->port->flags.isIntercepted();
+        if (request->flags.sslPeek && !isConnectRequest) {
+            if (X509 *srvX509 = anErr->detail->peerCert()) {
+                if (const char *name = Ssl::CommonHostName(srvX509)) {
+                    request->SetHost(name);
+                    debugs(83, 3, HERE << "reset request host: " << name);
+                }
+            }
+        }
+    }
+
+    bail(anErr);
+}
+
+void
+Ssl::PeerConnector::bail(ErrorState *error)
+{
+    Must(error); // or the recepient will not know there was a problem
+
+    // XXX: forward.cc calls peerConnectSucceeded() after an OK TCP connect but
+    // we call peerConnectFailed() if SSL failed afterwards. Is that OK?
+    // It is not clear whether we should call peerConnectSucceeded/Failed()
+    // based on TCP results, SSL results, or both. And the code is probably not
+    // consistent in this aspect across tunnelling and forwarding modules.
+    if (CachePeer *p = serverConnection()->getPeer())
+        peerConnectFailed(p);
+
+    Must(callback != NULL);
+    CbDialer *dialer = dynamic_cast<CbDialer*>(callback->getDialer());
+    Must(dialer);
+    dialer->answer().error = error;
+
+    callBack();
+    // Our job is done. The callabck recepient will probably close the failed
+    // peer connection and try another peer or go direct (if possible). We
+    // can close the connection ourselves (our error notification would reach
+    // the recepient before the fd-closure notification), but we would rather
+    // minimize the number of fd-closure notifications and let the recepient
+    // manage the TCP state of the connection.
+}
+
+void
+Ssl::PeerConnector::callBack()
+{
+    AsyncCall::Pointer cb = callback;
+    // Do this now so that if we throw below, swanSong() assert that we _tried_
+    // to call back holds.
+    callback = NULL; // this should make done() true
+
+    // remove close handler
+    comm_remove_close_handler(serverConnection()->fd, closeHandler);
+
+    CbDialer *dialer = dynamic_cast<CbDialer*>(cb->getDialer());
+    Must(dialer);
+    dialer->answer().conn = serverConnection();
+    ScheduleCallHere(cb);
+}
+
+
+void
+Ssl::PeerConnector::swanSong()
+{
+    // XXX: unregister fd-closure monitoring and CommSetSelect interest, if any
+    AsyncJob::swanSong();
+    assert(!callback); // paranoid: we have not left the caller waiting
+}
+
+const char *
+Ssl::PeerConnector::status() const
+{
+    static MemBuf buf;
+    buf.reset();
+
+    // TODO: redesign AsyncJob::status() API to avoid this
+    // id and stop reason reporting duplication.
+    buf.append(" [", 2);
+    if (stopReason != NULL) {
+        buf.Printf("Stopped, reason:");
+        buf.Printf("%s",stopReason);
+    }
+    if (serverConn != NULL)
+        buf.Printf(" FD %d", serverConn->fd);
+    buf.Printf(" %s%u]", id.Prefix, id.value);
+    buf.terminate();
+
+    return buf.content();
+}
+
+/* PeerConnectorAnswer */
+
+Ssl::PeerConnectorAnswer::~PeerConnectorAnswer()
+{
+    delete error.get();
+}
+
+std::ostream &
+operator <<(std::ostream &os, const Ssl::PeerConnectorAnswer &answer)
+{
+    return os << answer.conn << ", " << answer.error;
+}
