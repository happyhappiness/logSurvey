    if (hlp->childs.concurrency) {
        srv->requestsIndex.insert(helper_server::RequestIndex::value_type(reqId, it));
        assert(srv->requestsIndex.size() == srv->requests.size());
        srv->wqueue->Printf("%" PRIu64 " %s", reqId, r->buf);
    } else
        srv->wqueue->append(r->buf, strlen(r->buf));

