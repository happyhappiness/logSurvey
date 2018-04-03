    const char *user_auth = FormatName(al->cache.authuser);
    const char *user_ident = FormatName(al->cache.rfc931);

    logfilePrintf(logfile, "%s %s %s [%s] \"%s %s %s/%d.%d\" %d %"PRId64" %s%s:%s%s",
                  al->cache.caddr.NtoA(clientip,MAX_IPSTRLEN),
                  user_ident ? user_ident : dash_str,
                  user_auth ? user_auth : dash_str,
                  Time::FormatHttpd(squid_curtime),
                  al->_private.method_str,
                  al->url,
                  AnyP::ProtocolType_str[al->http.version.protocol],
                  al->http.version.major, al->http.version.minor,
                  al->http.code,
                  al->cache.replySize,
