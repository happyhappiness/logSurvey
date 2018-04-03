        }
    }

    if (debug)
        fprintf(stderr, "%s| %s: INFO: Starting version %s\n", LogTime(), PROGRAM,
                SQUID_KERB_AUTH_VERSION);
    if (service_principal && strcasecmp(service_principal, "GSS_C_NO_NAME")) {
        service.value = service_principal;
        service.length = strlen((char *) service.value);
