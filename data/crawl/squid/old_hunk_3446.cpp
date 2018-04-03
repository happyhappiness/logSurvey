
    if (totallen != length) {
        fprintf(stderr,
                "Squid_rad_auth: Received invalid reply length from server (want %d/ got %d)\n",
                totallen, length);
        return -1;
    }
