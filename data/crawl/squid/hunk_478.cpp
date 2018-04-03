 void ClientSocketContext::buildRangeHeader(HttpReply * rep) STUB
 clientStreamNode * ClientSocketContext::getTail() const STUB_RETVAL(NULL)
 clientStreamNode * ClientSocketContext::getClientReplyContext() const STUB_RETVAL(NULL)
-void ClientSocketContext::connIsFinished() STUB
-void ClientSocketContext::removeFromConnectionList(ConnStateData * conn) STUB
+void ClientSocketContext::finished() STUB
 void ClientSocketContext::deferRecipientForLater(clientStreamNode * node, HttpReply * rep, StoreIOBuffer receivedData) STUB
 bool ClientSocketContext::multipartRangeRequest() const STUB_RETVAL(false)
 void ClientSocketContext::registerWithConn() STUB
 void ClientSocketContext::noteIoError(const int xerrno) STUB
-void ClientSocketContext::writeControlMsg(HttpControlMsg &msg) STUB
 
-void ConnStateData::readSomeData() STUB
-bool ConnStateData::areAllContextsForThisConnection() const STUB_RETVAL(false)
-void ConnStateData::freeAllContexts() STUB
-void ConnStateData::notifyAllContexts(const int xerrno) STUB
 bool ConnStateData::clientParseRequests() STUB_RETVAL(false)
 void ConnStateData::readNextRequest() STUB
-void ConnStateData::addContextToQueue(ClientSocketContext * context) STUB
-int ConnStateData::getConcurrentRequestCount() const STUB_RETVAL(0)
 bool ConnStateData::isOpen() const STUB_RETVAL(false)
+void ConnStateData::kick() STUB
 void ConnStateData::sendControlMsg(HttpControlMsg msg) STUB
 int64_t ConnStateData::mayNeedToReadMoreBody() const STUB_RETVAL(0)
 #if USE_AUTH
 void ConnStateData::setAuth(const Auth::UserRequest::Pointer &aur, const char *cause) STUB
 #endif
 bool ConnStateData::transparent() const STUB_RETVAL(false)
-bool ConnStateData::reading() const STUB_RETVAL(false)
-void ConnStateData::stopReading() STUB
 void ConnStateData::stopReceiving(const char *error) STUB
 void ConnStateData::stopSending(const char *error) STUB
 void ConnStateData::expectNoForwarding() STUB
