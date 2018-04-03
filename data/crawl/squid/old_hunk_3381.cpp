
        /* AYJ: 2009-12-27: bit bumpy. new ListenStateData(...) should be doing all the Comm:: stuff ... */

        enter_suid();

        if (s->spoof_client_ip) {
            fd = comm_open_listener(SOCK_STREAM, IPPROTO_TCP, s->s, (COMM_NONBLOCKING|COMM_TRANSPARENT), "HTTP Socket");
        } else {
            fd = comm_open_listener(SOCK_STREAM, IPPROTO_TCP, s->s, COMM_NONBLOCKING, "HTTP Socket");
        }

        leave_suid();

        if (fd < 0)
            continue;

        AsyncCall::Pointer call = commCbCall(5,5, "SomeCommAcceptHandler(httpAccept)",
                                             CommAcceptCbPtrFun(httpAccept, s));
