    cfg->service_failure_limit = 0;
}

#if USE_SSL
static void parse_sslproxy_cert_adapt(sslproxy_cert_adapt **cert_adapt)
{
    char *al;
    sslproxy_cert_adapt *ca = (sslproxy_cert_adapt *) xcalloc(1, sizeof(sslproxy_cert_adapt));
    if ((al = strtok(NULL, w_space)) == NULL) {
        self_destruct();
        return;
    }
    
    const char *param;
    if ( char *s = strchr(al, '{')) {
        *s = '\0'; // terminate the al string
        s++;
        param = s;
        s = strchr(s, '}');
        if (!s) {
            self_destruct();
            return;
        }
        *s = '\0';
    }
    else
        param = NULL;

    if (strcmp(al, Ssl::CertAdaptAlgorithmStr[Ssl::algSetValidAfter]) == 0) {
        ca->alg = Ssl::algSetValidAfter;
        ca->param = strdup("on");
    }
    else if (strcmp(al, Ssl::CertAdaptAlgorithmStr[Ssl::algSetValidBefore]) == 0) {
        ca->alg = Ssl::algSetValidBefore;
        ca->param = strdup("on");
    }
    else if (strcmp(al, Ssl::CertAdaptAlgorithmStr[Ssl::algSetCommonName]) == 0) {
        ca->alg = Ssl::algSetCommonName;
        if (param) {
            ca->param = strdup(param);
        }
    } else {
        debugs(3, DBG_CRITICAL, "FATAL: sslproxy_cert_adapt: unknown cert adaptation algorithm: " << al);
        self_destruct();
        return;
    }

    aclParseAclList(LegacyParser, &ca->aclList);

    while(*cert_adapt)
        cert_adapt = &(*cert_adapt)->next;

    *cert_adapt = ca;
}

static void dump_sslproxy_cert_adapt(StoreEntry *entry, const char *name, sslproxy_cert_adapt *cert_adapt)
{
    for (sslproxy_cert_adapt *ca = cert_adapt; ca != NULL; ca = ca->next) {
        storeAppendPrintf(entry, "%s ", name);
        storeAppendPrintf(entry, "%s{%s} ", Ssl::sslCertAdaptAlgoritm(ca->alg), ca->param);
        if (ca->aclList)
            dump_acl_list(entry, ca->aclList);
        storeAppendPrintf(entry, "\n");
    }
}

static void free_sslproxy_cert_adapt(sslproxy_cert_adapt **cert_adapt)
{
    while(*cert_adapt) {
        sslproxy_cert_adapt *ca = *cert_adapt;
        *cert_adapt = ca->next;
        safe_free(ca->param);

        if (ca->aclList)
            aclDestroyAclList(&ca->aclList);

        safe_free(ca);
    }
}
#endif

#endif
