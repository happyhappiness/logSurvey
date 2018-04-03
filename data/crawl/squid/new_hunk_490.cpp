        pullData();
        break;

    case STREAM_COMPLETE: {
        debugs(33, 5, conn << " Stream complete, keepalive is " << http->request->flags.proxyKeepalive);
        ConnStateData *c = http->getConn();
        if (!http->request->flags.proxyKeepalive)
            clientConnection->close();
        finished();
        c->kick();
        }
        return;

    case STREAM_UNPLANNED_COMPLETE:
