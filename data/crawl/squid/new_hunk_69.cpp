    storeAppendPrintf(dumpEntry, "---- ------ ---- -------- -------- --------------------- ------------------------------\n");
#endif

    for (int i = 0; i < Squid_MaxFD; ++i) {
        fde::Table[i].dumpStats(*dumpEntry, i);
    }
}

char const *
fde::remoteAddr() const
{
    static char buf[MAX_IPSTRLEN];
    *buf = 0;

    if (type == FD_SOCKET) {
        if (*ipaddr)
            snprintf(buf, MAX_IPSTRLEN, "%s:%u", ipaddr, remote_port);
        else
            local_addr.toUrl(buf,MAX_IPSTRLEN); // toHostStr does not include port.
    }

    return buf;
}

