void
Ftp::Server::writeCustomReply(const int code, const char *msg, const HttpReply *reply)
{
    debugs(33, 7, HERE << code << ' ' << msg);
    assert(99 < code && code < 1000);

    const bool sendDetails = reply != NULL &&
