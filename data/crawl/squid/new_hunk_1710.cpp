
    if (!staticSslContext) {
        char buf[128];
        fatalf("%s_port %s initialization error", protocol,  s.toUrl(buf, sizeof(buf)));
    }
}
#endif