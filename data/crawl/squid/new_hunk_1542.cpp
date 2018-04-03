    return clientdbEstablished(Filled(checklist)->src_addr, 0) > limit ? 1 : 0;
}

SBufList
ACLMaxConnection::dump() const
{
    SBufList sl;
    if (!limit)
        return sl;

    SBuf s;
    s.Printf("%d", limit);
    sl.push_back(s);
    return sl;
}

void
