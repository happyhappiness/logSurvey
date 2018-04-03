Auth::UserRequest::UserRequest() STUB
Auth::UserRequest::~UserRequest() STUB
void Auth::UserRequest::setDenyMessage(char const *) STUB
char const * Auth::UserRequest::getDenyMessage() STUB_RETVAL("stub")
char const * Auth::UserRequest::denyMessage(char const * const) STUB_RETVAL("stub")
void authenticateAuthUserRequestRemoveIp(Auth::UserRequest::Pointer, Ip::Address const &) STUB
void authenticateAuthUserRequestClearIp(Auth::UserRequest::Pointer) STUB
int authenticateAuthUserRequestIPCount(Auth::UserRequest::Pointer) STUB_RETVAL(0)