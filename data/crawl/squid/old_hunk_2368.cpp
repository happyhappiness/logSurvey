}

void
AuthUserRequest::addAuthenticationInfoHeader(HttpReply * rep, int accelerated)
{}

void
AuthUserRequest::addAuthenticationInfoTrailer(HttpReply * rep, int accelerated)
{}

void
AuthUserRequest::onConnectionClose(ConnStateData *)
{}

const char *
AuthUserRequest::connLastHeader()
{
    fatal("AuthUserRequest::connLastHeader should always be overridden by conn based auth schemes");
    return NULL;
}

