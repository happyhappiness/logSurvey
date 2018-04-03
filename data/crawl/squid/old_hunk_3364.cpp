    storeAppendPrintf(output, "Next Garbage Collection in %d seconds.\n", static_cast<int32_t>(last_discard + Config.authenticateGCInterval - squid_curtime));

    /* cache dump column titles */
    storeAppendPrintf(output, "\n%-15s %-9s %-9s %s\n",
                      "Type",
                      "Check TTL",
                      "Cache TTL",
                      "Username");
    storeAppendPrintf(output, "--------------- --------- --------- ------------------------------\n");

    hash_first(proxy_auth_username_cache);
    while ((usernamehash = ((AuthUserHashPointer *) hash_next(proxy_auth_username_cache)))) {
        AuthUser::Pointer auth_user = usernamehash->user();

        storeAppendPrintf(output, "%-15s %-9d %-9d %s\n",
                          AuthType_str[auth_user->auth_type],
                          auth_user->ttl(),
                          static_cast<int32_t>(auth_user->expiretime - squid_curtime + Config.authenticateTTL),
                          auth_user->username()
