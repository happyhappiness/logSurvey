    if (s->sslContextSessionId)
        storeAppendPrintf(e, " sslcontext=%s", s->sslContextSessionId);

    if (!s->generateHostCertificates)
        storeAppendPrintf(e, " generate-host-certificates=off");

    if (s->dynamicCertMemCacheSize != 4*1024*1024) // 4MB default
        storeAppendPrintf(e, "dynamic_cert_mem_cache_size=%" PRIuSIZE "%s\n", s->dynamicCertMemCacheSize, B_BYTES_STR);
#endif
}
