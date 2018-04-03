        request->header.putStr(Http::HOST, useHost.c_str());
    request->flags.intercepted = ((clientConnection->flags & COMM_INTERCEPTION) != 0);
    request->flags.interceptTproxy = ((clientConnection->flags & COMM_TRANSPARENT) != 0 );
    request->sources |= ((switchedToHttps() || port->transport.protocol == AnyP::PROTO_HTTPS) ? HttpMsg::srcHttps : HttpMsg::srcHttp);
#if USE_AUTH
    if (getAuth())
        request->auth_user_request = getAuth();
