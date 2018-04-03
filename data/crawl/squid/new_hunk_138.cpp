        certs.emplace_back(t);
    } else if (strncmp(token, "key=", 4) == 0) {
        if (certs.empty() || certs.back().certFile.isEmpty()) {
            fatal("cert= option must be set before key= is used.");
            return;
        }
        KeyData &t = certs.back();