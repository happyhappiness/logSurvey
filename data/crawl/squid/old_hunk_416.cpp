    if (pipeline.empty())
        return;

    pipeline.front()->writeComplete(size);
}

// TODO: make this only need size parameter, ConnStateData handles the rest
void
Http::StreamContext::writeComplete(size_t size)
{
    const StoreEntry *entry = http->storeEntry();
    debugs(33, 5, clientConnection << ", sz " << size <<
           ", off " << (http->out.size + size) << ", len " <<
           (entry ? entry->objectLen() : 0));

    http->out.size += size;
    clientUpdateSocketStats(http->logType, size);

    if (clientHttpRequestStatus(clientConnection->fd, http)) {
        initiateClose("failure or true request status");
        /* Do we leak here ? */
        return;
    }

    switch (socketState()) {

    case STREAM_NONE:
        pullData();
        break;

    case STREAM_COMPLETE: {
        debugs(33, 5, clientConnection << " Stream complete, keepalive is " << http->request->flags.proxyKeepalive);
        ConnStateData *c = http->getConn();
        if (!http->request->flags.proxyKeepalive)
            clientConnection->close();
        finished();
        c->kick();
    }
    return;

    case STREAM_UNPLANNED_COMPLETE:
        initiateClose("STREAM_UNPLANNED_COMPLETE");
        return;

    case STREAM_FAILED:
        initiateClose("STREAM_FAILED");
        return;

    default:
        fatal("Hit unreachable code in Http::StreamContext::writeComplete\n");
    }
}

Http::StreamContext *