#endif /* USE_OPENSSL */

bool
ConnStateData::initiateTunneledRequest(HttpRequest::Pointer const &cause, Http::MethodType const method, const char *reason, const SBuf &payload)
{
    // fake a CONNECT request to force connState to tunnel
    SBuf connectHost;
    unsigned short connectPort = 0;

    if (pinning.serverConnection != nullptr) {
        static char ip[MAX_IPSTRLEN];
        connectHost.assign(pinning.serverConnection->remote.toStr(ip, sizeof(ip)));
        connectPort = pinning.serverConnection->remote.port();
    } else if (cause && cause->method == Http::METHOD_CONNECT) {
        // We are inside a (not fully established) CONNECT request
        connectHost = cause->url.host();
        connectPort = cause->url.port();
    } else {
        debugs(33, 2, "Not able to compute URL, abort request tunneling for " << reason);
        return false;
    }

    debugs(33, 2, "Request tunneling for " << reason);
    ClientHttpRequest *http = buildFakeRequest(method, connectHost, connectPort, payload);
    HttpRequest::Pointer request = http->request;
    request->flags.forceTunnel = true;
    http->calloutContext = new ClientRequestContext(http);
    http->doCallouts();
    clientProcessRequestFinished(this, request);
    return true;
}

bool
ConnStateData::fakeAConnectRequest(const char *reason, const SBuf &payload)
{
    debugs(33, 2, "fake a CONNECT request to force connState to tunnel for " << reason);

    SBuf connectHost;
    assert(transparent());
    const unsigned short connectPort = clientConnection->local.port();

#if USE_OPENSSL
    if (serverBump() && !serverBump()->clientSni.isEmpty())
        connectHost.assign(serverBump()->clientSni);
    else
#endif
    {
        static char ip[MAX_IPSTRLEN];
        connectHost.assign(clientConnection->local.toStr(ip, sizeof(ip)));
    }

    ClientHttpRequest *http = buildFakeRequest(Http::METHOD_CONNECT, connectHost, connectPort, payload);

    http->calloutContext = new ClientRequestContext(http);
    HttpRequest::Pointer request = http->request;
    http->doCallouts();
    clientProcessRequestFinished(this, request);
    return true;
}

ClientHttpRequest *
ConnStateData::buildFakeRequest(Http::MethodType const method, SBuf &useHost, unsigned short usePort, const SBuf &payload)
{
    ClientHttpRequest *http = new ClientHttpRequest(this);
    Http::Stream *stream = new Http::Stream(clientConnection, http);

    StoreIOBuffer tempBuffer;
    tempBuffer.data = stream->reqbuf;
    tempBuffer.length = HTTP_REQBUF_SZ;

    ClientStreamData newServer = new clientReplyContext(http);
    ClientStreamData newClient = stream;
    clientStreamInit(&http->client_stream, clientGetMoreData, clientReplyDetach,
                     clientReplyStatus, newServer, clientSocketRecipient,
                     clientSocketDetach, newClient, tempBuffer);

    http->uri = SBufToCstring(useHost);
    stream->flags.parsed_ok = 1; // Do we need it?
    stream->mayUseConnection(true);
    
    AsyncCall::Pointer timeoutCall = commCbCall(5, 4, "clientLifetimeTimeout",
                                                CommTimeoutCbPtrFun(clientLifetimeTimeout, stream->http));
    commSetConnTimeout(clientConnection, Config.Timeout.lifetime, timeoutCall);

    stream->registerWithConn();

    // Setup Http::Request object. Maybe should be replaced by a call to (modified)
    // clientProcessRequest
    HttpRequest::Pointer request = new HttpRequest();
    AnyP::ProtocolType proto = (method == Http::METHOD_NONE) ? AnyP::PROTO_AUTHORITY_FORM : AnyP::PROTO_HTTP;
    request->url.setScheme(proto, nullptr);
    request->method = method;
    request->url.host(useHost.c_str());
    request->url.port(usePort);
    http->request = request.getRaw();
    HTTPMSGLOCK(http->request);

    request->clientConnectionManager = this;

    if (proto == AnyP::PROTO_HTTP)
        request->header.putStr(Http::HOST, useHost.c_str());
    request->flags.intercepted = ((clientConnection->flags & COMM_INTERCEPTION) != 0);
    request->flags.interceptTproxy = ((clientConnection->flags & COMM_TRANSPARENT) != 0 );
    request->sources |= ((switchedToHttps() || port->transport.protocol == AnyP::PROTO_HTTPS) ? HttpMsg::srcHttps : HttpMsg::srcHttp);
#if USE_AUTH
    if (getAuth())
        request->auth_user_request = getAuth();
#endif
    request->client_addr = clientConnection->remote;
#if FOLLOW_X_FORWARDED_FOR
    request->indirect_client_addr = clientConnection->remote;
#endif /* FOLLOW_X_FORWARDED_FOR */
    request->my_addr = clientConnection->local;
    request->myportname = port->name;

    inBuf = payload;
    flags.readMore = false;

    setLogUri(http, urlCanonicalClean(request.getRaw()));
    return http;
}

/// check FD after clientHttp[s]ConnectionOpened, adjust HttpSockets as needed
static bool
OpenedHttpSocket(const Comm::ConnectionPointer &c, const Ipc::FdNoteId portType)
