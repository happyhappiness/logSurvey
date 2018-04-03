        fatalf("Unknown TLS option '%s'", err);
    }
    parsedOptions = Security::ParsedOptions(op, [](gnutls_priority_t p) {
        gnutls_priority_deinit(p);
    });
#endif
}
