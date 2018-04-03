    }
}

static void parse_sslproxy_ssl_bump(acl_access **ssl_bump)
{
    char *bm;
    if ((bm = strtok(NULL, w_space)) == NULL) {
        self_destruct();
        return;
    }

    acl_access *A = new acl_access;
    A->allow = allow_t(ACCESS_ALLOWED);

    if (strcmp(bm, Ssl::BumpModeStr[Ssl::bumpClientFirst]) == 0)
        A->allow.kind = Ssl::bumpClientFirst;
    else if (strcmp(bm, Ssl::BumpModeStr[Ssl::bumpServerFirst]) == 0)
        A->allow.kind = Ssl::bumpServerFirst;
    else if (strcmp(bm, Ssl::BumpModeStr[Ssl::bumpNone]) == 0)
        A->allow.kind = Ssl::bumpNone;
    else if (strcmp(bm, "allow") == 0 || strcmp(bm, "deny") == 0) {
        // allow/deny rule sets may rely on an implicit "negate the last one"
        // rule which we cannot support due to multuple "allow" keywords
        debugs(3, DBG_CRITICAL, "FATAL: ssl_bump allow/deny rule(s) " <<
               "must be CAREFULLY converted to specify bump mode(s).");
        self_destruct();
        return;
    } else {
        debugs(3, DBG_CRITICAL, "FATAL: unknown ssl_bump mode: " << bm);
        self_destruct();
        return;
    }

    aclParseAclList(LegacyParser, &A->aclList);

    acl_access *B, **T;
    for (B = *ssl_bump, T = ssl_bump; B; T = &B->next, B = B->next);
    *T = A;
}

static void dump_sslproxy_ssl_bump(StoreEntry *entry, const char *name, acl_access *ssl_bump)
{
    acl_access *sb;
    for (sb = ssl_bump; sb != NULL; sb = sb->next) {
        storeAppendPrintf(entry, "%s ", name);
        storeAppendPrintf(entry, "%s ", Ssl::bumpMode(sb->allow.kind));
        if (sb->aclList)
            dump_acl_list(entry, sb->aclList);
        storeAppendPrintf(entry, "\n");
    }
}

static void free_sslproxy_ssl_bump(acl_access **ssl_bump)
{
    free_acl_access(ssl_bump);
}

#endif
