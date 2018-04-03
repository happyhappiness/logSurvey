
    if (totallen != length) {
        fprintf(stderr,
                "basic_radius_auth: Received invalid reply length from server (want %d/ got %d)\n",
                totallen, length);
        return -1;
    }
