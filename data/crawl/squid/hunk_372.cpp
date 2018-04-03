  */
 
 #include "squid.h"
-#include "client_side.h"
+#include "client_side_request.h"
+#include "http/Stream.h"
 
 #define STUB_API "client_side.cc"
 #include "tests/STUB.h"
 
-//ClientSocketContext::ClientSocketContext(const ConnectionPointer&, ClientHttpRequest*) STUB
-//ClientSocketContext::~ClientSocketContext() STUB
-bool ClientSocketContext::startOfOutput() const STUB_RETVAL(false)
-void ClientSocketContext::writeComplete(size_t size) STUB
-void ClientSocketContext::pullData() STUB
-int64_t ClientSocketContext::getNextRangeOffset() const STUB_RETVAL(0)
-bool ClientSocketContext::canPackMoreRanges() const STUB_RETVAL(false)
-clientStream_status_t ClientSocketContext::socketState() STUB_RETVAL(STREAM_NONE)
-void ClientSocketContext::sendBody(HttpReply * rep, StoreIOBuffer bodyData) STUB
-void ClientSocketContext::sendStartOfMessage(HttpReply * rep, StoreIOBuffer bodyData) STUB
-size_t ClientSocketContext::lengthToSend(Range<int64_t> const &available) STUB_RETVAL(0)
-void ClientSocketContext::noteSentBodyBytes(size_t) STUB
-void ClientSocketContext::buildRangeHeader(HttpReply * rep) STUB
-clientStreamNode * ClientSocketContext::getTail() const STUB_RETVAL(NULL)
-clientStreamNode * ClientSocketContext::getClientReplyContext() const STUB_RETVAL(NULL)
-void ClientSocketContext::finished() STUB
-void ClientSocketContext::deferRecipientForLater(clientStreamNode * node, HttpReply * rep, StoreIOBuffer receivedData) STUB
-bool ClientSocketContext::multipartRangeRequest() const STUB_RETVAL(false)
-void ClientSocketContext::registerWithConn() STUB
-void ClientSocketContext::noteIoError(const int xerrno) STUB
-
+#include "client_side.h"
 bool ConnStateData::clientParseRequests() STUB_RETVAL(false)
 void ConnStateData::readNextRequest() STUB
 bool ConnStateData::isOpen() const STUB_RETVAL(false)
 void ConnStateData::kick() STUB
-void ConnStateData::sendControlMsg(HttpControlMsg msg) STUB
+void ConnStateData::sendControlMsg(HttpControlMsg) STUB
 int64_t ConnStateData::mayNeedToReadMoreBody() const STUB_RETVAL(0)
 #if USE_AUTH
-void ConnStateData::setAuth(const Auth::UserRequest::Pointer &aur, const char *cause) STUB
+void ConnStateData::setAuth(const Auth::UserRequest::Pointer &, const char *) STUB
 #endif
 bool ConnStateData::transparent() const STUB_RETVAL(false)
-void ConnStateData::stopReceiving(const char *error) STUB
-void ConnStateData::stopSending(const char *error) STUB
+void ConnStateData::stopReceiving(const char *) STUB
+void ConnStateData::stopSending(const char *) STUB
 void ConnStateData::expectNoForwarding() STUB
 void ConnStateData::noteMoreBodySpaceAvailable(BodyPipe::Pointer) STUB
 void ConnStateData::noteBodyConsumerAborted(BodyPipe::Pointer) STUB
 bool ConnStateData::handleReadData() STUB_RETVAL(false)
 bool ConnStateData::handleRequestBodyData() STUB_RETVAL(false)
-void ConnStateData::pinConnection(const Comm::ConnectionPointer &pinServerConn, HttpRequest *request, CachePeer *peer, bool auth, bool monitor) STUB
-void ConnStateData::unpinConnection(const bool andClose) STUB
-const Comm::ConnectionPointer ConnStateData::validatePinnedConnection(HttpRequest *request, const CachePeer *peer) STUB_RETVAL(NULL)
-void ConnStateData::clientPinnedConnectionClosed(const CommCloseCbParams &io) STUB
-void ConnStateData::connStateClosed(const CommCloseCbParams &io) STUB
-void ConnStateData::requestTimeout(const CommTimeoutCbParams &params) STUB
+void ConnStateData::pinConnection(const Comm::ConnectionPointer &, HttpRequest *, CachePeer *, bool, bool) STUB
+void ConnStateData::unpinConnection(const bool) STUB
+const Comm::ConnectionPointer ConnStateData::validatePinnedConnection(HttpRequest *, const CachePeer *) STUB_RETVAL(NULL)
+void ConnStateData::clientPinnedConnectionClosed(const CommCloseCbParams &) STUB
+void ConnStateData::connStateClosed(const CommCloseCbParams &) STUB
+void ConnStateData::requestTimeout(const CommTimeoutCbParams &) STUB
 void ConnStateData::swanSong() STUB
-void ConnStateData::quitAfterError(HttpRequest *request) STUB
+void ConnStateData::quitAfterError(HttpRequest *) STUB
 #if USE_OPENSSL
-void ConnStateData::httpsPeeked(Comm::ConnectionPointer serverConnection) STUB
+void ConnStateData::httpsPeeked(Comm::ConnectionPointer) STUB
 void ConnStateData::getSslContextStart() STUB
 void ConnStateData::getSslContextDone(Security::ContextPtr, bool) STUB
-void ConnStateData::sslCrtdHandleReplyWrapper(void *data, const Helper::Reply &reply) STUB
-void ConnStateData::sslCrtdHandleReply(const Helper::Reply &reply) STUB
-void ConnStateData::switchToHttps(HttpRequest *request, Ssl::BumpMode bumpServerMode) STUB
-void ConnStateData::buildSslCertGenerationParams(Ssl::CertificateProperties &certProperties) STUB
-bool ConnStateData::serveDelayedError(ClientSocketContext *context) STUB_RETVAL(false)
+void ConnStateData::sslCrtdHandleReplyWrapper(void *, const Helper::Reply &) STUB
+void ConnStateData::sslCrtdHandleReply(const Helper::Reply &) STUB
+void ConnStateData::switchToHttps(HttpRequest *, Ssl::BumpMode) STUB
+void ConnStateData::buildSslCertGenerationParams(Ssl::CertificateProperties &) STUB
+bool ConnStateData::serveDelayedError(Http::Stream *) STUB_RETVAL(false)
 #endif
 
-void setLogUri(ClientHttpRequest * http, char const *uri, bool cleanUrl) STUB
-const char *findTrailingHTTPVersion(const char *uriAndHTTPVersion, const char *end) STUB_RETVAL(NULL)
-int varyEvaluateMatch(StoreEntry * entry, HttpRequest * req) STUB_RETVAL(0)
+void setLogUri(ClientHttpRequest *, char const *, bool) STUB
+const char *findTrailingHTTPVersion(const char *, const char *) STUB_RETVAL(NULL)
+int varyEvaluateMatch(StoreEntry *, HttpRequest *) STUB_RETVAL(0)
 void clientOpenListenSockets(void) STUB
 void clientHttpConnectionsClose(void) STUB
 void httpRequestFree(void *) STUB
+void clientPackRangeHdr(const HttpReply *, const HttpHdrRangeSpec *, String, MemBuf *) STUB
+void clientPackTermBound(String, MemBuf *) STUB
 
