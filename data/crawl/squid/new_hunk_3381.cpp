
        /* AYJ: 2009-12-27: bit bumpy. new ListenStateData(...) should be doing all the Comm:: stuff ... */

        const int openFlags = COMM_NONBLOCKING |
            (s->spoof_client_ip ? COMM_TRANSPARENT : 0);

        AsyncCall::Pointer callback = asyncCall(33,2,
            "clientHttpConnectionOpened",
            ListeningStartedDialer(&clientHttpConnectionOpened, s));
        Ipc::StartListening(SOCK_STREAM, IPPROTO_TCP, s->s, openFlags,
            Ipc::fdnHttpSocket, callback);

        HttpSockets[NHttpSockets++] = -1; // set in clientHttpConnectionOpened
    }

#if USE_SSL
    if (bumpCount && !Config.accessList.ssl_bump)
        debugs(33, 1, "WARNING: http_port(s) with SslBump found, but no " <<
               std::endl << "\tssl_bump ACL configured. No requests will be " <<
               "bumped.");
#endif
}

static void
clientHttpConnectionOpened(int fd, int, http_port_list *s)
{
    if (fd < 0) {
        Must(NHttpSockets > 0); // we tried to open some
        --NHttpSockets; // there will be fewer sockets than planned
        Must(HttpSockets[NHttpSockets] < 0); // no extra fds received

        if (!NHttpSockets) // we could not open any listen sockets at all
            fatal("Cannot open HTTP Port");

        return;
    }

    Must(s);

        AsyncCall::Pointer call = commCbCall(5,5, "SomeCommAcceptHandler(httpAccept)",
                                             CommAcceptCbPtrFun(httpAccept, s));
