void ConnStateData::setAuth(const Auth::UserRequest::Pointer &aur, const char *cause) STUB
#endif
bool ConnStateData::transparent() const STUB_RETVAL(false)
bool ConnStateData::reading() const STUB_RETVAL(false)
void ConnStateData::stopReading() STUB
void ConnStateData::stopReceiving(const char *error) STUB
void ConnStateData::stopSending(const char *error) STUB
void ConnStateData::expectNoForwarding() STUB
