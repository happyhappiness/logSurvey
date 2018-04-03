	fatal_dump("peerCountMcastPeersStart: non-multicast peer");
    p->mcast.flags &= ~PEER_COUNT_EVENT_PENDING;
    sprintf(url, "http://%s/", inet_ntoa(p->in_addr.sin_addr));
    fake = storeCreateEntry(url, 0, METHOD_GET);
    psstate->request = requestLink(urlParse(METHOD_GET, url));
    psstate->entry = fake;
    psstate->callback = NULL;
